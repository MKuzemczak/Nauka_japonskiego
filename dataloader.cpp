#include <limits>

#include "dataloader.h"

using namespace  std;

DataLoader::DataLoader()
{
    questionAmount = 0;
    currentQuestion = 0;

    imageExtension = ".jpg";
}

void DataLoader::scanPath()
{
    QFile wordsFile(dataPath + "words.txt");


    if(!wordsFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", wordsFile.errorString());
    }


    QTextStream in(&wordsFile);
    int line = 0;

    while(!in.atEnd())
    {
        in.readLine();
        line++;
    }

    questionAmount = line;
}

bool DataLoader::questNumber(int number, Question & q)
{
    if(number > questionAmount || number < 0)
        return false;

    QFile wordsFile(dataPath + "words.txt");


    if(!wordsFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", wordsFile.errorString());
        return false;
    }


    QTextStream in(&wordsFile);
    int line = 0;
    QString s[5];

    while(!in.atEnd())
    {
        if(line == number)
        {
            for(int i = 0; i < 5; i++)
                in >> s[i];
        }
        else
            in.readLine();
        line++;
    }

    int lastQuestionAlphabet = q.questionAlphabet;

    srand ( time(NULL) );
    q.questionAlphabet = rand() % 5;
    while(q.questionAlphabet == lastQuestionAlphabet || s[q.questionAlphabet][0] == '-')
        q.questionAlphabet = rand() % 5;

    q.englishWord = s[0];
    q.romajiWord = s[1];
    q.katakanaWord = s[2];
    q.hiraganaWord = s[3];
    q.kanjiWord = s[4];

    return true;
}

bool DataLoader::randQuest(Question & q)
{
    int lastQuestion = currentQuestion;
    srand ( time(NULL) );
    currentQuestion = rand() % questionAmount;
    while(currentQuestion == lastQuestion)
        currentQuestion = rand() % questionAmount;

    qDebug() << "current: " << currentQuestion;
    return questNumber(currentQuestion, q);
}

bool DataLoader::nextQuest(Question & q)
{
    if(currentQuestion == questionAmount - 1)
        currentQuestion = 0;
    else
        currentQuestion++;

    return questNumber(currentQuestion, q);
}



std::ifstream& GotoLine(std::ifstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < (int)num; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}
