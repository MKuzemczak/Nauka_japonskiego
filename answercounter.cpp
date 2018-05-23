#include "answercounter.h"

AnswerCounter::AnswerCounter(QWidget *parent)
    : QLabel(parent)
{
    correctAnswers = 0;
    answersTotally = 0;
    ratio = 0;
    setText(QString("%1").arg(ratio, 0, 'g', 2) + "%");

    setStyleSheet("font: 40pt;");
}


void AnswerCounter::increaseCorrectAnswers()
{
    correctAnswers += 1;
    answersTotally += 1;
    updateRatio();
}

void AnswerCounter::increaseAnswers()
{
    answersTotally += 1;
    updateRatio();
}

void AnswerCounter::updateRatio()
{
    ratio = correctAnswers/answersTotally;
    setText(QString("%1").arg(ratio, 0, 'g', 2));
}
