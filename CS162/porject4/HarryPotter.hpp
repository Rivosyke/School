/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the specification file for the Harry Potter class.
** This class has 5 data members: four pointers to Die objects that 
** represent attack/defense die and a bool to represent if Harry is on
** his first life. It inherits other data members and methods from the 
** Creature super class.
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

class HarryPotter: public Creature
{
    private:
        Die* attackDie1;
        Die* attackDie2;
        Die* defenseDie1;
        Die* defenseDie2;
        bool firstLife;

    public:
        HarryPotter();
        int attack();
        void defense(int attackRating);
        ~HarryPotter();
};

#endif // HARRYPOTTER_HPP
