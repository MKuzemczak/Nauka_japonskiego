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
    QString s[ALPHA_AMOUNT];

    while(!in.atEnd())
    {
        if(line == number)
        {
            for(int i = 0; i < ALPHA_AMOUNT; i++)
                in >> s[i];
        }
        else
            in.readLine();
        line++;
    }

    int lastQuestionAlphabet = q.questionAlphabet;

    q.questionAlphabet = random.uniform(0, ALPHA_AMOUNT-1);

    while(q.questionAlphabet == lastQuestionAlphabet || s[q.questionAlphabet][0] == '-')
        q.questionAlphabet = random.uniform(0, ALPHA_AMOUNT-1);


    for(int i = 0; i < ALPHA_AMOUNT; i++)
        q.words[i] = s[i];

    return true;
}

bool DataLoader::randQuest(Question & q)
{
    int lastQuestion = currentQuestion;

    currentQuestion = random.uniform(0, questionAmount-1);

    while(currentQuestion == lastQuestion)
        currentQuestion = random.uniform(0, questionAmount-1);

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

bool DataLoader::prevQuest(Question & q)
{
    if(currentQuestion == 0)
        currentQuestion = questionAmount - 1;
    else
        currentQuestion--;

    return questNumber(currentQuestion, q);
}
