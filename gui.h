#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QKeyEvent>
#include <QPixmap>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFont>
#include <QFontDatabase>
#include <QDebug>
#include <QCheckBox>

#include "dataloader.h"
#include "scribblearea.h"

class GUI : public QWidget
{
    Q_OBJECT

    QLabel *headline,
           *englishWordLabel,
           *romajiWordLabel,
           *katakanaWordLabel,
           *hiraganaWordLabel,
           *kanjiWordLabel;

    ScribbleArea *katakanaScribble,
                 *hiraganaScribble,
                 *kanjiScribble;

    QLineEdit *englishAnswer,
              *romajiAnswer;

    QLabel *englishAnswerLabel,
           *romajiAnswerLabel;

    QGroupBox *englishGroup,
              *romajiGroup,
              *katakanaGroup,
              *hiraganaGroup,
              *kanjiGroup;

    QPushButton *nextButton,
                *randomButton;

    QCheckBox *onlyEnglishQuestionMode;

    DataLoader loader;

    Question question;

    //////////////////// font
    int fontId;
    QString fontFamily;
    QFont rounded_mgenplus_light;

    void arrangeGUI();
    QGroupBox * arrangeEnglishGroup();
    QGroupBox * arrangeRomajiGroup();
    QGroupBox * arrangeKatakanaGroup();
    QGroupBox * arrangeHiraganaGroup();
    QGroupBox * arrangeKanjiGroup();



public:
    explicit GUI(QWidget *parent = nullptr);

    void showQuestion();
    void showAnswers();

protected:
    void keyPressEvent(QKeyEvent *e);

signals:

public slots:
    void nextQuestion();
    void randomQuestion();
    void clear();
};

#endif // GUI_H
