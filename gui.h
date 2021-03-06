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
#include <QDir>
#include <QRegExpValidator>
#include <unistd.h>


#include "dataloader.h"
#include "scribblearea.h"
#include "answercounter.h"
#include "alphabetamount.h"
#include "lineedit.h"



class GUI : public QWidget
{
    Q_OBJECT

    QLabel *headline,
           *wordLabels[ALPHA_AMOUNT],
           *questRangeLineEditLabel,
           *questAmountLabel;

    ScribbleArea *scribbles[JAP_ALPH_AMOUNT];

    QLineEdit *latinAnswers[LAT_ALPH_AMOUNT];

    QGroupBox *radioGroup;

    QPushButton *nextButton,
                *previousButton,
                *randomButton,
                *checkButton,
                *okButton,
                *setQuestRange;

    QButtonGroup *correctAnswersAmountButtonGroup,
                 *questionModesButtonGroup;
    int uncheckHelper;

    QCheckBox *onlyEnglishQuestionMode,
              *onlyKanjiQuestionMode,
              *autoRandomMode;

    DataLoader loader;
    bool okPressed;

    Question question;

    AnswerCounter *answerCounter;

    LineEdit *questRangeLineEdit;
    QValidator *validator;
    int rans, rane;

    //////////////////// font
    int fontId;
    QString fontFamily;
    QFont rounded_mgenplus_light;

    void arrangeGUI();
    QGroupBox * arrangeRadioGroup();

    QGroupBox * arrangeLatinGroup(QLabel * (*wordLabel),
                                  QLineEdit * (*answer),
                                  QString name);

    QGroupBox * arrangeJapaneseGroup(QLabel * (*wordLabel),
                                     ScribbleArea* (*scribbleAnswer),
                                     QString name);



public:
    explicit GUI(QWidget *parent = nullptr);

    void showQuestion();


protected:
    void keyPressEvent(QKeyEvent *e);

signals:

public slots:
    void nextQuestion();
    void previousQuestion();
    void randomQuestion();
    void showAnswers();
    void correctAnswersAmountOkPressed();
    void clear();
    void modeButtonsUncheckStart(int id);
    void modeButtonsUncheckEnd(int id);
    void changeQuestRange();
    void questRangeLineEditFocusOut();
};

#endif // GUI_H
