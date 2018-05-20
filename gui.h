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

    QLineEdit *englishAnswer,
              *romajiAnswer;

    QPixmap *katakanaPix,
            *hiraganaPix,
            *kanjiPix;

    QGroupBox *englishGroup(),
              *romajiGroup(),
              *katakanaGroup(),
              *hiraganaGroup(),
              *kanjiGroup();

    ScribbleArea *scribbleArea;

public:
    explicit GUI(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *e);

signals:

public slots:
};

#endif // GUI_H
