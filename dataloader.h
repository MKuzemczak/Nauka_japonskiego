#ifndef DATALOADER_H
#define DATALOADER_H

#include <iostream>
#include <fstream>
#include <QString>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QLineEdit>
#include <time.h>
#include <random>
#include <vector>


#include "randutils.hpp"
#include "alphabetamount.h"
#include "numberset.h"


typedef struct question {
    QString words[ALPHA_AMOUNT];

    int questionAlphabet;


} Question;

class DataLoader
{
    int questionAmount,
        currentQuestion,
        rangeStart,
        rangeEnd;

    QString dataPath,
            imageExtension;

    randutils::mt19937_rng random;


    NumberSet doneQuestionsSet,
              toRandomQuestionsSet,
              allQuestionsSet;

public:
    DataLoader();

    void setDataPath(const QString & path) { dataPath = path; }
    void scanPath();
    bool questNumber(int number, Question & q);
    bool randQuest(Question & q);
    bool nextQuest(Question & q);
    bool prevQuest(Question & q);
    void addCurrentToVector();
    void setRange(int start, int end);

    int getRangeStart() { return rangeStart; }
    int getRangeEnd() { return rangeEnd; }
    int getQuestAmount() { return questionAmount; }
};


void swapSpaces(QString & s);
void swapNewLines(QString & s);
#endif // DATALOADER_H
