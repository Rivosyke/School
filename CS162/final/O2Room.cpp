/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the O2Room class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "O2Room.hpp"

/*********************************************************************
** Description: Constructor that will take in pointers to Space objects
** that are then passed to the Space base class constructor.
*********************************************************************/
O2Room::O2Room(Space* tempUp, 
                         Space* tempRight, 
                         Space* tempDown, 
                         Space* tempLeft,
                         string tempName)
			:Space(tempUp, tempRight, tempDown, tempLeft, tempName)
{
    pressureRegulator = nullptr;
}

/*********************************************************************
** Description: Destructor that will delete the pressureRegulator, if 
** it has been placed in the O2 Room.
*********************************************************************/
O2Room::~O2Room()
{
    if (pressureRegulator)
    {
        delete pressureRegulator;
        pressureRegulator = nullptr;
    }
}

/*********************************************************************
** Description: Method that will display the description of the O2 Room
** based on the special action status.
*********************************************************************/ 
void O2Room::displayDesc()
{
    if (!actionStatus and !pressureRegulator)
    {        
        cout << "You are in a room mostly taken up by equipment designed for life\n"
             << "support. You see a complex system of intertwined pipes, valves, \n"
             << "and pumps. There is a console on a pedestal near the back of the\n"
             << "room that is flashing a message. You can sense a disharmonic in \n"
             << "the functionality of the equipment, as if there is a piece missing\n"
             << "to the system." << endl;
        
    }
    // Description based on if the pressureRegulator is not present in the O2 Room
    else if (!actionStatus)
    {
        cout << "You are in a room mostly taken up by equipment designed for life\n"
             << "support. You see a complex system of intertwined pipes, valves, \n"
             << "and pumps. There is a console on a pedestal near the back of the\n"
             << "room that is flashing a message. Installing the pressure regulator\n"
             << "has restored the harmonic balance of the machinery." << endl;
    }
    else
    {
        cout << "You are in a room mostly taken up by equipment designed for life\n"
             << "support. You see a complex system of intertwined pipes, valves, \n"
             << "and pumps. There is a console on a pedestal near the back of the\n"
             << "room. The pressure regulator has been installed and the air \n"
             << "mixture has been tuned." << endl;
    }
}

/*********************************************************************
** Description: Method that will initiate the derived class' special 
** action(s) and return false if the action has already been done and
** true if the action is performed.
*********************************************************************/
bool O2Room::specialAction()
{
    // The Oxygen/Nitrogen mixture needs to be tuned, after the regulator is 
    // installed
    if (actionStatus)
    {
        printColor("The oxygen/nitrogen mixture has already been tuned and the \n",RED,BOLD);
        printColor("console provides no further prompts.\n",RED,BOLD);
        return false;
    }
    else if (!actionStatus and !pressureRegulator)
    {
        printColor("You can't tune the air mixture without the pressure\n",RED,BOLD);
        printColor("regulator installed.\n",RED,BOLD);
        return false;
    }
    else
    {
        printColor("You approach the control panel at the heart of the complex\n", GREEN,BOLD); 
        printColor("series of pumps and pipes. Across the screen scroll readouts\n",GREEN,BOLD);
        printColor("of various life support related processes. In the middle of\n",GREEN,BOLD);
        printColor("the screen is prompt asking:\n",GREEN,BOLD);
        printColor("'Tune Oxygen/Nitrogen mixture for human life?'\n",RED,NORMAL);
        printColor("You briefly ponder what other form of life this system would\n",GREEN,BOLD);
        printColor("be capable of supporting before pressing 'Yes' on the screen.\n",GREEN,BOLD);

        actionStatus = true;
        return true;
    }
    
}

/*********************************************************************
** Description: Virtual function that will return nullptr as there are
** no items in the O2 Room.
*********************************************************************/
Item* O2Room::getItem()
{
    printColor("There are no items of worth in the O2 room.\n",RED,BOLD);
    return nullptr;
}

/*********************************************************************
** Description: Virtual function that will return if the room has any
** use for items in the player's inventory.
*********************************************************************/
bool O2Room::canUseItems()
{
    return true;
}

/*********************************************************************
** Description: Virtual function will take in a Space pointer that
** is where the player wants to move to. Returns a bool depending on 
** if that move location is acceptable based on special actions.
*********************************************************************/
bool O2Room::canChangeRooms(Space* newSpace)
{
    return true;
}

/*********************************************************************
** Description: Virtual function that will test if the passed in item
** is the correct item for this room. Will return false if it is not.
*********************************************************************/
bool O2Room::placeItem(Item* itemToPlace)
{
    if (itemToPlace -> getName() != "Oxygen Pressure Regulator")
    {
        return false;
    }
    else
    {
        printColor("There is a rectangular hole in one of the pumps that looks\n",GREEN,BOLD);
        printColor("like it would fit the pressure regulator in your inventory.\n",GREEN,BOLD);
        printColor("You take it out of your suit pocket and try it in the slot.\n",GREEN,BOLD);
        printColor("It slides in with a satisfying click and the noise in the room\n",GREEN,BOLD);
        printColor("changes audibly, to be less disharmonic.\n",GREEN,BOLD);
        pressureRegulator = itemToPlace;
        return true;
    }
}
