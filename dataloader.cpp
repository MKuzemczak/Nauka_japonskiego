#include "dataloader.h"

using namespace  std;

DataLoader::DataLoader()
{
    questionAmount = 0;
    currentQuestion = 0;
}

void DataLoader::scanPath()
{
    ifstream questAmountFile(dataPath + "amount.txt");

    if(questAmountFile.is_open())
    {
        questAmountFile >> questionAmount;

        if(questionAmount == 0)
            cout << "Warning! No questions.\n";
    }
    else
        cout << "Unable to open amount.txt\n";
}

void DataLoader::randQuest(Question & q)
{
    currentQuestion = rand() % questionAmount;
}

void nextQuest(Question & q);
