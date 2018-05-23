#include "gui.h"

GUI::GUI(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1200,600);

    //katakanaImage = new QLabel(this);
    //katakanaImage->setGeometry(0,0, 100, 100);

    /*scribbleArea = new ScribbleArea(this);
    scribbleArea->setGeometry(0,0, 100, 100);
    scribbleArea1 = new ScribbleArea(this);
    scribbleArea1->setGeometry(100,100, 100, 100);*/

    fontId = QFontDatabase::addApplicationFont(
                "C:/Qt/Projects/Nauka_japonskiego/Data/rounded-mgenplus-20140828/rounded-mgenplus-1c-light.ttf");
    fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    rounded_mgenplus_light = QFont(fontFamily, 30);

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
    showQuestion();
}
void GUI::randomQuestion()
{
    loader.randQuest(question);
    showQuestion();
}

void GUI::showQuestion()
{
    switch(question.questionAlphabet)
    {
    case 0:
        englishWordLabel->setText(question.englishWord);
        break;
    case 1:
        romajiWordLabel->setText(question.romajiWord);
        break;
    case 2:
        katakanaWordLabel->setText(question.katakanaWord);
        break;
    case 3:
        hiraganaWordLabel->setText(question.hiraganaWord);
        break;
    case 4:
        kanjiWordLabel->setText(question.kanjiWord);
        break;
    }
}


void GUI::showAnswers()
{
    englishWordLabel->setText(question.englishWord);
    romajiWordLabel->setText(question.romajiWord);
    katakanaWordLabel->setText(question.katakanaWord);
    hiraganaWordLabel->setText(question.hiraganaWord);
    kanjiWordLabel->setText(question.kanjiWord);
}

void GUI::clear()
{
    englishWordLabel->setText("");
    romajiWordLabel->setText("");
    katakanaWordLabel->setText("");
    hiraganaWordLabel->setText("");
    kanjiWordLabel->setText("");
}


void GUI::arrangeGUI()
{

    QGridLayout *layout = new QGridLayout;

    headline = new QLabel("Japanese learning v0.1");
    headline->setStyleSheet("font: 40pt;");

    nextButton = new QPushButton("Next question");
    randomButton = new QPushButton("Random question");
    nextButton->setFixedHeight(50);
    randomButton->setFixedHeight(50);


    layout->addWidget(headline, 0, 0, 3, -1);

    layout->addWidget(arrangeEnglishGroup(), 4, 0, 10, 5);
    layout->addWidget(arrangeRomajiGroup(), 4, 5, 10, 5);
    layout->addWidget(arrangeKatakanaGroup(), 4, 10, 10, 5);
    layout->addWidget(arrangeHiraganaGroup(), 4, 15, 10, 5);
    layout->addWidget(arrangeKanjiGroup(), 4, 20, 10, 5);

    layout->addWidget(nextButton, 15, 8, 2, 4);
    layout->addWidget(randomButton, 15, 13, 2, 4);

    setLayout(layout);
}


QGroupBox * GUI::arrangeEnglishGroup()
{
    QVBoxLayout *vbox = new QVBoxLayout;
    QGroupBox *question = new QGroupBox("Word");
    QVBoxLayout *questionLayout = new QVBoxLayout;

    englishGroup = new QGroupBox("English");

    englishWordLabel = new QLabel("");
    englishWordLabel->setStyleSheet("font: 20pt;");
    englishAnswerLabel = new QLabel("Your answer:");
    englishAnswer = new QLineEdit();

    questionLayout->addWidget(englishWordLabel);
    question->setLayout(questionLayout);

    vbox->addWidget(question);
    vbox->addWidget(englishAnswerLabel);
    vbox->addWidget(englishAnswer);
    vbox->addWidget(new QLabel(""));

    vbox->setStretch(0, 6);
    vbox->setStretch(3, 2);
    //vbox->addStretch(1);

    englishGroup->setLayout(vbox);

    return englishGroup;
}

