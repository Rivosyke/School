/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the specification file for the Blue Men class.
** This class has five data members: two pointers to Die objects that 
** represent attack die, a vector of Die pointers to hold the defense 
** die, and two bools to represent when the defense die are lost. It 
** inherits other data members and methods from the Creature super class.
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"
#include <vector>

class BlueMen: public Creature
{
    private:
        Die* attackDie1;
        Die* attackDie2;
        vector<Die*> defenseDie;
        bool firstDieLost;
        bool secondDieLost;
        
    
    public:
        BlueMen();
        int attack();
        void defense(int attackRating);
        ~BlueMen();
};
#endif // BLUEMEN_HPP
