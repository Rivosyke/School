/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the StorageRoom class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "StorageRoom.hpp"

/*********************************************************************
** Description: Constructor that will take in pointers to Space objects
** that are then passed to the Space base class constructor.
*********************************************************************/
StorageRoom::StorageRoom(Space* tempUp, 
                         Space* tempRight, 
                         Space* tempDown, 
                         Space* tempLeft,
                         string tempName)
			:Space(tempUp, tempRight, tempDown, tempLeft, tempName)
{
	actionStatus = false;
    pressureRegulator = new Item("Oxygen Pressure Regulator");

    specialActionName = "Turn on lights";
}

/*********************************************************************
** Description: Destructor that will delete the pressure regulator item
** if it exists.
*********************************************************************/
StorageRoom::~StorageRoom()
{

    if (pressureRegulator)
    {
        delete pressureRegulator;
        pressureRegulator = nullptr;
    }
}

/*********************************************************************
** Description: Method that will display the description of the Storage 
** Room based on the special action status.
*********************************************************************/ 
void StorageRoom::displayDesc()
{
    if (!actionStatus)
    {        
        cout << "In the dim light filtering in from the corridor behind you,\n"
             << "you can see the outline of shelves along the wall." << endl;
    }
    else if (!pressureRegulator)
    {
        cout << "With the lights on, you can see that the room is little more\n" 
             << "a closet with empty shelves lining the walls and a crumpled\n"
             << "box on the floor." << endl;
    }
    else
    {
        cout << "With the lights on, you can see that the room is little more\n" 
             << "a closet with empty shelves lining the walls and a crumpled\n"
             << "box on the floor. In the box is a rectangular device." << endl;
    }
}

/*********************************************************************
** Description: Method that will initiate the derived class' special 
** action(s) and return false if the action has already been done and
** true if the action is performed.
*********************************************************************/
bool StorageRoom::specialAction()
{
    // Lights can be turned to illuminate the room
    if (actionStatus)
    {
        printColor("The lights are already on and they don't appear to turn off, no matter how many times you mash the button.\n",RED,ITALIC);
        return false;
    }
    else
    {
        printColor("The storage room's overhead fluorescents flicker to life, revealing the\n", GREEN, ITALIC);
        printColor("room's contents.\n", GREEN, ITALIC); 
        actionStatus = true;
        return true;
    }
}

/*********************************************************************
** Description: Virtual function that will return the item(s) in the 
** room.
*********************************************************************/
Item* StorageRoom::getItem()
{
	if (actionStatus)
	{	
        printColor("You stoop down and take the device out the box. It has the words\n",GREEN,BOLD);
        printColor("'Pressure Regulator' stamped in tiny letters on the bottom.\n",GREEN,BOLD);
        Item* temp = pressureRegulator;
        pressureRegulator = nullptr;
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
bool StorageRoom::canUseItems()
{
	// The Storage Room has no use for any of the player's items.
    return false;
}

/*********************************************************************
** Description: Virtual function will take in a Space pointer that
** is where the player wants to move to. Returns a bool depending on 
** if that move location is acceptable based on special actions.
*********************************************************************/
bool StorageRoom::canChangeRooms(Space* newSpace)
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
bool StorageRoom::placeItem(Item* itemToPlace)
{
    return false;
}
