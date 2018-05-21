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

    QString dataPath;


public:
    DataLoader();

    void setDataPath(const QString & path) { dataPath = path; }
    void scanPath();
    void randQuest(Question & q);
    void nextQuest(Question & q);

};

#endif // DATALOADER_H
