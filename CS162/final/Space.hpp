/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the Space class.
** This class has four data members: four pointers to other Space 
** objects that will actually be derived classes. 
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Item.hpp"
#include <string>
#include <iostream>
#include "utility.hpp"
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

enum direction{UP,RIGHT,DOWN,LEFT};

class Space
{
    protected:
        Space* Up;
        Space* Right;
        Space* Down;
        Space* Left;
        string name;
    
    public:
        Space(Space* tempUp, 
              Space* tempRight, 
              Space* tempDown, 
              Space* tempLeft, 
              string tempName);
		void setDirectionPointer(Space* spaceToSet, direction position);
		void fillSpaceVector(vector<Space*> *availableRooms);
        virtual ~Space();
        virtual void displayDesc() = 0;
        virtual bool specialAction() = 0;
        virtual Item* getItem() = 0;
        string getName();
        virtual bool canUseItems() = 0;
        
};

#endif // SPACE_HPP


