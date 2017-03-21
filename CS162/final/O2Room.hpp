/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the O2Room class.
** This class has two data members: A Item pointer for the item in
** the room and a string to hold the name of the special action. 
** It inherits other data members and methods from the Space super class.
*********************************************************************/

#include "Space.hpp"


#ifndef O2ROOM_HPP
#define O2ROOM_HPP

class O2Room: public Space
{
	private:
        Item* pressureRegulator;
	public:
		O2Room(Space* tempUp, 
                    Space* tempRight, 
                    Space* tempDown, 
                    Space* tempLeft,
                    string tempName);
        ~O2Room();
		void displayDesc();
		bool specialAction();
        Item* getItem();
        bool canUseItems();
        bool canChangeRooms(Space* newSpace);
        bool placeItem(Item* itemToPlace);
};

#endif // O2ROOM_HPP
