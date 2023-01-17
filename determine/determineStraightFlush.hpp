
#ifndef determineStraightFlush_H
#define determineStraightFlush_H
#include <string>
#include <iostream>
#include <algorithm>
#include "../convert/convertCardBinaryToInt.hpp"
using namespace std;

int determineStraightFlush(string arr[], string pile[], int size)
{
    int highest = 0;
    int sortedCombinedRank[7];
    int sortedCombinedSuit[7];
    for (int i = 0; i < 2; i++)
    {
        string card = arr[i];
        int cardRankInt = convertCardBinaryToInt(card.substr(6));
        int cardSuitInt = convertCardBinaryToInt(card.substr(4, 2));
        sortedCombinedRank[i] = cardRankInt;
        sortedCombinedSuit[i] = cardSuitInt;
    }
    for (int i = 0; i < 5; i++)
    {
        string card = pile[i];
        int cardRankInt = convertCardBinaryToInt(card.substr(6));
        int cardSuitInt = convertCardBinaryToInt(card.substr(4, 2));
        sortedCombinedRank[i + 2] = cardRankInt;
        sortedCombinedSuit[i + 2] = cardSuitInt;
    }

    // sort(begin(sortedCombinedRank), end(sortedCombinedRank));
    // sort(begin(sortedCombinedSuit), end(sortedCombinedSuit));

    for (int i = 0; i < 7; i++)
    {
        if (sortedCombinedSuit[i] == sortedCombinedSuit[i + 1] and sortedCombinedSuit[i + 1] == sortedCombinedSuit[i + 2] and sortedCombinedSuit[i + 2] == sortedCombinedSuit[i + 3] and sortedCombinedSuit[i + 3] == sortedCombinedSuit[i + 4])
        {
            if (sortedCombinedRank[i] == sortedCombinedRank[i + 1] - 1 and sortedCombinedRank[i + 1] - 1 == sortedCombinedRank[i + 2] - 2 and sortedCombinedRank[i + 2] - 2 == sortedCombinedRank[i + 3] - 3 and sortedCombinedRank[i + 3] - 3 == sortedCombinedRank[i + 4] - 4)
            {
                return 100;
            }
        }
    }

    return highest;
}
#endif
