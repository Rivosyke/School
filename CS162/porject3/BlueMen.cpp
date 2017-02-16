/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the implementation file for the Die class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "BlueMen.hpp"

BlueMen::BlueMen() : Creature(12, 3)
{
    attackDie1 = new Die(10);
    attackDie2 = new Die(10);
    defenseDie.push_back(new Die(6));
    defenseDie.push_back(new Die(6));
    defenseDie.push_back(new Die(6));
    firstDieLost = false;
    secondDieLost = false;
}
int BlueMen::attack()
{
    return ((attackDie1->rollDice()) + (attackDie2->rollDice()));
}
void BlueMen::defense(int attackRating)
{
    cout << "Attack Rating : " << attackRating << endl;
    
    int defenseRating = 0;
    
    for (unsigned int x = 0; x < defenseDie.size(); x++)
    {
        defenseRating += defenseDie.at(x)->rollDice();
    }
    
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
        if (strengthRating <= 8 and strengthRating > 4 and !firstDieLost)
        {
            defenseDie.pop_back();
            firstDieLost = true;
        }
        else if (strengthRating <= 4 and strengthRating > 0 and !secondDieLost)
        {
            defenseDie.pop_back();
            secondDieLost = true;
        }
        cout << "Defense Die   : " << defenseDie.size() << endl;
    }
}

BlueMen::~BlueMen()
{
    delete attackDie1;
    delete attackDie2;
}
