/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the implementation file for the Barbarian class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Barbarian.hpp"


/*********************************************************************
** Description: Constructor that calls the Creature constructor and
** allocates the memory for the Die objects.
*********************************************************************/
Barbarian::Barbarian() : Creature(12, 0, "Barbarian")
{
    attackDie1 = new Die(6);
    attackDie2 = new Die(6);
    defenseDie1 = new Die(6);
    defenseDie2 = new Die(6);
}

/*********************************************************************
** Description: This method will return an int that contains the sum
** of rolling both attack die.
*********************************************************************/
int Barbarian::attack()
{
    return ((attackDie1->rollDice()) + (attackDie2->rollDice()));
}

/*********************************************************************
** Description: This method will take in the int that is the attack 
** roll and calculate if the attack was successful or not and update
** the strenthRating accordingly.
*********************************************************************/
void Barbarian::defense(int attackRating)
{
    cout << "Attack Rating : " << attackRating << endl;
    
    // Rolls both defense Die 
    int defenseRating = (defenseDie1->rollDice() + defenseDie2->rollDice());
    cout << "Defense Rating: " << defenseRating << endl;
    
    int roundResult;
	// Checks to see if the defense rolls combined with the armor is 
	// greater than the attack roll
    if ((attackRating - defenseRating) - armorRating <= 0 )
    {
        roundResult = 0;
    }
    else
    {
        roundResult = (attackRating - defenseRating) - armorRating;
    }
    
    // Checks to see if the attack kills the monster
    if ((strengthRating - roundResult) <= 0)
    {
        strengthRating = 0;
        alive = false;
    }
    else
    {
        cout << "Damage Dealt  : " << roundResult << endl;
        strengthRating -= roundResult;
    }
}

/*********************************************************************
** Description: Destructor that deletes the allocated Die objects
*********************************************************************/
Barbarian::~Barbarian()
{
    delete attackDie1;
    delete attackDie2;
    delete defenseDie1;
    delete defenseDie2;
}

