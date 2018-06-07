#ifndef NUMBERSET_H
#define NUMBERSET_H

#include <QDebug>
#include <QString>
#include <vector>

class NumberSet : public std::vector<int>
{
    int maxSize;

public:
    NumberSet();
    NumberSet(int begin, int end);

    void add(int number);
    void setMaxSize(const int size);
    const NumberSet operator - (const NumberSet & ns);
};

#endif // NUMBERSET_H
