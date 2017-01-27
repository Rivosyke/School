/*********************************************************************
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This is the implementation file for the LoadedDie class.
** It contains the function definitions and the constructor.
*********************************************************************/

#include "LoadedDie.hpp"
#include "utility.hpp"
#include "Die.hpp"


/*********************************************************************
** Description: This function will prompt the user to choose an option
** for the speed of the simulation. The options correspond to constant
** ints that represent microseconds. 
*********************************************************************/
int LoadedDie::rollDice()
{
    int tempResult = randomNum(3);
    
    switch (tempResult)
    {
        case 0:
            return randomNum(numOfSides/2) + 1;
        case 1:
            return ((randomNum(numOfSides/2) + (numOfSides/2))) + 1;
        case 2:
            return ((randomNum(numOfSides/2) + (numOfSides/2))) + 1;
        default:
            return 0;
    };
}

/*********************************************************************
** Description: This is the constructor that calls the base class 
** constructor as this class does not need it's own constructor nor
** does it have it's own data members.
*********************************************************************/
LoadedDie::LoadedDie(int sides) : Die(sides)
{
}

