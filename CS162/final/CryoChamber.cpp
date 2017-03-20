/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the CryoChamber class.
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
    pressureSuit = new Item("Pressure Suit");

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
    else if (!pressureSuit)
    {
        cout << "With emergency power now on, the room is well lit. You see\n"
             << "your empty cryo pod, the emergency power console, and the\n"
             << "now empty storage locker." << endl;
    }
    else
    {
        cout << "With emergency power now on, the room is well lit. You notice\n"
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
        printColor("You've already turned on emergency power; this console has no further function.\n",RED,BOLD);
        return false;
    }
    else
    {
        printColor("The console appears to control emergency power. You briefly wonder why the ship\n", GREEN, BOLD); 
        printColor("designers would put this console in this room. As you engage emergency power, the\n", GREEN, BOLD); 
        printColor("red lights stop flashing and the room's normal lighting returns. Now that the room\n",GREEN, BOLD);
        printColor("is fully illuminated, you see a pressure suit in a storage locker against a wall.\n", GREEN, BOLD);
        actionStatus = true;
        return true;
    }
    
}

/*********************************************************************
** Description: Virtual function that will return the item(s) in the 
** chamber.
*********************************************************************/
Item* CryoChamber::getItem()
{
    if (!pressureSuit)
    {
        printColor("There are no more items to be picked up in this room.\n",RED,BOLD);
        return nullptr;
    }
	if (actionStatus)
	{		
		Item* temp = pressureSuit;
		pressureSuit = nullptr;
		return temp;
	}
	else
	{
		printColor("In the near-dark, you can't see anything worth picking up.\n",GREEN,BOLD);
		printColor("Perhaps there is a way to restore power to the lights...\n",GREEN,BOLD);
		return nullptr;
	}
}

/*********************************************************************
** Description: Virtual function that will return if the room has any
** use for items in the player's inventory.
*********************************************************************/
bool CryoChamber::canUseItems()
{
	// The Cryo Chamber has no use for any of the player's items.
    return false;
}

/*********************************************************************
** Description: Virtual function will take in a Space pointer that
** is where the player wants to move to. Returns a bool depending on 
** if that move location is acceptable based on special actions.
*********************************************************************/
bool CryoChamber::canChangeRooms(Space* newSpace)
{
    if (!actionStatus)
    {
        printColor("During the brief periods of illumination provided by the flashing red lights\n",GREEN,BOLD);
        printColor("you see the door controls; they do not appear to have power. Perhaps there is\n",GREEN,BOLD);
        printColor("a way to restore power to the room...\n",GREEN,BOLD);
        return false;
    }
    else
    {
        return true;
    }
}

/*********************************************************************
** Description: Virtual function that will do nothing as this room
** doesn't take in any items.
*********************************************************************/
bool CryoChamber::placeItem(Item* itemToPlace)
{
    return false;
}
