/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the CommonRoom class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "CommonRoom.hpp"

/*********************************************************************
** Description: Constructor that will take in pointers to Space objects
** that are then passed to the Space base class constructor.
*********************************************************************/
CommonRoom::CommonRoom(Space* tempUp, 
                         Space* tempRight, 
                         Space* tempDown, 
                         Space* tempLeft,
                         string tempName)
			:Space(tempUp, tempRight, tempDown, tempLeft, tempName)
{
	actionStatus = false;
    FTLFOB = new Item("FTL Engagement FOB on a fuzzy dice keychain");

    specialActionName = "Turn on lights";
}

/*********************************************************************
** Description: Destructor that will delete the FTL FOB item
** if it exists.
*********************************************************************/
CommonRoom::~CommonRoom()
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
void CommonRoom::displayDesc()
{
    if (!actionStatus)
    {        
        cout << "Though you are in near darkness, you get a sense that this\n"
             << "room is larger than the corridor you entered from.\n"
			 << "Perhaps there is a way to turn on the lights..." << endl;
    }
    else if (!FTLFOB)
    {
        cout << "With the lights on, you can see that the room is large and\n"
             << "must be used for recreation and eating as there are tables\n"
             << "and chairs, vid screens, and a food dispensary." << endl;
    }
    else
    {
        cout << "With the lights on, you can see that the room is large and\n"
             << "must be used for recreation and eating as there are tables\n"
             << "and chairs, vid screens, and a food dispensary. You see what\n"
             << "look like a pair of fuzzy dice on a nearby table."  << endl;
    }
}

/*********************************************************************
** Description: Method that will initiate the derived class' special 
** action(s) and return false if the action has already been done and
** true if the action is performed.
*********************************************************************/
bool CommonRoom::specialAction()
{
    // Lights can be turned to illuminate the passage
    if (actionStatus)
    {
        printColor("The lights are already on and they don't appear to turn off, no matter how many times you mash the button.\n",RED,ITALIC);
        return false;
    }
    else
    {
        printColor("The common room's overhead fluorescents flicker to life, revealing the\n", GREEN, ITALIC);
        printColor("room's contents.\n", GREEN, ITALIC); 
        actionStatus = true;
        return true;
    }
}

/*********************************************************************
** Description: Virtual function that will return the item(s) in the 
** room.
*********************************************************************/
Item* CommonRoom::getItem()
{
	if (actionStatus)
	{	
        printColor("You approach the table and pick up the object on the table. It appears\n",GREEN,BOLD);
        printColor("to be two pink fuzzy dice on a keychain. On the keychain is a key.\n",GREEN,BOLD);
        printColor("You don't know what this key is for.\n",GREEN,BOLD);
        Item* temp = FTLFOB;
        FTLFOB = nullptr;
        return temp;
	}
	else
	{
		printColor("In the near-dark, you can't see anything worth picking up.\n",GREEN,BOLD);
		printColor("Perhaps there is a way to turn on the lights...\n",GREEN,BOLD);
		return nullptr;
	}
}

/*********************************************************************
** Description: Virtual function that will return if the room has any
** use for items in the player's inventory.
*********************************************************************/
bool CommonRoom::canUseItems()
{
	// The Common Room has no use for any of the player's items.
    return false;
}

/*********************************************************************
** Description: Virtual function will take in a Space pointer that
** is where the player wants to move to. Returns a bool depending on 
** if that move location is acceptable based on special actions.
*********************************************************************/
bool CommonRoom::canChangeRooms(Space* newSpace)
{
     if (!actionStatus)
    {
        printColor("The lack of light in the room prevents you from moving around safely.\n",GREEN,BOLD);
        printColor("Perhaps there is a way to turn the lights on...\n",GREEN,BOLD);
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
bool CommonRoom::placeItem(Item* itemToPlace)
{
    return false;
}
