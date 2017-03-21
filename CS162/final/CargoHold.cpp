/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the CargoHold class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "CargoHold.hpp"

/*********************************************************************
** Description: Constructor that will take in pointers to Space objects
** that are then passed to the Space base class constructor.
*********************************************************************/
CargoHold::CargoHold(Space* tempUp, 
                         Space* tempRight, 
                         Space* tempDown, 
                         Space* tempLeft,
                         string tempName)
			:Space(tempUp, tempRight, tempDown, tempLeft, tempName)
{
    emFieldRegulator = new Item("EM Field Regulator");
}

/*********************************************************************
** Description: Destructor that will delete the EM Field Regulator item
** if it exists.
*********************************************************************/
CargoHold::~CargoHold()
{

    if (emFieldRegulator)
    {
        delete emFieldRegulator;
        emFieldRegulator = nullptr;
    }
}

/*********************************************************************
** Description: Method that will display the description of the Cargo
** Hold based on the special action status.
*********************************************************************/ 
void CargoHold::displayDesc()
{
    if (!actionStatus and !emFieldRegulator)
    {        
        cout <<"You are in an expansive space filled with machinery designed\n"
			 <<"for loading / offloading cargo containers. A lone box fastened to\n"
             <<"a wall with metal straps near the door now sits alone and empty. \n"
             <<"There are no containers in the hold now, possibly due to the cargo\n"
             <<"door being suddenly opened, resulting in a violent decompression.\n"
             <<"Through the open door, the vastness of space looms...\n\n"
             <<"The door needs to be closed if the ship is to perform an FTL jump." << endl;
    }
    else if (!actionStatus)
    {        
        cout <<"You are in an expansive space filled with machinery designed\n"
			 <<"for loading / offloading cargo containers. A lone box fastened to\n"
             <<"a wall with metal straps near the door has a cylindrical object \n"
             <<"in it. There are no containers in the hold now, possibly due to\n"
             <<"the cargo door being suddenly opened, resulting in a violent\n"
             <<"decompression. Through the open door, the vastness of space looms.\n"
             <<"The door needs to be closed if the ship is to perform an FTL jump." << endl;
    }

    else if (!emFieldRegulator and !actionStatus)
    {
        cout <<"You are in an expansive space filled with machinery designed\n"
			 <<"for loading / offloading cargo containers. A lone box fastened to\n"
             <<"a wall with metal straps near the door now sits empty and alone. \n"
             <<"There are no containers in the hold now, possibly due to the cargo\n"
             <<"door being suddenly opened, resulting in a violent decompression.\n"
             <<"Through the open door, the vastness of space looms...\n\n"
             <<"The door needs to be closed if the ship is to perform an FTL jump." << endl;
    }
    else if (actionStatus and !emFieldRegulator)
    {
        cout <<"You are in an expansive space filled with machinery designed\n"
			 <<"for loading / offloading cargo containers. A lone box fastened to\n"
             <<"a wall with metal straps near the door now sits empty and alone. \n"
             <<"There are no containers in the hold and while the cargo door is \n"
             <<"now closed, the room is still depressurized." << endl;
    }
    else if (actionStatus)
    {
        cout <<"You are in an expansive space filled with machinery designed\n"
			 <<"for loading / offloading cargo containers. A lone box fastened to\n"
             <<"a wall with metal straps near the door has a cylindrical object\n"
             <<"in it. There are no containers in the hold and while the cargo \n"
             <<"door is now closed, the room is still depressurized." << endl;
    }
}

/*********************************************************************
** Description: Method that will initiate the derived class' special 
** action(s) and return false if the action has already been done and
** true if the action is performed.
*********************************************************************/
bool CargoHold::specialAction()
{
    // The cargo hold door can be closed 
    if (actionStatus)
    {
        printColor("The cargo hold door is already closed. There's no need to open it at this time.\n",RED,BOLD);
        return false;
    }
    else
    {
        printColor("You approach the gaping hole left by the open cargo door and try to avoid\n", GREEN, BOLD);
        printColor("looking into the void. The lever to close the door is on the right hand side\n", GREEN, BOLD); 
        printColor("of the hold, near the exit. You grip the lever with both hands and force it\n",GREEN,BOLD);
        printColor("down into the closed position. The two halves of the door mechanism slowly\n",GREEN,BOLD);
        printColor("come together and form a seal against the vacuum of space.\n",GREEN,BOLD);
        actionStatus = true;
        return true;
    }
}

/*********************************************************************
** Description: Virtual function that will return the item(s) in the 
** room.
*********************************************************************/
Item* CargoHold::getItem()
{
	if (emFieldRegulator)
	{	
        printColor("Pulling open the flaps of the box reveals a cylindrical object resting\n",GREEN,BOLD);
        printColor("in a form-fitting slot in the box. It has a handle on one end of the \n",GREEN,BOLD);
        printColor("cylinder and two metal prongs on the other. It looks like it is meant\n",GREEN,BOLD);
        printColor("to be inserted into a receptacle. Along one side, in faded letters, is\n",GREEN,BOLD);
        printColor("printed 'EM Field Regulator'.\n",GREEN,BOLD);
        Item* temp = emFieldRegulator;
        emFieldRegulator = nullptr;
        return temp;
	}
	else
	{
		printColor("The box is now empty and there doesn't seem to be anything else of use\n",RED,BOLD);
		printColor("in the cargo hold.\n",RED,BOLD);
		return nullptr;
	}
}

/*********************************************************************
** Description: Virtual function that will return if the room has any
** use for items in the player's inventory.
*********************************************************************/
bool CargoHold::canUseItems()
{
	// The Cargo Hold has no use for any of the player's items.
    return false;
}

/*********************************************************************
** Description: Virtual function will take in a Space pointer that
** is where the player wants to move to. Returns a bool depending on 
** if that move location is acceptable based on special actions.
*********************************************************************/
bool CargoHold::canChangeRooms(Space* newSpace)
{
	return true;
}

/*********************************************************************
** Description: Virtual function that will do nothing as this room
** doesn't take in any items.
*********************************************************************/
bool CargoHold::placeItem(Item* itemToPlace)
{
    return false;
}
