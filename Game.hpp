#ifndef Game_H
#define Game_H
#include "getRand.hpp"
#include "./determine/determineHighCard.hpp"
#include "./determine/determineOnePair.hpp"
#include "./determine/determineTriplet.hpp"
#include "./determine/determineTwoPair.hpp"
#include "./determine/determineQuad.hpp"
#include "./determine/determineFlush.hpp"
#include "./determine/determineStraight.hpp"
#include "./determine/determineStraightFlush.hpp"
#include "./determine/determineRoyalFlush.hpp"
#include <string>

using namespace std;

string deckBinaryTemp[4][13] = {
    {"0000000010", "0000000011", "0000000100", "0000000101", "0000000110", "0000000111", "0000001000", "0000001001", "0000001010", "0000001011", "0000001100", "0000001101", "0000001110"},
    {"0000010010", "0000010011", "0000010100", "0000010101", "0000010110", "0000010111", "0000011000", "0000011001", "0000011010", "0000011011", "0000011100", "0000011101", "0000011110"},
    {"0000100010", "0000100011", "0000100100", "0000100101", "0000100110", "0000100111", "0000101000", "0000101001", "0000101010", "0000101011", "0000101100", "0000101101", "0000101110"},
    {"0000110010", "0000110011", "0000110100", "0000110101", "0000110110", "0000110111", "0000111000", "0000111001", "0000111010", "0000111011", "0000111100", "0000111101", "0000111110"},
};
string ESC = "\x1B";
string playerColors[8] = {"97m", "30;47m", "1;91m", "1;92m", "1;93m", "1;94m", "1;95m", "1;96m"};

class Game
{
public:
    string deckBinary[4][13];
    int playerCount;

    // constructor
    Game(int playerCount)
    {
        this->playerCount = playerCount;
    }

    // conversion
    string convertPlayerIntToBinary(int num)
    {
        string binary = bitset<4>(num).to_string();
        return binary;
    }

    // misc
    string getRandomCard(int player)
    {
        string playerBinary = convertPlayerIntToBinary(player);
        int rankRand = getRand(12);
        int suitRand = getRand(3);
        string card = this->deckBinary[suitRand][rankRand];
        if (this->deckBinary[suitRand][rankRand].substr(0, 4) != "0000")
        {
            getRandomCard(player);
        }
        else
        {
            this->deckBinary[suitRand][rankRand] = playerBinary + card.substr(4, 10);
        }

        return card;
    }

    // game progression
    void setDeck()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                deckBinary[i][j] = deckBinaryTemp[i][j];
            }
        }
    }
    void setHands()
    {
        for (int i = 2; i < this->playerCount + 2; i++)
        {
            getRandomCard(i);
            getRandomCard(i);
        }
    }
    void setFlop()
    {
        getRandomCard(1);
        getRandomCard(1);
        getRandomCard(1);
    }
    void setTurn()
    {
        getRandomCard(1);
    }
    void setRiver()
    {
        getRandomCard(1);
    }

    // print
    void printDeck()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                string card = this->deckBinary[i][j];
                string player = card.substr(0, 4);
                int playerInt = stoi(player, 0, 2);
                cout << "\x1B[" << playerColors[playerInt] << card;
                cout << "\x1B[0m";
                cout << " ";
            }
            cout << "\n";
        }
    }

    int runHands()
    {
        int isActive = 0;
        for (int i = 2; i < playerCount + 2; i++)
        {
            int playerHandStrength = determineStrength(i);
            if (playerHandStrength > 0)
            {
                isActive = playerHandStrength;
            }
        }
        return isActive;
    }

    int printHands()
    {
        int isActive = 0;
        for (int i = 2; i < playerCount + 2; i++)
        {
            string playerHandString = findPlayer(i);
            int playerHandStrength = determineStrength(i);
            if (playerHandStrength > 0)
            {
                isActive = 1;
            }
            string playerHand[5];
            cout << "player " << i - 1 << " ";
            cout << playerHandString << " ";
            for (int k = 0; k < (playerHandString.length() / 10); k++)
            {
                playerHand[k] = playerHandString.substr(k * 10, 10);
            }
            cout << "\x1B[" << playerColors[i];
            for (int j = 0; j < 5; j++)
            {
                cout << playerHand[j];

                cout << " ";
            }
            cout << "player strength " << playerHandStrength;
            cout << "\x1B[0m";
            cout << "\n";
        }
        return isActive;
    }

    // strength
    int determineStrength(int player)
    {
        string pileString = findPlayer(1);
        string pile[5];
        string playerHandString = findPlayer(player);
        string playerHand[5];

        int playerHandSize = (playerHandString.length() / 10);
        for (int k = 0; k < playerHandSize; k++)
        {
            playerHand[k] = playerHandString.substr(k * 10, 10);
        }

        int pileSize = (pileString.length() / 10);
        for (int k = 0; k < pileSize; k++)
        {
            pile[k] = pileString.substr(k * 10, 10);
        }

        int highestCard = determineHighCard(playerHand);
        int highestPair = determineOnePair(playerHand, pile, pileSize);
        int highestTriplet = determineTriplet(playerHand, pile, pileSize);
        int highestTwoPair = determineTwoPair(playerHand, pile, pileSize); // about 10% less frequent
        int highestQuad = determineQuad(playerHand, pile, pileSize);
        int highestFlush = determineFlush(playerHand, pile, pileSize);
        int highestStraight = determineStraight(playerHand, pile, pileSize);
        int highestStraightFlush = determineStraightFlush(playerHand, pile, pileSize);
        int highestRoyalFlush = determineRoyalFlush(playerHand, pile, pileSize);

        if (highestRoyalFlush != 0)
        {
            return 1;
        }
        else if (highestStraightFlush != 0)
        {
            return 2;
        }
        else if (highestQuad != 0)
        {
            return 3;
        }
        else if (highestFlush != 0)
        {
            return 4;
        }
        else if (highestStraight != 0)
        {
            return 5;
        }
        else if (highestTriplet != 0)
        {
            return 6;
        }
        else if (highestTwoPair != 0)
        {
            return 7;
        }
        else if (highestPair != 0)
        {
            return 8;
        }
        else if (highestCard != 0)
        {
            return 9;
        }
        return 0;
    }

    // find
    string findPlayer(int player)
    {
        string playerHand;
        string playerBinary = convertPlayerIntToBinary(player);

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                string card = this->deckBinary[i][j];
                string cardPlayer = card.substr(0, 4);
                if (cardPlayer == playerBinary)
                {
                    playerHand += card;
                }
            }
        }
        return playerHand;
    }
};
#endif