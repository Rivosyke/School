/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the Corridor class.
** This class has two data members: two pointers to Die objects that 
** represent attack and defense die. It inherits other data members
** and methods from the Space super class.
*********************************************************************/

#include "Space.hpp"

#ifndef CORRIDOR_HPP
#define CORRIDOR_HPP

class Corridor: public Space
{        
	public:
		Corridor(Space* tempUp, 
                    Space* tempRight, 
                    Space* tempDown, 
                    Space* tempLeft,
                    string tempName);
        ~Corridor();
		void displayDesc();
		bool specialAction();
        Item* getItem();
        bool canUseItems();
        bool canChangeRooms(Space* newSpace);
        bool placeItem(Item* itemToPlace);
};

#endif // CORRIDOR_HPP
