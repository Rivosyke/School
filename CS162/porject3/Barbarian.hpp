/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the specification file for the Die class.
** This class has one data member: an int to hold the number of sides
** that the Die will have. Input validation in main() will ensure
** that the number will be greater than 1.
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
