#include "gui.h"

GUI::GUI(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1200,400);

    katakanaImage = new QLabel(this);
    katakanaImage->setGeometry(0,0, 100, 100);

    /*scribbleArea = new ScribbleArea(this);
    scribbleArea->setGeometry(0,0, 100, 100);
    scribbleArea1 = new ScribbleArea(this);
    scribbleArea1->setGeometry(100,100, 100, 100);*/

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
        katakanaImage->setPixmap(question.katakanaPix.
                                 scaled(katakanaImage->width(),
                                        katakanaImage->height(),
                                        Qt::KeepAspectRatio));
        break;
    case 3:
        hiraganaImage->setPixmap(question.hiraganaPix.
                                 scaled(hiraganaImage->width(),
                                        hiraganaImage->height(),
                                        Qt::KeepAspectRatio));
        break;
    case 4:
        kanjiImage->setPixmap(question.kanjiPix.
                                 scaled(kanjiImage->width(),
                                        kanjiImage->height(),
                                        Qt::KeepAspectRatio));
        break;
    }
}


void GUI::showAnswers()
{

}

void GUI::clear()
{

}


void GUI::arrangeGUI()
{
    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(arrangeEnglishGroup());
    layout->addWidget(arrangeRomajiGroup());
    layout->addWidget(arrangeKatakanaGroup());
    layout->addWidget(arrangeHiraganaGroup());
    layout->addWidget(arrangeKanjiGroup());

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
    //vbox->addStretch(1);

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


    katakanaImage = new QLabel();
    katakanaImage->setFixedSize(100,100);

    katakanaScribble = new ScribbleArea();
    katakanaScribble->setFixedSize(200,100);

    questionLayout->addWidget(katakanaImage);
    question->setLayout(questionLayout);

    scribbleLayout->addWidget(katakanaScribble);
    scribble->setLayout(scribbleLayout);

    vbox->addWidget(question);
    vbox->addWidget(scribble);

    //vbox->setStretch(0, 6);
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


    hiraganaImage = new QLabel();
    hiraganaImage->setFixedSize(100,100);

    hiraganaScribble = new ScribbleArea();
    hiraganaScribble->setFixedSize(200,100);

    questionLayout->addWidget(hiraganaImage);
    question->setLayout(questionLayout);

    scribbleLayout->addWidget(hiraganaScribble);
    scribble->setLayout(scribbleLayout);

    vbox->addWidget(question);
    vbox->addWidget(scribble);

    //vbox->setStretch(0, 6);
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


    kanjiImage = new QLabel();
    kanjiImage->setFixedSize(100,100);

    kanjiScribble = new ScribbleArea();
    kanjiScribble->setFixedSize(200,100);

    questionLayout->addWidget(kanjiImage);
    question->setLayout(questionLayout);

    scribbleLayout->addWidget(kanjiScribble);
    scribble->setLayout(scribbleLayout);

    vbox->addWidget(question);
    vbox->addWidget(scribble);

    //vbox->setStretch(0, 6);
    vbox->addStretch(1);

    kanjiGroup->setLayout(vbox);

    return kanjiGroup;
}
