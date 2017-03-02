/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the implementation file for the Creature class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Creature.hpp"

/*********************************************************************
** Description: Constructor that sets the passed in values to their 
** appropriate data member.
*********************************************************************/
Creature::Creature(int tempStr, int tempArmor, string tempName)
{
    strengthRating = tempStr;
    armorRating = tempArmor;
    alive = true;
    name = tempName;
}

/*********************************************************************
** Description: Destructor that does nothing.
*********************************************************************/
Creature::~Creature()
{}

/*********************************************************************
** Description: Method that returns the strengthRating data member
*********************************************************************/
int Creature::getStr()
{
    return strengthRating;
}

/*********************************************************************
** Description: Method that returns the armorRating data member
*********************************************************************/
int Creature::getArmor()
{
    return armorRating;
}

/*********************************************************************
** Description: Method that returns the alive data member
*********************************************************************/
bool Creature::living()
{
    return alive;
}

/*********************************************************************
** Description: Method that returns the name data member.
*********************************************************************/
string Creature::getName()
{
    return name;
}
