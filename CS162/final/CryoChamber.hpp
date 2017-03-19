/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the CryoChamber class.
** This class has three data members: A Item pointer for the item in
** the chamber, a string to hold the name of the special action, and
** a bool that represents if the action has been taken. It inherits 
** other data members and methods from the Space super class.
*********************************************************************/

#include "Space.hpp"


#ifndef CRYOCHAMBER_HPP
#define CRYOCHAMBER_HPP

class CryoChamber: public Space
{
	private:
        Item* pressureSuit;
        string specialActionName;
	public:
		CryoChamber(Space* tempUp, 
                    Space* tempRight, 
                    Space* tempDown, 
                    Space* tempLeft,
                    string tempName);
        ~CryoChamber();
		void displayDesc();
		bool specialAction();
        Item* getItem();
        bool canUseItems();
        bool canChangeRooms(Space* newSpace);
        bool placeItem(Item* itemToPlace);
};

#endif // CRYOCHAMBER_HPP
