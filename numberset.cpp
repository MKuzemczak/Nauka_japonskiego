#include "numberset.h"

NumberSet::NumberSet()
{
    maxSize = 1000000;
}


NumberSet::NumberSet(int begin, int end)
{
    maxSize = 1000000;

    NumberSet n;

    for(int i = begin; i <= end; i++)
        n.add(i);

    *this = n;
}

void NumberSet::add(int number)
{
    push_back(number);

    if(size() > maxSize)
        erase(begin());
}

void NumberSet::setMaxSize(const int size)
{
    maxSize = size;
    while((int)this->size() > maxSize)
        erase(begin());
}

const NumberSet NumberSet::operator - (const NumberSet & ns)
{
    NumberSet ret;


    for(int i = 0; i < (int)size(); i++)
    {
        ret.push_back(at(i));

        for(int j = 0; j < (int)ns.size(); j++)
            if(ret.back() == ns.at(j))
                ret.erase(--ret.end());
    }

    return ret;
}

bool NumberSet::contains(int n)
{
    for(int i : *this)
        if(n == i)
            return true;
    return false;
}
