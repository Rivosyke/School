/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the implementation file for the Die class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Vampire.hpp"


Vampire::Vampire() : Creature(18, 1, "Vampire")
{
    attackDie1 = new Die(12);
    defenseDie1 = new Die(6);
}
int Vampire::attack()
{
    return attackDie1->rollDice();
}
void Vampire::defense(int attackRating)
{
    // Special vampire ability that will get a random 0 or 1 to indicate the 
    // 50% chance to charm the attacker
    if (randomNum(2) == 0)
    {
        cout << "Attack Rating : " << attackRating << endl;
        int defenseRating = defenseDie1->rollDice();
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
    else
    {
        cout << "Charm Successful - No Damage!" << endl;
    }
    
}
Vampire::~Vampire()
{
    delete attackDie1;
    delete defenseDie1;
}
