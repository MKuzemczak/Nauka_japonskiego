#ifndef DATALOADER_H
#define DATALOADER_H

#include <iostream>
#include <fstream>
#include <QString>
#include <QPixmap>

typedef struct question {
    QPixmap katakanaPix,
            hiraganaPix,
            kanjiPix;

    QString englishWord,
            romajiWord;

    int questionAlphabet;

} Question;

class DataLoader
{
    int questionAmount,
        currentQuestion;

    QString dataPath,
            imageExtension;


public:
    DataLoader();

    void setDataPath(const QString & path) { dataPath = path; }
    void scanPath();
    bool questNumber(int number, Question & q);
    bool randQuest(Question & q);
    bool nextQuest(Question & q);

};

std::ifstream& GotoLine(std::ifstream& file, unsigned int num);
#endif // DATALOADER_H
