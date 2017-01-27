/*********************************************************************
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This is the definition file for the LoadedDie class. 
** This class has no data members of its own but inherits from the 
** Die class. It will call the parent class's constructor to initialize 
** that inherited data member.
*********************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

class LoadedDie : public Die
{
    public:
        int rollDice();
        LoadedDie(int sides);
};



#endif // LOADEDDIE_HPP
