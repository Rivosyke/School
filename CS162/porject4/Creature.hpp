/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the specification file for the Creature class.
** This class has four data members: Two ints for strength and armor,
** a bool to indicate the living status of the Creature, and a string
** for the name.
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
