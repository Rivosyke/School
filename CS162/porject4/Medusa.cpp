/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the implementation file for the Medusa class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Medusa.hpp"

/*********************************************************************
** Description: Constructor that calls the Creature constructor and
** allocates the memory for the Die objects.
*********************************************************************/
Medusa::Medusa() : Creature(8, 3, "Medusa")
{
    attackDie1 = new Die(6);
    attackDie2 = new Die(6);
    defenseDie1 = new Die(6);
}

/*********************************************************************
** Description: This method will return an int that contains the sum
** of rolling both attack die. If the sum is 12, the glare attack is
** successful and a value of 9999 is returned.
*********************************************************************/
int Medusa::attack()
{
    int attackRoll = attackDie1->rollDice() + attackDie2->rollDice();
    const int glareAttack = 9999;
    
    if (attackRoll == 12)
    {
        return glareAttack;
    }
    else
    {
        return attackRoll;
    }
    
}

/*********************************************************************
** Description: This method will take in the int that is the attack 
** roll and calculate if the attack was successful or not and update
** the strenthRating accordingly.
*********************************************************************/
void Medusa::defense(int attackRating)
{

 //   cout << "Attack Rating : " << attackRating << endl;
    int defenseRating = defenseDie1->rollDice();
 //   cout << "Defense Rating: " << defenseRating << endl;
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
  //      cout << "Damage Dealt  : " << roundResult << endl;
        strengthRating -= roundResult;
    }
}

/*********************************************************************
** Description: Destructor that deletes the allocated Die objects
*********************************************************************/
Medusa::~Medusa()
{
    delete attackDie1;
    delete attackDie2;
    delete defenseDie1;
}
