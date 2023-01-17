#include <string>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <ctime>

#include "Player.hpp"
#include "Game.hpp"

using namespace std;

void init()
{
    srand(time(NULL));
}

int main()
{
    init();

    // int isActive = 0;
    // int count = 0;

    // while (isActive == 0)
    // {
    //     count++;
    //     Game game(1);
    //     game.setDeck();
    //     game.setHands();
    //     game.setFlop();
    //     game.setTurn();
    //     game.setRiver();
    //     isActive = game.runHands();
    //     if (isActive != 0)
    //     {
    //         cout << "\n";
    //         game.printDeck();
    //         game.printHands();
    //         cout << "Total iterations " << count << "\n";
    //     }
    // }

    double highestCard = 0;
    double highestPair = 0;
    double highestTriplet = 0;
    double highestTwoPair = 0;
    double highestQuad = 0;
    double highestFlush = 0;
    double highestStraight = 0;
    double highestStraightFlush = 0;
    double highestRoyalFlush = 0;
    double iterations = 1000000;
    for (int i = 0; i < iterations; i++)
    {
        int isActive = 0;
        Game game(1);
        game.setDeck();
        game.setHands();
        game.setFlop();
        game.setTurn();
        game.setRiver();
        isActive = game.runHands();
        if (isActive == 1)
        {
            highestRoyalFlush++;
        }
        else if (isActive == 2)
        {
            highestStraightFlush++;
        }
        else if (isActive == 3)
        {
            highestQuad++;
        }
        else if (isActive == 4)
        {
            highestFlush++;
        }
        else if (isActive == 5)
        {
            highestStraight++;
        }
        else if (isActive == 6)
        {
            highestTriplet++;
        }
        else if (isActive == 7)
        {
            highestTwoPair++;
        }
        else if (isActive == 8)
        {
            highestPair++;
        }
        else if (isActive == 9)
        {
            highestCard++;
        }
    }

    cout << "Total iterations " << iterations << "\n";

    double highestRoyalFlushPercent = highestRoyalFlush / iterations;
    highestRoyalFlushPercent = highestRoyalFlushPercent * 100;
    cout << "Royal Flush total " << highestRoyalFlush << "\n";
    cout << "Royal Flush percentage " << highestRoyalFlushPercent << "\n";

    double highestStraightFlushPercent = highestStraightFlush / iterations;
    highestStraightFlushPercent = highestStraightFlushPercent * 100;
    cout << "Straight Flush total " << highestStraightFlush << "\n";
    cout << "Straight Flush percentage " << highestStraightFlushPercent << "\n";

    double highestQuadPercent = highestQuad / iterations;
    highestQuadPercent = highestQuadPercent * 100;
    cout << "Quad total " << highestQuad << "\n";
    cout << "Quad percentage " << highestQuadPercent << "\n";

    double highestFlushPercent = highestFlush / iterations;
    highestFlushPercent = highestFlushPercent * 100;
    cout << "Flush total " << highestFlush << "\n";
    cout << "Flush percentage " << highestFlushPercent << "\n";

    double highestStraightPercent = highestStraight / iterations;
    highestStraightPercent = highestStraightPercent * 100;
    cout << "Straight total " << highestStraight << "\n";
    cout << "Straight percentage " << highestStraightPercent << "\n";

    double highestTripletPercent = highestTriplet / iterations;
    highestTripletPercent = highestTripletPercent * 100;
    cout << "Triple total " << highestTriplet << "\n";
    cout << "Triple percentage " << highestTripletPercent << "\n";

    double highestTwoPairPercent = highestTwoPair / iterations;
    highestTwoPairPercent = highestTwoPairPercent * 100;
    cout << "Two Pair total " << highestTwoPair << "\n";
    cout << "Two Pair percentage " << highestTwoPairPercent << "\n";

    double highestPairPercent = highestPair / iterations;
    highestPairPercent = highestPairPercent * 100;
    cout << "Pair total " << highestPair << "\n";
    cout << "Pair percentage " << highestPairPercent << "\n";

    double highestCardPercent = highestCard / iterations;
    highestCardPercent = highestCardPercent * 100;
    cout << "High total " << highestCard << "\n";
    cout << "High percentage " << highestCardPercent << "\n";

    return 0;
}
