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
** Description: This function will implement the "loaded" aspect of 
** the die. It does this by first getting a random number between 
** 0 and 2. It then will get another random number based off the
** previous result. 0 will call randomNum using the bottom half of the
** number range determined by the numOfSides data member. Cases 1 and 2
** will also pass half the num to the randomNum function but they will
** also add that same half to the result of the randomNum call. This 
** equates to being 2/3rds as likely to roll a number in the upper 
** range of probability.
*********************************************************************/
int LoadedDie::rollDice()
{
    int tempResult = randomNum(3);
    
    switch (tempResult)
    {
        case 0:
            // Returns 
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

