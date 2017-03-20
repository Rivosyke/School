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
** Description: Method that will display the description of the cockpit
** based on the special action status.
*********************************************************************/ 
void Cockpit::displayDesc()
{
    // Description based on if the FTLFOB is not present in the cockpit
	if (!FTLFOB)
    {
        cout << "You are in the cockpit, surrounded by a dizzying array of monitors\n"
			 << "and consoles providing readouts from every part of the ship. Through\n"
			 << "the viewscreen, all you see is a starfield. Off to the left,\n"
			 << "though, you see a section of space where the stars are elongated\n"
			 << "and curved. Perhaps this is how you can see the effects of the\n"
			 << "black hole you are near. Between the consoles at hand-level,\n" 
			 << "there appears to be a slot for a small key. It strikes you as odd\n"
			 << "that an advanced piece of technology such as this ship would still\n"
			 << "require a simple key to function." << endl;
    }
    else
    {
        cout << "You are in the cockpit, surrounded by a dizzying array of monitors\n"
			 << "and consoles providing readouts from every part of the ship. Through\n"
			 << "the viewscreen, all you see is a starfield. Off to the left,\n"
			 << "though, you see a section of space where the stars are elongated\n"
			 << "and curved. Perhaps this is how you can see the effects of the\n"
			 << "black hole you are near. Now that the key is inserted into the\n"
			 << "slot, the fuzzy dice it is attached to are resting on adjoining\n"
			 << "consoles." << endl;
    }
}

/*********************************************************************
** Description: Method that will initiate the derived class' special 
** action(s) and return false if the action has already been done and
** true if the action is performed.
*********************************************************************/
bool Cockpit::specialAction()
{
    // The cockpit can engage the FTL drive to escape the black hole, 
    // provided the ship is fixed and the key is in the slot
	printColor("With everything fixed and the key inserted, the ship is ready\n", MAGENTA,BOLD); 
	printColor("to FTL away from the black hole. Praying to whatever deity will\n",MAGENTA,BOLD);
	printColor("listen, you press the 'Emergency FTL' button on the navigation\n",MAGENTA,BOLD);
	printColor("console, a move that will make a short range jump in the direction\n",MAGENTA,BOLD);
	printColor("the ship is currently facing. You hope that the ship is not pointed\n",MAGENTA,BOLD);
	printColor("in the wrong direction...\n",MAGENTA,BOLD);
	cout << endl;
	printColor("You hear a hum emanate from the rear of the ship and feel the deck\n",MAGENTA,BOLD);
	printColor("plates start to vibrate. You quickly sit at one of the crew stations\n",MAGENTA,BOLD);
	printColor("and strap yourself in. As you fasten the last restraint, you see the\n",MAGENTA,BOLD);
	printColor("the starfield start to blur and feel an indescribable acceleration\n",MAGENTA,BOLD);
	printColor("slamming you into your chair. You shy away from thinking what would\n",MAGENTA,BOLD);
	printColor("have happened had you not sat down and restrained yourself...\n",MAGENTA,BOLD);
	cout << endl;
	printColor("And then it was all over. The ship dropped out of FTL and\n",MAGENTA,BOLD);
	printColor("starts slowly drifting in the direction it exited from FTL.\n",MAGENTA,BOLD);
	printColor("You can no longer feel the constant pull in one direction of the\n",MAGENTA,BOLD);
	printColor("black hole and the automated countdown has ceased. It appears you\n",MAGENTA,BOLD);
	printColor("are you safe, for the time being.\n",MAGENTA,BOLD);
	cout << endl;
	printColor("Now that you have escaped the black hole, you need to decide what\n",MAGENTA,BOLD);
	printColor("your next move is..\n",MAGENTA,BOLD);

	actionStatus = true;
	return true;
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

/*********************************************************************
** Description: Method that will check, and return an appropriate value,
** if the FTLFOB is in the cockpit or not.
*********************************************************************/
bool Cockpit::hasFOB()
{
	if (FTLFOB)
	{
		return true;
	}
	else
	{
		return false;
	}
}

