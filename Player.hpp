#include <string>
#include <iostream>

using namespace std;

class Player
{
public:
    string hand[5];

    string getSuitCardBinary(int i)
    {
        string suitCardBinary;
        suitCardBinary = this->hand[i].substr(0, 2);
        return suitCardBinary;
    }

    string getRankCardBinary(int i)
    {
        string rankCardBinary;
        rankCardBinary = this->hand[i].substr(2, 6);
        return rankCardBinary;
    }

    void setHand(string newHand[])
    {
        for (int i = 0; i < 5; i++)
        {
            this->hand[i] = newHand[i];
        }
    }

    int getSuitCardInt(int i)
    {
        string suitCardBinary = this->getSuitCardBinary(i);
        int suitCardInt;
        suitCardInt = stoi(suitCardBinary, 0, 2);
        return suitCardInt;
    }
    int getRankCardInt(int i)
    {
        string rankCardBinary = this->getRankCardBinary(i);
        int rankCardInt;
        rankCardInt = stoi(rankCardBinary, 0, 2);
        return rankCardInt;
    }

    string getSuitCardString(int i)
    {
        string suit;
        int suitCardInt = this->getSuitCardInt(i);
        if (suitCardInt == 0)
        {
            suit = "H";
        }
        else if (suitCardInt == 1)
        {
            suit = "D";
        }
        else if (suitCardInt == 2)
        {
            suit = "S";
        }
        else if (suitCardInt == 3)
        {
            suit = "J";
        }

        return suit;
    }

    string getRankCardString(int i)
    {
        string rank;
        int rankCardInt = this->getRankCardInt(i);
        rank = to_string(rankCardInt);

        if (rankCardInt == 1)
        {
            rank = "A";
        }
        else if (rankCardInt == 11)
        {
            rank = "J";
        }
        else if (rankCardInt == 12)
        {
            rank = "Q";
        }
        else if (rankCardInt == 13)
        {
            rank = "K";
        }

        return rank;
    }

    void printOverview()
    {
        string handString[5];
        cout << "hand binary ";
        printArr(this->hand);
        cout << "\n";

        cout << "hand string ";
        for (int i = 0; i < 5; i++)
        {
            cout << getSuitCardString(i);
            cout << getRankCardString(i);
            cout << " ";
        }
        cout << "\n";

        cout << "suit binary ";
        for (int i = 0; i < 5; i++)
        {
            cout << getSuitCardBinary(i);
            cout << " ";
        }
        cout << "\n";

        cout << "suit string ";
        for (int i = 0; i < 5; i++)
        {
            cout << getSuitCardString(i);
            cout << " ";
        }
        cout << "\n";

        cout << "rank binary ";
        for (int i = 0; i < 5; i++)
        {
            cout << getRankCardBinary(i);
            cout << " ";
        }
        cout << "\n";

        cout << "rank string ";
        for (int i = 0; i < 5; i++)
        {
            cout << getRankCardString(i);
            cout << " ";
        }
        cout << "\n";
    }

    void printArr(string arr[])
    {
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

// 0 - 15 for rank
// 0 - 3 for suit

// 000000
// 00 0000
// Ace -> 0

// A 00 15 > x
// D 01 16 < x < 31
// S 10 32 < x < 47
// J 11 48 < x

// A7