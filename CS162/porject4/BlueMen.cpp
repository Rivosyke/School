/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the implementation file for the Blue Men class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "BlueMen.hpp"

/*********************************************************************
** Description: Constructor that calls the Creature constructor and
** allocates the memory for the Die objects.
*********************************************************************/
BlueMen::BlueMen() : Creature(12, 3, "Blue Men")
{
    attackDie1 = new Die(10);
    attackDie2 = new Die(10);
    defenseDie.push_back(new Die(6));
    defenseDie.push_back(new Die(6));
    defenseDie.push_back(new Die(6));
    firstDieLost = false;
    secondDieLost = false;
}

/*********************************************************************
** Description: This method will return an int that contains the sum
** of rolling both attack die.
*********************************************************************/
int BlueMen::attack()
{
    return ((attackDie1->rollDice()) + (attackDie2->rollDice()));
}

/*********************************************************************
** Description: This method will take in the int that is the attack 
** roll and calculate if the attack was successful or not and update
** the strenthRating accordingly. For every 4 points of damage, the
** Blue Men will lose one defense Die.
*********************************************************************/
void BlueMen::defense(int attackRating)
{
  //  cout << "Attack Rating : " << attackRating << endl;
    
    int defenseRating = 0;
    
    // rolls each defense die and sums it
    for (unsigned int x = 0; x < defenseDie.size(); x++)
    {
        defenseRating += defenseDie.at(x)->rollDice();
    }
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
 //       cout << "Damage Dealt  : " << roundResult << endl;
        strengthRating -= roundResult;
        
        // Checks to see if 4 points of damage have been dealt
        if (strengthRating <= 8 and strengthRating > 4 and !firstDieLost)
        {
            defenseDie.pop_back();
            firstDieLost = true;
        }
        // Checks to see if 4 points of damage have been dealt
        else if (strengthRating <= 4 and strengthRating > 0 and !secondDieLost)
        {
            defenseDie.pop_back();
            secondDieLost = true;
        }
  //      cout << "Defense Die   : " << defenseDie.size() << endl;
    }
}

/*********************************************************************
** Description: Destructor that deletes the allocated Die objects
*********************************************************************/
BlueMen::~BlueMen()
{
    delete attackDie1;
    delete attackDie2;
}
