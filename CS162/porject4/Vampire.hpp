/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the specification file for the Vampire class.
** This class has two data members: two pointers to Die objects that 
** represent attack and defense die. It inherits other data members
** and methods from the Creature super class.
*********************************************************************/



#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"
#include "Die.hpp"
#include "utility.hpp"


class Vampire: public Creature
{
    private:
        Die* attackDie1;
        Die* defenseDie1;

    
    public:
        Vampire();
        int attack();
        void defense(int attackRating);
        ~Vampire();
};



#endif // VAMPIRE_HPP
