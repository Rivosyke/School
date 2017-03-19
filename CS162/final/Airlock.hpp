/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the Airlock class.
** This class has one data member: A string that holds the name of the 
** special action. It inherits other data members and methods from the 
** Space super class.
*********************************************************************/

#include "Space.hpp"

#ifndef AIRLOCK_HPP
#define AIRLOCK_HPP

class Airlock: public Space
{
	private:
        string specialActionName;
        
	public:
		Airlock(Space* tempUp, 
                    Space* tempRight, 
                    Space* tempDown, 
                    Space* tempLeft,
                    string tempName);
        ~Airlock();
		void displayDesc();
		bool specialAction();
        Item* getItem();
        bool canUseItems();
        bool canChangeRooms(Space* newSpace);
        bool placeItem(Item* itemToPlace);
};

#endif // AIRLOCK_HPP
