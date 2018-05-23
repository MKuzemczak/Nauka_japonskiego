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
#include <QButtonGroup>
#include <QRadioButton>

#include "dataloader.h"
#include "scribblearea.h"
#include "answercounter.h"

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
              *kanjiGroup,
              *radioGroup;

    QPushButton *nextButton,
                *randomButton,
                *checkButton,
                *okButton;

    QButtonGroup *correctAnswersAmountButtonGroup;

    QCheckBox *onlyEnglishQuestionMode;

    DataLoader loader;

    Question question;

    AnswerCounter *answerCounter;

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
    QGroupBox * arrangeRadioGroup();



public:
    explicit GUI(QWidget *parent = nullptr);

    void showQuestion();


protected:
    void keyPressEvent(QKeyEvent *e);

signals:

public slots:
    void nextQuestion();
    void randomQuestion();
    void showAnswers();
    void correctAnswersAmountOkPressed();
    void clear();
};

#endif // GUI_H
