/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the implementation file for the Vampire class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Vampire.hpp"

/*********************************************************************
** Description: Constructor that calls the Creature constructor and
** allocates the memory for the Die objects.
*********************************************************************/
Vampire::Vampire() : Creature(18, 1, "Vampire")
{
    attackDie1 = new Die(12);
    defenseDie1 = new Die(6);
}

/*********************************************************************
** Description: This method will return an int that contains the roll
** of the attack Die.
*********************************************************************/
int Vampire::attack()
{
    return attackDie1->rollDice();
}

/*********************************************************************
** Description: This method will take in the int that is the attack 
** roll and calculate if the attack was successful or not and update
** the strenthRating accordingly.
*********************************************************************/
void Vampire::defense(int attackRating)
{
    // Special vampire ability that will get a random 0 or 1 to indicate the 
    // 50% chance to charm the attacker and take no damage
    if (randomNum(2) == 0)
    {
		int roundResult;
   //     cout << "Attack Rating : " << attackRating << endl;
        
        int defenseRating = defenseDie1->rollDice();
   //     cout << "Defense Rating: " << defenseRating << endl;
              
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
   //         cout << "Damage Dealt  : " << roundResult << endl;
            strengthRating -= roundResult;
        }
    }
    else
    {
    //    cout << "Charm Successful - No Damage!" << endl;
    }
    
}

/*********************************************************************
** Description: Destructor that deletes the allocated Die objects
*********************************************************************/
Vampire::~Vampire()
{
    delete attackDie1;
    delete defenseDie1;
}
