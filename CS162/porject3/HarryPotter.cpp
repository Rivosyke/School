/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the implementation file for the Die class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "HarryPotter.hpp"

HarryPotter::HarryPotter() : Creature(10, 0, "Harry Potter")
{
    attackDie1 = new Die(6);
    attackDie2 = new Die(6);
    defenseDie1 = new Die(6);
    defenseDie2 = new Die(6);
    firstLife = true;
}
int HarryPotter::attack()
{
    return ((attackDie1->rollDice()) + (attackDie2->rollDice()));
}
void HarryPotter::defense(int attackRating)
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
        if (firstLife)
        {
            strengthRating = 20;
            firstLife = false;
        }
        else
        {
            strengthRating = 0;
            alive = false;
        }
    }
    else
    {
        cout << "Round Result  : " << roundResult << endl;
        strengthRating -= roundResult;
    }
}

HarryPotter::~HarryPotter()
{
    delete attackDie1;
    delete attackDie2;
    delete defenseDie1;
    delete defenseDie2;
}
