/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the CargoHold class.
** This class has two data members: A Item pointer for the item in
** the room and a string to hold the name of the special action. 
** It inherits other data members and methods from the Space super class.
*********************************************************************/

#include "Space.hpp"


#ifndef CARGOHOLD_HPP
#define CARGOHOLD_HPP

class CargoHold: public Space
{
	private:
        Item* emFieldRegulator;
	public:
		CargoHold(Space* tempUp, 
                    Space* tempRight, 
                    Space* tempDown, 
                    Space* tempLeft,
                    string tempName);
        ~CargoHold();
		void displayDesc();
		bool specialAction();
        Item* getItem();
        bool canUseItems();
        bool canChangeRooms(Space* newSpace);
        bool placeItem(Item* itemToPlace);
};

#endif // CARGOHOLD_HPP
