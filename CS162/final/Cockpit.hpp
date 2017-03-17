/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the Cockpit class.
** This class has three data members: A Item pointer for the item to be
** place in the cockpit, a string to hold the name of the special action, 
** and a bool that represents if the action has been taken. It inherits 
** other data members and methods from the Space super class.
*********************************************************************/

#include "Space.hpp"


#ifndef COCKPIT_HPP
#define COCKPIT_HPP

class Cockpit: public Space
{
	private:
		bool actionStatus;
        Item* FTLFOB;
        string specialActionName;
	public:
		Cockpit(Space* tempUp, 
                    Space* tempRight, 
                    Space* tempDown, 
                    Space* tempLeft,
                    string tempName);
        ~Cockpit();
		void displayDesc();
		bool specialAction();
        Item* getItem();
        bool canUseItems();
        bool canChangeRooms(Space* newSpace);
        bool placeItem(Item* itemToPlace);
};

#endif // COCKPIT_HPP
