#include "gui.h"


GUI::GUI(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1250,600);


    fontId = QFontDatabase::addApplicationFont(QDir::currentPath() +
                "/Data/rounded-mgenplus-20140828/rounded-mgenplus-1c-light.ttf");
    fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    rounded_mgenplus_light = QFont(fontFamily, 30);

    loader.setDataPath(QDir::currentPath() + "/Data/");
    loader.scanPath();

    arrangeGUI();

}

void GUI::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_W && !(e->isAutoRepeat()))
    {
    }
}


void GUI::nextQuestion()
{
    loader.nextQuest(question);
    if(onlyEnglishQuestionMode->isChecked())
    {
        while(question.words[ENG][0] == '-')
            loader.nextQuest(question);

        question.questionAlphabet = ENG;
    }
    clear();
    showQuestion();
}

void GUI::previousQuestion()
{
    loader.prevQuest(question);
    if(onlyEnglishQuestionMode->isChecked())
    {
        while(question.words[ENG][0] == '-')
            loader.prevQuest(question);

        question.questionAlphabet = ENG;
    }
    clear();
    showQuestion();
}

void GUI::randomQuestion()
{
    loader.randQuest(question);
    if(onlyEnglishQuestionMode->isChecked())
    {
        while(question.words[ENG][0] == '-')
            loader.randQuest(question);

        question.questionAlphabet = ENG;
    }
    clear();
    showQuestion();
    qDebug()<< "alphabet: " << question.questionAlphabet;
}

void GUI::showQuestion()
{
    wordLabels[question.questionAlphabet]->
            setText(question.words[question.questionAlphabet]);
}


void GUI::showAnswers()
{
    for(int i = 0; i < ALPHA_AMOUNT; i++)
        wordLabels[i]->setText(question.words[i]);

    nextButton->hide();
    randomButton->hide();
    checkButton->hide();

    radioGroup->show();
}

void GUI::clear()
{
    for(int i = 0; i < ALPHA_AMOUNT; i++)
        wordLabels[i]->setText("");

    for(int i = 0; i < JAP_ALPH_AMOUNT; i++)
        scribbles[i]->clearImage();

    for(int i = 0; i < LAT_ALPH_AMOUNT; i++)
        latinAnswers[i]->setText("");
}

void GUI::correctAnswersAmountOkPressed()
{
    answerCounter->increaseCorrectAnswers((double)correctAnswersAmountButtonGroup->checkedId()/4);

    nextButton->show();
    randomButton->show();
    checkButton->show();

    radioGroup->hide();
}

void GUI::arrangeGUI()
{

    QGridLayout *layout = new QGridLayout;

    headline = new QLabel("Learning japenese v0.1");
    headline->setStyleSheet("font: 40pt;");

    nextButton = new QPushButton("Next question");
    previousButton = new QPushButton("Previous question");
    randomButton = new QPushButton("Random question");
    checkButton = new QPushButton("Show answers");
    nextButton->setFixedHeight(50);
    previousButton->setFixedHeight(50);
    randomButton->setFixedHeight(50);
    checkButton->setFixedHeight(50);

    connect(nextButton, SIGNAL(pressed()), this, SLOT(nextQuestion()));
    connect(previousButton, SIGNAL(pressed()), this, SLOT(previousQuestion()));
    connect(randomButton, SIGNAL(pressed()), this, SLOT(randomQuestion()));
    connect(checkButton, SIGNAL(pressed()), this, SLOT(showAnswers()));

    answerCounter = new AnswerCounter;

    layout->addWidget(headline, 0, 0, 3, 20);
    layout->addWidget(answerCounter, 0, 21, 3, -1);

    layout->addWidget(arrangeLatinGroup(&wordLabels[ENG],
                                        &latinAnswers[LAT_ENG],
                                        "English"),
                      4, 0, 10, 5);
    layout->addWidget(arrangeLatinGroup(&wordLabels[ROMAJI],
                                        &latinAnswers[LAT_ROMAJI],
                                        "Romaji"),
                      4, 5, 10, 5);
    layout->addWidget(arrangeJapaneseGroup(&wordLabels[KATA],
                                           &scribbles[JAP_KATA],
                                           "Katakana"),
                      4, 10, 10, 5);
    layout->addWidget(arrangeJapaneseGroup(&wordLabels[HIRA],
                                           &scribbles[JAP_HIRA],
                                           "Hiragana"),
                      4, 15, 10, 5);
    layout->addWidget(arrangeJapaneseGroup(&wordLabels[KANJI],
                                           &scribbles[JAP_KANJI],
                                           "Kanji"),
                      4, 20, 10, 5);

    layout->addWidget(previousButton, 15, 5, 2, 4);
    layout->addWidget(nextButton, 15, 9, 2, 4);
    layout->addWidget(randomButton, 15, 13, 2, 4);
    layout->addWidget(checkButton, 15, 17, 2, 4);

    layout->addWidget(arrangeRadioGroup(), 15, 7, -1, 12);
    radioGroup->hide();

    setLayout(layout);

    onlyEnglishQuestionMode = new QCheckBox("Only english questions mode", this);
    onlyEnglishQuestionMode->setChecked(false);
    onlyEnglishQuestionMode->setFixedWidth(400);
    onlyEnglishQuestionMode->move(20, 10);
}



