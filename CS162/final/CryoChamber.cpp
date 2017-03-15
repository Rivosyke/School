/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the implementation file for the Vampire class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "CryoChamber.hpp"

/*********************************************************************
** Description: Constructor that will take in pointers to Space objects
** that are then passed to the Space base class constructor.
*********************************************************************/
CryoChamber::CryoChamber(Space* tempUp, 
                         Space* tempRight, 
                         Space* tempDown, 
                         Space* tempLeft,
                         string tempName)
			:Space(tempUp, tempRight, tempDown, tempLeft, tempName)
{
	actionStatus = false;
    pressureSuit = new Item("Pressure Suit");
}

/*********************************************************************
** Description: Destructor that will delete the pressureSuit item
** if it exists.
*********************************************************************/
CryoChamber::~CryoChamber()
{
    if (pressureSuit)
    {
        delete pressureSuit;
        pressureSuit = nullptr;
    }
}

/*********************************************************************
** Description: Method that will display the description of the Cryo 
** Chamber
*********************************************************************/ 
void CryoChamber::displayDesc()
{
    
}

/*********************************************************************
** Description: Method that will initiate the derived class' special 
** action(s) 
*********************************************************************/
void CryoChamber::specialAction()
{
    
}

/*********************************************************************
** Description: Virtual function that will return the item(s) in the 
** chamber
*********************************************************************/
Item* CryoChamber::getItem()
{
    Item* temp = pressureSuit;
    pressureSuit = nullptr;
    return temp;
}



