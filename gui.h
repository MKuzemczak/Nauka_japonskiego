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

#include "dataloader.h"
#include "scribblearea.h"

class GUI : public QWidget
{
    Q_OBJECT

    QLabel *headline,
           *englishWordLabel,
           *romajiWordLabel,
           *katakanaImage,
           *hiraganaImage,
           *kanjiImage;

    ScribbleArea *katakanaScribble,
                 *hiraganaScribble,
                 *kanjiScribble;

    QLineEdit *englishAnswer,
              *romajiAnswer;

    QLabel *englishAnswerLabel,
           *romajiAnswerLabel,
           *katakanaScribbleLabel,
           *hiraganaScribbleLabel,
           *kanjiScribbleLabel;

    QPixmap *katakanaPix,
            *hiraganaPix,
            *kanjiPix;

    QGroupBox *englishGroup,
              *romajiGroup,
              *katakanaGroup,
              *hiraganaGroup,
              *kanjiGroup;



    DataLoader loader;

    Question question;

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