QGroupBox * GUI::arrangeRomajiGroup()
{
    romajiGroup = new QGroupBox("Romaji");

    QVBoxLayout *vbox = new QVBoxLayout;
    QGroupBox *question = new QGroupBox("Word");
    QVBoxLayout *questionLayout = new QVBoxLayout;


    romajiWordLabel = new QLabel("");
    romajiWordLabel->setStyleSheet("font: 20pt;");

    romajiAnswerLabel = new QLabel("Your answer:");
    romajiAnswer = new QLineEdit();

    questionLayout->addWidget(romajiWordLabel);
    question->setLayout(questionLayout);

    vbox->addWidget(question);
    vbox->addWidget(romajiAnswerLabel);
    vbox->addWidget(romajiAnswer);
    vbox->addWidget(new QLabel(""));

    vbox->setStretch(0, 6);
    vbox->setStretch(3, 2);

    romajiGroup->setLayout(vbox);


    return romajiGroup;
}

QGroupBox * GUI::arrangeKatakanaGroup()
{
    katakanaGroup = new QGroupBox("Katakana");

    QVBoxLayout *vbox = new QVBoxLayout;
    QGroupBox *question = new QGroupBox("Word");
    QGroupBox *scribble = new QGroupBox("Your answer");
    QVBoxLayout *questionLayout = new QVBoxLayout;
    QVBoxLayout *scribbleLayout = new QVBoxLayout;


    katakanaWordLabel = new QLabel("");
    katakanaWordLabel->setFixedSize(100,100);
    katakanaWordLabel->setFont(rounded_mgenplus_light);

    katakanaScribble = new ScribbleArea();
    katakanaScribble->setFixedSize(200,100);

    questionLayout->addWidget(katakanaWordLabel);
    question->setLayout(questionLayout);

    scribbleLayout->addWidget(katakanaScribble);
    scribble->setLayout(scribbleLayout);

    vbox->addWidget(question);
    vbox->addWidget(scribble);

    vbox->addStretch(1);

    katakanaGroup->setLayout(vbox);


    return katakanaGroup;
}

QGroupBox * GUI::arrangeHiraganaGroup()
{
    hiraganaGroup = new QGroupBox("Hiragana");

    QVBoxLayout *vbox = new QVBoxLayout;
    QGroupBox *question = new QGroupBox("Word");
    QGroupBox *scribble = new QGroupBox("Your answer");
    QVBoxLayout *questionLayout = new QVBoxLayout;
    QVBoxLayout *scribbleLayout = new QVBoxLayout;


    hiraganaWordLabel = new QLabel("");
    hiraganaWordLabel->setFixedSize(100,100);
    hiraganaWordLabel->setFont(rounded_mgenplus_light);

    hiraganaScribble = new ScribbleArea();
    hiraganaScribble->setFixedSize(200,100);

    questionLayout->addWidget(hiraganaWordLabel);
    question->setLayout(questionLayout);

    scribbleLayout->addWidget(hiraganaScribble);
    scribble->setLayout(scribbleLayout);

    vbox->addWidget(question);
    vbox->addWidget(scribble);

    vbox->addStretch(1);

    hiraganaGroup->setLayout(vbox);

    return hiraganaGroup;
}

QGroupBox * GUI::arrangeKanjiGroup()
{
    kanjiGroup = new QGroupBox("Kanji");

    QVBoxLayout *vbox = new QVBoxLayout;
    QGroupBox *question = new QGroupBox("Word");
    QGroupBox *scribble = new QGroupBox("Your answer");
    QVBoxLayout *questionLayout = new QVBoxLayout;
    QVBoxLayout *scribbleLayout = new QVBoxLayout;


    kanjiWordLabel = new QLabel("");
    kanjiWordLabel->setFixedSize(100,100);
    kanjiWordLabel->setFont(rounded_mgenplus_light);

    kanjiScribble = new ScribbleArea();
    kanjiScribble->setFixedSize(200,100);

    questionLayout->addWidget(kanjiWordLabel);
    question->setLayout(questionLayout);

    scribbleLayout->addWidget(kanjiScribble);
    scribble->setLayout(scribbleLayout);

    vbox->addWidget(question);
    vbox->addWidget(scribble);

    vbox->addStretch(1);

    kanjiGroup->setLayout(vbox);

    return kanjiGroup;
}
