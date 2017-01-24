#include "LoadedDie.hpp"
#include "utility.hpp"
#include "Die.hpp"

using namespace std;

int LoadedDie::rollDice()
{
    int tempResult = randomNum(3, 1);
    
    switch (tempResult)
    {
        case 1:
            return randomNum(numOfSides/2, 1);
        case 2:
            return (randomNum(numOfSides/2, 1) + (numOfSides/2));
        case 3:
            return (randomNum(numOfSides/2, 1) + (numOfSides/2));
        default:
            return 0;
    };
}

LoadedDie::LoadedDie(int sides) : Die(sides)
{
}

