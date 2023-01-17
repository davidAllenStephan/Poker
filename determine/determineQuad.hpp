
#ifndef determineQuad_H
#define determineQuad_H
#include <string>
#include <iostream>
#include <algorithm>
#include "../convert/convertCardBinaryToInt.hpp"
using namespace std;

int determineQuad(string arr[], string pile[], int size)
{
    int highest = 0;
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
        if ((sortedCombined[i] == sortedCombined[i + 1]) && (sortedCombined[i + 2] == sortedCombined[i + 3]))
        {
            if (sortedCombined[i + 1] == sortedCombined[i + 2])
            {
                highest = sortedCombined[i] * 4;
            }
        }
    }

    return highest;
}
#endif
