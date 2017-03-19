/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the Airlock class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Airlock.hpp"

/*********************************************************************
** Description: Constructor that will take in pointers to Space objects
** that are then passed to the Space base class constructor.
*********************************************************************/
Airlock::Airlock(Space* tempUp, 
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
Airlock::~Airlock()
{}

/*********************************************************************
** Description: Method that will display the description of the Airlock 
** based on the special action status.
*********************************************************************/ 
void Airlock::displayDesc()
{
    if (!actionStatus)
    {   
		printColor("Airlock Status  : ",YELLOW,BOLD);
		printColor("PRESSURIZED\n", GREEN,BOLD);     
        cout << "You are in a small chamber lined with vents. Through\n"
			 << "the window in one airlock door you can see the cargo hold,\n" 
			 << "and the corridor connecting to the common area through the\n"
			 << "other. There is a pressure hazard warning sign on the door\n"
			 << "leading to the cargo hold, which appears to be depressurized.\n"
			 << "Fortunately, your pressure suit will protect you for a time if\n"
			 << "you choose to cycle the airlock." << endl;
    }
    else
    {
		printColor("Airlock Status  : ",YELLOW,BOLD);
		printColor("DEPRESSURIZED\n", RED,BOLD);  
        cout << "You are in a small chamber lined with vents. Through\n"
			 << "the window in one airlock door you can see the cargo hold,\n" 
			 << "and the corridor connecting to the common area through the\n"
			 << "other. There is a pressure hazard warning sign on the door\n"
			 << "leading to the corridor. Your suit is protecting you from\n"
			 << "the vacuum but it won't last forever..." << endl;
    }
}

/*********************************************************************
** Description: Method that will initiate the derived class' special 
** action(s) and return false if the action has already been done and
** true if the action is performed.
*********************************************************************/
bool Airlock::specialAction()
{
    // The airlock can be cycled as the corridor is pressurized and the cargo hold is not
    if (!actionStatus)
    {
        printColor("You active the airlock's cycling system. You can hear the\n",RED,BOLD);
        printColor("pumps extracting the life-giving oxygen mixture and feel\n",RED,BOLD);
        printColor("the change in pressure as your suit compensates for the\n",RED,BOLD);
        printColor("change. As the cycle completes, you notice that the pressure\n",RED,BOLD);
        printColor("hazard holographic sign has switched from the cargo hold door\n",RED,BOLD);
        printColor("to the adjoining corridor.\n",RED,BOLD);
        actionStatus = true;
        return false;
    }
    else
    {
        printColor("You active the airlock's cycling system. You can hear the\n",RED,BOLD);
        printColor("vents pumping out the life-giving oxygen mixture and feel\n",RED,BOLD);
        printColor("the change in pressure as your suit compensates for the\n",RED,BOLD);
        printColor("change. As the cycle completes, you notice that the pressure\n",RED,BOLD);
        printColor("hazard holographic sign has switched from the adjoining corridor\n",RED,BOLD);
        printColor("to the cargo hold.\n",RED,BOLD);
        actionStatus = false;
        return true;
    }
    
}

/*********************************************************************
** Description: Virtual function that will output a message stating
** that there are no items in the airlock.
*********************************************************************/
Item* Airlock::getItem()
{
	printColor("The airlock has no items of interest.\n",GREEN, BOLD);
	return nullptr;
}

/*********************************************************************
** Description: Virtual function that will return if the room has any
** use for items in the player's inventory.
*********************************************************************/
bool Airlock::canUseItems()
{
	// The Airlock has no use for any of the player's items.
    return false;
}

/*********************************************************************
** Description: Virtual function will take in a Space pointer that
** is where the player wants to move to. Returns a bool depending on 
** if that move location is acceptable based on special actions.
*********************************************************************/
bool Airlock::canChangeRooms(Space* newSpace)
{
	if (newSpace -> getName() == "Cargo Hold" and !actionStatus)
	{
		printColor("The airlock is still pressurized and will explosively\n",RED,BOLD);
		printColor("decompress if you open the cargo hold door at this time.\n",RED,BOLD);
		printColor("Decompress the airlock first.\n",RED,BOLD);
		return false;
	}
	else if (newSpace -> getName() == "Cargo Hold" and actionStatus)
	{
		return true;
	}
    else if (newSpace -> getName() == "East Corridor" and actionStatus)
    {
        printColor("The airlock is decompressed still. Opening the corridor door\n",RED,BOLD);
        printColor("now would cause an explosive decompression of the corridor!\n",RED,BOLD);
        printColor("Repressurize the airlock first.\n",RED,BOLD);
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
bool Airlock::placeItem(Item* itemToPlace)
{
    return false;
}
