/*********************************************************************
** Program Name: Lab 5
** Author: Ryan McGinn
** Date: 09 February 2017
** Description: This program will output a menu that gives the user
** four different options: 1) Reverse a String, 2) Sum an array of ints,
** 3) Calculate a Triangular Number, 4) Exit.
*********************************************************************/

#include <iostream>
#include "utility.hpp"
#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"




using namespace std;


/*********************************************************************
** Running Instruction: This program doesn't use any command-line 
** arguments and is executed on the command line using the executable's
** name.
*********************************************************************/
int main()
{
    seedRN();
    Creature* b1 = new Medusa();
    Creature* b2 = new HarryPotter();
    
    int rounds = 0;
    
    while (b2->living())
    {
        b2->defense(b1->attack());
        cout << "Str rating    : " << b2->getStr() << endl;
        rounds++;
        cout << endl;
    }
    
    cout << endl << "It took " << rounds << " rounds." << endl;

	return 0;
}

