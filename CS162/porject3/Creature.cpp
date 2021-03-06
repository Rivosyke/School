/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the implementation file for the Die class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Creature.hpp"

Creature::Creature(int tempStr, int tempArmor, string tempName)
{
    strengthRating = tempStr;
    armorRating = tempArmor;
    alive = true;
    name = tempName;
}
Creature::~Creature()
{}

int Creature::getStr()
{
    return strengthRating;
}
int Creature::getArmor()
{
    return armorRating;
}
bool Creature::living()
{
    return alive;
}

string Creature::getName()
{
    return name;
}
