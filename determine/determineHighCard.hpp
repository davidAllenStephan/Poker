#ifndef determineHighCard_H
#define determineHighCard_H
#include <string>
#include "../convert/convertCardBinaryToInt.hpp"

using namespace std;

int determineHighCard(string arr[])
{
    int highest = 0;
    string output;
    for (int i = 0; i < 2; i++)
    {
        string card = arr[i];
        int cardInt = convertCardBinaryToInt(card.substr(6));
        if (cardInt > highest)
        {
            highest = cardInt;
            output = card;
        }
    }
    return highest;
}
#endif