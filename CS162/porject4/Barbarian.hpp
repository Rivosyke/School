/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the specification file for the Barbarian class.
** This class has four data members: pointers to Die objects that 
** represent attack and defense die. It inherits other data members
** and methods from the Creature super class.
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian: public Creature
{
    private:
        Die* attackDie1;
        Die* attackDie2;
        Die* defenseDie1;
        Die* defenseDie2;
    
    public:
        Barbarian();
        int attack();
        void defense(int attackRating);
        ~Barbarian();
};

#endif // BARBARIAN_HPP