QGroupBox * GUI::arrangeRadioGroup()
{
    radioGroup = new QGroupBox("How many correct answers?");
    correctAnswersAmountButtonGroup = new QButtonGroup;

    QRadioButton *a[5];
    QHBoxLayout * radioLayout = new QHBoxLayout;


    for(int i = 0; i < 5; i++)
    {
        a[i] = new QRadioButton(QString::number(i));
        correctAnswersAmountButtonGroup->addButton(a[i]);
        correctAnswersAmountButtonGroup->setId(a[i], i);
        radioLayout->addWidget(a[i]);
    }
    a[4]->setChecked(true);

    okButton = new QPushButton("OK");
    okButton->setFixedSize(100,50);
    connect(okButton, SIGNAL(pressed()), this, SLOT(correctAnswersAmountOkPressed()));

    radioLayout->addWidget(okButton);

    radioGroup->setLayout(radioLayout);

    return radioGroup;
}

QGroupBox * GUI::arrangeLatinGroup(QLabel * (*wordLabel),
                                   QLineEdit * (*answer), QString name)
{
    QGroupBox *group = new QGroupBox(name);

    QVBoxLayout *vbox = new QVBoxLayout;
    QGroupBox *question = new QGroupBox("Word");
    QVBoxLayout *questionLayout = new QVBoxLayout;


    *wordLabel = new QLabel("");
    (*wordLabel)->setFixedSize(200,100);
    (*wordLabel)->setStyleSheet("font: 20pt;");

    QLabel * answerLabel = new QLabel("Your answer");
    *answer = new QLineEdit();

    questionLayout->addWidget(*wordLabel);
    question->setLayout(questionLayout);

    vbox->addWidget(question);
    vbox->addWidget(answerLabel);
    vbox->addWidget(*answer);
    vbox->addWidget(new QLabel(""));

    vbox->addStretch(1);

    group->setLayout(vbox);


    return group;
}
QGroupBox * GUI::arrangeJapaneseGroup(QLabel * (*wordLabel),
                                      ScribbleArea* (*scribbleAnswer), QString name)
{
    QGroupBox * group = new QGroupBox(name);

    QVBoxLayout *vbox = new QVBoxLayout;
    QGroupBox *question = new QGroupBox("Word");
    QGroupBox *scribble = new QGroupBox("Your answer");
    QVBoxLayout *questionLayout = new QVBoxLayout;
    QVBoxLayout *scribbleLayout = new QVBoxLayout;


    (*wordLabel) = new QLabel("");
    (*wordLabel)->setFixedSize(200,100);
    (*wordLabel)->setFont(rounded_mgenplus_light);

    (*scribbleAnswer) = new ScribbleArea();
    (*scribbleAnswer)->setFixedSize(200,100);

    questionLayout->addWidget(*wordLabel);
    question->setLayout(questionLayout);

    scribbleLayout->addWidget(*scribbleAnswer);
    scribble->setLayout(scribbleLayout);

    vbox->addWidget(question);
    vbox->addWidget(scribble);

    vbox->addStretch(1);

    group->setLayout(vbox);

    return group;
}
