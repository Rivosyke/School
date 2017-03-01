/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the specification file for the Die class.
** This class has one data member: an int to hold the number of sides
** that the Die will have. Input validation in main() will ensure
** that the number will be greater than 1.
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
