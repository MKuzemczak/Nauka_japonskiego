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
#include <time.h>
#include <random>

#include "randutils.hpp"
#include "alphabetamount.h"

//thread_local std::mt19937 gen{std::random_device{}()};

/*template<typename T>
T random(T min, T max) {
    return std::uniform_int_distribution<T>{min, max}(gen);
}*/

typedef struct question {
    QString words[ALPHA_AMOUNT];

    int questionAlphabet;

} Question;

class DataLoader
{
    int questionAmount,
        currentQuestion;

    QString dataPath,
            imageExtension;

    randutils::mt19937_rng random;


public:
    DataLoader();

    void setDataPath(const QString & path) { dataPath = path; }
    void scanPath();
    bool questNumber(int number, Question & q);
    bool randQuest(Question & q);
    bool nextQuest(Question & q);
    bool prevQuest(Question & q);

};

std::ifstream& GotoLine(std::ifstream& file, unsigned int num);
#endif // DATALOADER_H
