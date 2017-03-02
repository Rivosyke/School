/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the specification file for the Medusa class.
** This class has three data members: three pointers to Die objects that 
** represent attack and defense die. It inherits other data members
** and methods from the Creature super class.
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

class Medusa: public Creature
{
    private:
        Die* attackDie1;
        Die* attackDie2;
        Die* defenseDie1;

    
    public:
        Medusa();
        int attack();
        void defense(int attackRating);
        ~Medusa();
};


#endif // MEDUSA_HPP
