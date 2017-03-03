/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the implementation file for the Harry Potter 
** class. It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "HarryPotter.hpp"

/*********************************************************************
** Description: Constructor that calls the Creature constructor and
** allocates the memory for the Die objects.
*********************************************************************/
HarryPotter::HarryPotter() : Creature(10, 0, "Harry Potter")
{
    attackDie1 = new Die(6);
    attackDie2 = new Die(6);
    defenseDie1 = new Die(6);
    defenseDie2 = new Die(6);
    firstLife = true;
}

/*********************************************************************
** Description: This method will return an int that contains the sum
** of rolling both attack die.
*********************************************************************/
int HarryPotter::attack()
{
    return ((attackDie1->rollDice()) + (attackDie2->rollDice()));
}

/*********************************************************************
** Description: This method will take in the int that is the attack 
** roll and calculate if the attack was successful or not and update
** the strenthRating accordingly. Additionally, when Harry dies the 
** first time, he gets resurrected with an HP of 20.
*********************************************************************/
void HarryPotter::defense(int attackRating)
{
 //   cout << "Attack Rating : " << attackRating << endl;
    
     // rolls each defense die and sums it
    int defenseRating = (defenseDie1->rollDice() + defenseDie2->rollDice());
  //  cout << "Defense Rating: " << defenseRating << endl;
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
        if (firstLife)
        {
	//		cout << "Harry Potter's brought back to life!" << endl;
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
   //     cout << "Damage Dealt  : " << roundResult << endl;
        strengthRating -= roundResult;
    }
}

/*********************************************************************
** Description: Destructor that deletes the allocated Die objects
*********************************************************************/
HarryPotter::~HarryPotter()
{
    delete attackDie1;
    delete attackDie2;
    delete defenseDie1;
    delete defenseDie2;
}
