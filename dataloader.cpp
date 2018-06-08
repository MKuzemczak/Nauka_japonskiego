#include <limits>

#include "dataloader.h"

using namespace  std;

DataLoader::DataLoader()
{
    questionAmount = 0;
    currentQuestion = 0;

    rangeStart = 0;

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
    doneQuestionsSet.setMaxSize(questionAmount * 0.85);
    allQuestionsSet = NumberSet(0, questionAmount - 1);
    toRandomQuestionsSet = allQuestionsSet;

    qDebug() << allQuestionsSet;

    rangeEnd = questionAmount-1;
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

    while(q.questionAlphabet == lastQuestionAlphabet)
        q.questionAlphabet = random.uniform(0, ALPHA_AMOUNT-1);


    for(int i = 0; i < ALPHA_AMOUNT; i++)
    {
        swapSpaces(s[i]);
        swapNewLines(s[i]);
        q.words[i] = s[i];
    }

    return true;
}

bool DataLoader::randQuest(Question & q)
{
    int rand = random.uniform(0, ((int)toRandomQuestionsSet.size()) - 1);

    qDebug() << "number: " << rand;

    currentQuestion = toRandomQuestionsSet.at(rand);

    return questNumber(currentQuestion, q);
}

bool DataLoader::nextQuest(Question & q)
{
    if(currentQuestion >= rangeEnd || currentQuestion < rangeStart)
        currentQuestion = rangeStart;
    else
        currentQuestion++;

    return questNumber(currentQuestion, q);
}

bool DataLoader::prevQuest(Question & q)
{
    if(currentQuestion <= rangeStart || currentQuestion > rangeEnd)
        currentQuestion = rangeEnd;
    else
        currentQuestion--;

    return questNumber(currentQuestion, q);
}

void swapSpaces(QString & s)
{
    for(QChar & c : s)
        if(c == '_')
            c = ' ';
}

void swapNewLines(QString & s)
{
    for(QChar & c : s)
        if(c == '/')
            c = '\n';
}

void DataLoader::addCurrentToVector()
{
    if(!doneQuestionsSet.contains(currentQuestion))
        doneQuestionsSet.add(currentQuestion);

    toRandomQuestionsSet = allQuestionsSet - doneQuestionsSet;

    qDebug() << toRandomQuestionsSet;
}

void DataLoader::setRange(int start, int end)
{
    rangeStart = start;
    rangeEnd = end;

    allQuestionsSet = NumberSet(start, end);
    toRandomQuestionsSet = allQuestionsSet - toRandomQuestionsSet;

    if(allQuestionsSet.size() < 10)
        doneQuestionsSet.setMaxSize(allQuestionsSet.size() * 0.5);
    else
        doneQuestionsSet.setMaxSize(allQuestionsSet.size() * 0.85);
}

