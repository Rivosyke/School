/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the specification file for the Die class.
** This class has one data member: an int to hold the number of sides
** that the Die will have. Input validation in main() will ensure
** that the number will be greater than 1.
*********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "Die.hpp"
#include "utility.hpp"
#include <iostream>
#include <string> 

using namespace std;

class Creature
{
	protected:
		int strengthRating;
		int armorRating;
        bool alive;
        string name;
    public:
        Creature(int tempStr, int tempArmor, string tempName);
        virtual int attack() = 0;
        virtual void defense(int attackRating) = 0;
        virtual ~Creature();
        int getStr();
        int getArmor();
        bool living();
        string getName();
        
};


#endif // CREATURE_HPP
