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
    ifstream questAmountFile(dataPath.toUtf8().toStdString() + "amount.txt");

    if(questAmountFile.is_open())
    {
        questAmountFile >> questionAmount;

        if(questionAmount == 0)
            cout << "Warning! No questions.\n";
    }
    else
        cout << "Unable to open amount.txt\n";
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

    while(!in.atEnd())
    {
        if(line == number)
        {
            in >> q.englishWord;
            in >> q.romajiWord;
            in >> q.katakanaWord;
            in >> q.hiraganaWord;
            in >> q.kanjiWord;
        }
        else
            in.readLine();
        line++;
    }

    q.questionAlphabet = rand() % 5;

    return true;
}

bool DataLoader::randQuest(Question & q)
{
    currentQuestion = rand() % questionAmount;

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
