/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the implementation file for the Space class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Space.hpp"

/*********************************************************************
** Description: Constructor that sets the passed in values to their 
** appropriate data member.
*********************************************************************/
Space::Space(Space* tempUp, 
             Space* tempRight, 
             Space* tempDown, 
             Space* tempLeft, 
             string tempName)
{
    Up = tempUp;
    Right = tempRight;
    Down = tempDown;
    Left = tempLeft;
    name = tempName;
}

/*********************************************************************
** Description: Destructor that does nothing.
*********************************************************************/
Space::~Space()
{}

/*********************************************************************
** Description: Method that returns the name of the space
*********************************************************************/
string Space::getName()
{
    return name;
}





