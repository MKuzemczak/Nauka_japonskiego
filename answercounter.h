#ifndef ANSWERCOUNTER_H
#define ANSWERCOUNTER_H

#include <QLabel>

class AnswerCounter : public QLabel
{
    Q_OBJECT

    double correctAnswers,
           answersTotally,
           ratio;
public:
    AnswerCounter(QWidget *parent = 0);

    void increaseCorrectAnswers(double c);
    void increaseAnswers();
    void updateRatio();
};

#endif // ANSWERCOUNTER_H
