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
    Up = nullptr;
    specialActionName = "Turn on emergency power";
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
** Chamber based on the special action status.
*********************************************************************/ 
void CryoChamber::displayDesc()
{
    if (!actionStatus)
    {        
        cout << "You are in the Cryo Chamber. Red lights are flashing\n" 
             << "on and off, briefly illuminating the chamber's interior.\n"
             << "During the brief periods of illumination, you can see your\n"
             << "cryo pod against a wall, some sort of console next to it, \n"
             << "and a door opposite the pod." << endl;
    }
    else
    {
        cout << "With Emergency power now on, the room is well lit. You notice\n"
             << "a pressure suit in a storage locker against the wall." << endl;
    }
}

/*********************************************************************
** Description: Method that will initiate the derived class' special 
** action(s) and return false if the action has already been done and
** true if the action is performed.
*********************************************************************/
bool CryoChamber::specialAction()
{
    // Emergency Power can be turned on in this room: turn it on
    if (actionStatus)
    {
        printColor("You've already turned on emergency power; this console has no further function.\n",RED,ITALIC);
        return false;
    }
    else
    {
        printColor("The console appears to control emergency power. You briefly wonder why the ship\n", GREEN, ITALIC); 
        printColor("designers would put this console in this room. As you engage emergency power, the\n", GREEN, ITALIC); 
        printColor("red lights stop flashing and the room's normal lighting returns. Now that the room\n",GREEN, ITALIC);
        printColor("is fully illuminated, you see a pressure suit in a storage locker against a wall.\n", GREEN, ITALIC);
        actionStatus = true;
        return true;
    }
    
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

/*********************************************************************
** Description: Virtual function that will return the item(s) in the 
** chamber
*********************************************************************/
bool CryoChamber::canUseItems()
{
    return true;
}


