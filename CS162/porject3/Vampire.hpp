/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the specification file for the Die class.
** This class has one data member: an int to hold the number of sides
** that the Die will have. Input validation in main() will ensure
** that the number will be greater than 1.
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
