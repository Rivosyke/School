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
Space::Space(Space* tempUp, Space* tempRight, Space* tempDown, Space* tempLeft)
{
    Up = tempUp;
    Right = tempRight;
    Down = tempDown;
    Left = tempLeft;
}

/*********************************************************************
** Description: Destructor that does nothing.
*********************************************************************/
Space::~Space()
{}

/*********************************************************************
** Description: Virtual function that will display the description
** of the space - needs to be implemented by derived classes
*********************************************************************/
void Space::displayDesc()
{
}
/*********************************************************************
** Description: Virtual function that will initiate the derived class'
** special action(s - needs to be implemented by derived classes
*********************************************************************/
void Space::specialAction()
{}




