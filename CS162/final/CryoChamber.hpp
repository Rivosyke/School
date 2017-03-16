/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the specification file for the Vampire class.
** This class has two data members: two pointers to Die objects that 
** represent attack and defense die. It inherits other data members
** and methods from the Creature super class.
*********************************************************************/

#include "Space.hpp"


#ifndef CRYOCHAMBER_HPP
#define CRYOCHAMBER_HPP

class CryoChamber: public Space
{
	private:
		bool actionStatus;
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
};

#endif // CRYOCHAMBER_HPP
