/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the Engineering class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Engineering.hpp"

/*********************************************************************
** Description: Constructor that will take in pointers to Space objects
** that are then passed to the Space base class constructor.
*********************************************************************/
Engineering::Engineering(Space* tempUp, 
                         Space* tempRight, 
                         Space* tempDown, 
                         Space* tempLeft,
                         string tempName)
			:Space(tempUp, tempRight, tempDown, tempLeft, tempName)
{
    emFieldRegulator = nullptr;
    specialActionName = "Restore Main Power";
}

/*********************************************************************
** Description: Destructor that will delete the pressureRegulator, if 
** it has been placed in the O2 Room.
*********************************************************************/
Engineering::~Engineering()
{
    if (emFieldRegulator)
    {
        delete emFieldRegulator;
        emFieldRegulator = nullptr;
    }
}

/*********************************************************************
** Description: Method that will display the description of the cockpit
** based on the special action status.
*********************************************************************/ 
void Engineering::displayDesc()
{
    if (!actionStatus and !emFieldRegulator)
    {        
        cout << "You are in a room that has a catwalk with metal grating floor plates\n"
             << "spanning across a chamber that contains a single, giant cylinder in\n"
             << "the center. The catwalk connects the door to a console and maintenance\n"
             << "panel on the cylinder. The panel says 'Fusion Reactor Maintenance' and\n"
             << "the panel is labeled 'Reactor Operations'. The reactor appears to be \n"
             << "dormant and the maintenance panel appears to be missing a part." << endl;
        
    }
    // Description based on if the EM Field Regulator is not present in Engineering
    else if (!actionStatus)
    {
        cout << "You are in a room that has a catwalk with metal grating floor plates\n"
             << "spanning across a chamber that contains a single, giant cylinder in\n"
             << "the center. The catwalk connects the door to a console and maintenance\n"
             << "panel on the cylinder. The panel says 'Fusion Reactor Maintenance' and\n"
             << "the panel is labeled 'Reactor Operations'. Though the EM Field Regulator\n"
             << "has been installed, the reactor is still dormant." << endl;
    }
    else
    {
        cout << "You are in a room that has a catwalk with metal grating floor plates\n"
             << "spanning across a chamber that contains a single, giant cylinder in\n"
             << "the center. The catwalk connects the door to a console and maintenance\n"
             << "panel on the cylinder. The panel says 'Fusion Reactor Maintenance' and\n"
             << "the panel is labeled 'Reactor Operations'. The room hums as the reactor\n"
             << "is now active and you can feel a faint vibration if you touch the cylinder." << endl;
    }
}

/*********************************************************************
** Description: Method that will initiate the derived class' special 
** action(s) and return false if the action has already been done and
** true if the action is performed.
*********************************************************************/
bool Engineering::specialAction()
{
    // Main power can be restored, provided the EM Field Regulator is installed
    if (actionStatus)
    {
        printColor("Main power has already been restored.\n",RED,BOLD);
        return false;
    }
    else if (!actionStatus and !emFieldRegulator)
    {
        printColor("You can't restore main power until the EM Field Regulator\n",RED,BOLD);
        printColor("is installed.\n",RED,BOLD);
        return false;
    }
    else
    {
        printColor("The console on the fusion reactor is a sea of red warning\n", GREEN,BOLD); 
        printColor("lights next to readouts of various processes. There is prompt\n",GREEN,BOLD);
        printColor("at the bottom of those readouts asking:\n ",GREEN,BOLD);
        printColor("'Restore main power?'\n",RED,NORMAL);
        printColor("You hit 'yes' and suddenly the warning lights go away and the \n",GREEN,BOLD);
        printColor("numbers on the readouts increase. You don't fully understand what\n",GREEN,BOLD);
        printColor("is going on, but there is a solid green light that's labeled 'FTL'\n",GREEN,BOLD);
        printColor("that seems to indicate that main power is functional again.\n",GREEN,BOLD);
        actionStatus = true;
        return true;
    }
    
}

/*********************************************************************
** Description: Virtual function that will return nullptr as there are
** no items in Engineering.
*********************************************************************/
Item* Engineering::getItem()
{
    printColor("There are no items of worth in Engineering.\n",RED,BOLD);
    return nullptr;
}

/*********************************************************************
** Description: Virtual function that will return if the room has any
** use for items in the player's inventory.
*********************************************************************/
bool Engineering::canUseItems()
{
    return true;
}

/*********************************************************************
** Description: Virtual function will take in a Space pointer that
** is where the player wants to move to. Returns a bool depending on 
** if that move location is acceptable based on special actions.
*********************************************************************/
bool Engineering::canChangeRooms(Space* newSpace)
{
    return true;
}

/*********************************************************************
** Description: Virtual function that will test if the passed in item
** is the correct item for this room. Will return false if it is not.
*********************************************************************/
bool Engineering::placeItem(Item* itemToPlace)
{
    if (itemToPlace -> getName() != "EM Field Regulator")
    {
        return false;
    }
    else
    {
        printColor("On the maintenance panel of the fusion reactor, you see a \n",GREEN,BOLD);
        printColor("cylindrical hole with the label 'EM Field Regulator' printed\n",GREEN,BOLD);
        printColor("printed above it. You take the regulator out, grab the handle\n",GREEN,BOLD);
        printColor("with one hand and support the length with the other hand while\n",GREEN,BOLD);
        printColor("sliding it into the empty slot. It slides in smoothly and turns\n",GREEN,BOLD);
        printColor("90 degrees to lock in place when fully inserted.\n",GREEN,BOLD);
        emFieldRegulator = itemToPlace;
        return true;
    }
}
