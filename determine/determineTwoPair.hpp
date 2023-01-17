
#ifndef determineTwoPair_H
#define determineTwoPair_H
#include <string>
#include <iostream>
#include <algorithm>
#include "../convert/convertCardBinaryToInt.hpp"
using namespace std;

int determineTwoPair(string arr[], string pile[], int size)
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

    int count = 0;

    for (int i = 0; i < 7; i++)
    {
        if (sortedCombined[i] == sortedCombined[i + 1])
        {
            if (sortedCombined[i] * 2 != highest || highest == 0)
            {
                highest += sortedCombined[i] * 2;
                count += 1;
            }
        }
    }

    if (count < 2)
    {
        highest = 0;
    }

    return highest;
}
#endif
