#include "Die.hpp"
#include "utility.hpp"

using namespace std;

Die::Die(int sides)
{
    numOfSides = sides;
}

int Die::rollDice()
{
    return randomNum(numOfSides, 1);
}
Die::~Die()
{
}
