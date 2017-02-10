/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the implementation file for the Die class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Creature.hpp"

Creature::Creature(int tempStr, int tempArmor)
{
    strengthRating = tempStr;
    armorRating = tempArmor;
}
//int Creature::attack();
//void Creature::defense(int attackRating);
Creature::~Creature()
{
}

int Creature::getStr()
{
    return strengthRating;
}
int Creature::getArmor()
{
    return armorRating;
}
