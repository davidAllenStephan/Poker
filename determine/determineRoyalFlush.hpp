
#ifndef determineRoyalFlush_H
#define determineRoyalFlush_H
#include <string>
#include <iostream>
#include <algorithm>
#include <iostream>
#include "../convert/convertCardBinaryToInt.hpp"
using namespace std;

int determineRoyalFlush(string arr[], string pile[], int size)
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

    int foundAce = 0;
    int foundTen = 0;
    int foundJack = 0;
    int foundQueen = 0;
    int foundKing = 0;
    for (int i = 0; i < 7; i++)
    {
        if (sortedCombinedRank[i] == 14)
        {
            foundAce = 1;
        }
        if (sortedCombinedRank[i] == 10)
        {
            foundTen = 1;
        }
        if (sortedCombinedRank[i] == 11)
        {
            foundJack = 1;
        }
        if (sortedCombinedRank[i] == 12)
        {
            foundQueen = 1;
        }
        if (sortedCombinedRank[i] == 13)
        {
            foundKing = 1;
        }
    }
    int checkIfRoyal[5];
    for (int i = 0; i < 7; i++)
    {
        if (sortedCombinedSuit[i] == sortedCombinedSuit[i + 1] && sortedCombinedSuit[i + 1] == sortedCombinedSuit[i + 2] && sortedCombinedSuit[i + 2] == sortedCombinedSuit[i + 3] && sortedCombinedSuit[i + 3] == sortedCombinedSuit[i + 4])
        {
            if (sortedCombinedRank[i] == sortedCombinedRank[i + 1] - 1 && sortedCombinedRank[i + 1] - 1 == sortedCombinedRank[i + 2] - 2 && sortedCombinedRank[i + 2] - 2 == sortedCombinedRank[i + 3] - 3 && sortedCombinedRank[i + 3] - 3 == sortedCombinedRank[i + 4] - 4)
            {
                if (sortedCombinedRank[i] == 10 && sortedCombinedRank[i + 1] == 11 && sortedCombinedRank[i + 2] == 12 && sortedCombinedRank[i + 3] == 13 && sortedCombinedRank[i + 4] == 14)
                {
                    return 100;
                }
            }
        }
    }

    return highest;
}
#endif
