/*********************************************************************
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This is the implementation file for the Die class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Die.hpp"
#include "utility.hpp"


/*********************************************************************
** Description: Constructor that sets the assigns the data member
** numOfSides to the passed in int.
*********************************************************************/
Die::Die(int sides)
{
    numOfSides = sides;
}

/*********************************************************************
** Description: This function will call the randomNum function, passing
** in the numOfSides data member, and then add one to the result to
** represent the valid number range (lowest of 1).
*********************************************************************/
int Die::rollDice()
{
    return (randomNum(numOfSides)) + 1;
}

/*********************************************************************
** Description: Destructor that does nothing.
*********************************************************************/
Die::~Die()
{
}
