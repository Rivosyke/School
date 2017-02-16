/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the implementation file for the Die class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Barbarian.hpp"

Barbarian::Barbarian() : Creature(12, 0)
{
    attackDie1 = new Die(6);
    attackDie2 = new Die(6);
    defenseDie1 = new Die(6);
    defenseDie2 = new Die(6);
}
int Barbarian::attack()
{
    return ((attackDie1->rollDice()) + (attackDie2->rollDice()));
}
void Barbarian::defense(int attackRating)
{
    cout << "Attack Rating : " << attackRating << endl;
    int defenseRating = (defenseDie1->rollDice() + defenseDie2->rollDice());
    cout << "Defense Rating: " << defenseRating << endl;
    int roundResult;
    if ((attackRating - defenseRating) - armorRating <= 0 )
    {
        roundResult = 0;
    }
    else
    {
        roundResult = (attackRating - defenseRating) - armorRating;
    }
    
    if ((strengthRating - roundResult) <= 0)
    {
        strengthRating = 0;
        alive = false;
    }
    else
    {
        cout << "Round Result  : " << roundResult << endl;
        strengthRating -= roundResult;
    }
}

Barbarian::~Barbarian()
{
    delete attackDie1;
    delete attackDie2;
    delete defenseDie1;
    delete defenseDie2;
}

