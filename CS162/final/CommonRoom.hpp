/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the CommonRoom class.
** This class has two data members: A Item pointer for the item in
** the room and a string to hold the name of the special action. 
** It inherits other data members and methods from the Space super class.
*********************************************************************/

#include "Space.hpp"


#ifndef COMMONROOM_HPP
#define COMMONROOM_HPP

class CommonRoom: public Space
{
	private:
        Item* FTLFOB;
        
	public:
		CommonRoom(Space* tempUp, 
                    Space* tempRight, 
                    Space* tempDown, 
                    Space* tempLeft,
                    string tempName);
        ~CommonRoom();
		void displayDesc();
		bool specialAction();
        Item* getItem();
        bool canUseItems();
        bool canChangeRooms(Space* newSpace);
        bool placeItem(Item* itemToPlace);
};

#endif // COMMONROOM_HPP
