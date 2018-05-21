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

    ifstream englishFile(dataPath.toUtf8().toStdString() + "english.txt");
    ifstream romajiFile(dataPath.toUtf8().toStdString() + "romaji.txt");

    if(!englishFile.is_open() || !romajiFile.is_open())
        return false;

    GotoLine(englishFile, (unsigned int)number);
    GotoLine(romajiFile, (unsigned int)number);

    string s;

    englishFile >> s;

    q.englishWord = QString::fromStdString(s);

    s = "";

    romajiFile >> s;

    q.romajiWord = QString::fromStdString(s);

    q.katakanaPix.load(dataPath + "katakana_" + QString::number(number) + imageExtension);
    q.hiraganaPix.load(dataPath + "hiragana_" + QString::number(number) + imageExtension);
    q.kanjiPix.load(dataPath + "kanji_" + QString::number(number) + imageExtension);

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
