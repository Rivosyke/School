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

using std::cout;
using std::endl;
using std::string;

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
        virtual ~Space();
        virtual void displayDesc();
        virtual void specialAction();
        virtual Item* getItem();
        string getName();
};

#endif // SPACE_HPP


