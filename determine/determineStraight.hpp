
#ifndef determineStraight_H
#define determineStraight_H
#include <string>
#include <iostream>
#include <algorithm>
#include "../convert/convertCardBinaryToInt.hpp"
using namespace std;

int determineStraight(string arr[], string pile[], int size)
{
    int highest = 0;
    int sortedCombined[7];
    for (int i = 0; i < 2; i++)
    {
        string card = arr[i];
        int cardSuitInt = convertCardBinaryToInt(card.substr(6));
        sortedCombined[i] = cardSuitInt;
    }
    for (int i = 0; i < 5; i++)
    {
        string card = pile[i];
        int cardSuitInt = convertCardBinaryToInt(card.substr(6));
        sortedCombined[i + 2] = cardSuitInt;
    }

    sort(begin(sortedCombined), end(sortedCombined));

    for (int i = 0; i < 7; i++)
    {
        if (sortedCombined[i] == sortedCombined[i + 1] - 1 && sortedCombined[i + 1] == sortedCombined[i + 2] - 1 && sortedCombined[i + 2] == sortedCombined[i + 3] - 1 && sortedCombined[i + 3] == sortedCombined[i + 4] - 1)
        {
            highest = 100;
        }
    }

    return highest;
}
#endif
