
#ifndef determinePair_H
#define determinePair_H
#include <string>
#include <iostream>
#include <algorithm>
#include "../convert/convertCardBinaryToInt.hpp"
using namespace std;

int determineOnePair(string arr[], string pile[], int size)
{
    int sortedCombined[7];
    for (int i = 0; i < 2; i++)
    {
        string card = arr[i];
        int cardInt = convertCardBinaryToInt(card.substr(6));
        sortedCombined[i] = cardInt;
    }
    for (int i = 0; i < 5; i++)
    {
        string card = pile[i];
        int cardInt = convertCardBinaryToInt(card.substr(6));
        sortedCombined[i + 2] = cardInt;
    }

    sort(begin(sortedCombined), end(sortedCombined));

    for (int i = 0; i < 7; i++)
    {
        if (sortedCombined[i] == sortedCombined[i + 1])
        {
            return sortedCombined[i] * 2;
        }
    }
    return 0;
}
#endif
