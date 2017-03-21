/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the StorageRoom class.
** This class has three data members: A Item pointer for the item in
** the chamber, a string to hold the name of the special action, and
** a bool that represents if the action has been taken. It inherits 
** other data members and methods from the Space super class.
*********************************************************************/

#include "Space.hpp"


#ifndef STORAGEROOM_HPP
#define STORAGEROOM_HPP

class StorageRoom: public Space
{
	private:
        Item* pressureRegulator;
        
	public:
		StorageRoom(Space* tempUp, 
                    Space* tempRight, 
                    Space* tempDown, 
                    Space* tempLeft,
                    string tempName);
        ~StorageRoom();
		void displayDesc();
		bool specialAction();
        Item* getItem();
        bool canUseItems();
        bool canChangeRooms(Space* newSpace);
        bool placeItem(Item* itemToPlace);
};

#endif // STORAGEROOM_HPP
