/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the Corridor class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Corridor.hpp"

/*********************************************************************
** Description: Constructor that will take in pointers to Space objects
** that are then passed to the Space base class constructor.
*********************************************************************/
Corridor::Corridor(Space* tempUp, 
                         Space* tempRight, 
                         Space* tempDown, 
                         Space* tempLeft,
                         string tempName)
			:Space(tempUp, tempRight, tempDown, tempLeft, tempName)
{
    specialActionName = "Turn on the lights";
}

/*********************************************************************
** Description: Destructor that does nothing
*********************************************************************/
Corridor::~Corridor()
{}

/*********************************************************************
** Description: Method that will display the description of the Corridor 
** based on the special action status.
*********************************************************************/ 
void Corridor::displayDesc()
{
    if (!actionStatus)
    {        
        cout << "You step into the corridor and peer into the darkness.\n"
			 << "Perhaps there is a way to turn on the lights..." << endl;
    }
    else
    {
        cout << "The fluorescent lights reveal a long hallway with doors\n"
			 << "leading to various locations." << endl;
    }
}

/*********************************************************************
** Description: Method that will initiate the derived class' special 
** action(s) and return false if the action has already been done and
** true if the action is performed.
*********************************************************************/
bool Corridor::specialAction()
{
    // Lights can be turned to illuminate the passage
    if (actionStatus)
    {
        printColor("The lights are already on and they don't appear to turn off,\n",RED,BOLD);
        printColor("no matter how many times you mash the button.\n",RED,BOLD);
        return false;
    }
    else
    {
        printColor("The corridor's overhead fluorescents flicker to life, shedding light on the long passageway.\n", GREEN, ITALIC); 
        actionStatus = true;
        return true;
    }
    
}

/*********************************************************************
** Description: Virtual function that will output appropriate messages
** based on if the lights are on. The corridors have no items.
*********************************************************************/
Item* Corridor::getItem()
{
	if (actionStatus)
	{		
		printColor("Now that the corridor is illuminated, you can see nothing of interest here.\n",GREEN,BOLD);
		return nullptr;
	}
	else
	{
		printColor("In the near-dark of the corridor, you can't see anything worth picking up.\n",GREEN,BOLD);
		return nullptr;
	}
}

/*********************************************************************
** Description: Virtual function that will return if the room has any
** use for items in the player's inventory.
*********************************************************************/
bool Corridor::canUseItems()
{
	// The Corridor has no use for any of the player's items.
    return false;
}

/*********************************************************************
** Description: Virtual function will take in a Space pointer that
** is where the player wants to move to. Returns a bool depending on 
** if that move location is acceptable based on special actions.
*********************************************************************/
bool Corridor::canChangeRooms(Space* newSpace)
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
bool Corridor::placeItem(Item* itemToPlace)
{
    return false;
}
