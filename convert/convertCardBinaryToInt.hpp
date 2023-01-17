#ifndef convertCardBinaryToInt_H
#define convertCardBinaryToInt_H
#include <string>

int convertCardBinaryToInt(string value)
{
    int output = stoi(value, 0, 2);
    return output;
}

#endif