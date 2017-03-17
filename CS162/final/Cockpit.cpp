/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the Cockpit class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Cockpit.hpp"

/*********************************************************************
** Description: Constructor that will take in pointers to Space objects
** that are then passed to the Space base class constructor.
*********************************************************************/
Cockpit::Cockpit(Space* tempUp, 
                         Space* tempRight, 
                         Space* tempDown, 
                         Space* tempLeft,
                         string tempName)
			:Space(tempUp, tempRight, tempDown, tempLeft, tempName)
{
    FTLFOB = nullptr;
	actionStatus = false;
    specialActionName = "Engage FTL";
}

/*********************************************************************
** Description: Destructor that will delete the FTLFOB, if it has been
** placed in the cockpit.
*********************************************************************/
Cockpit::~Cockpit()
{
    if (FTLFOB)
    {
        delete FTLFOB;
        FTLFOB = nullptr;
    }
}

/*********************************************************************
** Description: Method that will display the description of the Cryo 
** Chamber based on the special action status.
*********************************************************************/ 
void Cockpit::displayDesc()
{
    if (!actionStatus)
    {        
        cout << "\n" 
             << "\n"
             << "\n"
             << "\n"
             << "" << endl;
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
bool Cockpit::specialAction()
{
    // The cockpit can engage FTL to escape the black hole, provided the ship is fixed
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
** Description: Virtual function that will return nullptr as there are
** no items in the Cockpit.
*********************************************************************/
Item* Cockpit::getItem()
{
    printColor("There are no items of worth in the cockpit.\n",RED,BOLD);
    return nullptr;
}

/*********************************************************************
** Description: Virtual function that will return if the room has any
** use for items in the player's inventory.
*********************************************************************/
bool Cockpit::canUseItems()
{
    return true;
}

/*********************************************************************
** Description: Virtual function will take in a Space pointer that
** is where the player wants to move to. Returns a bool depending on 
** if that move location is acceptable based on special actions.
*********************************************************************/
bool Cockpit::canChangeRooms(Space* newSpace)
{
    return true;
}

/*********************************************************************
** Description: Virtual function that will test if the passed in item
** is the correct item for this room. Will return false if it is not.
*********************************************************************/
bool Cockpit::placeItem(Item* itemToPlace)
{
    if (itemToPlace -> getName() != "FTL Engagement FOB on a fuzzy dice keychain")
    {
        return false;
    }
    else
    {
        FTLFOB = itemToPlace;
        return true;
    }
}
