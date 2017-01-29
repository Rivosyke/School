/*********************************************************************
** Program Name: Lab 3
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This program will play a game that uses two players
** and two different dice. The user will be prompted for some starting
** information (number of sides the die will have, how many rounds 
** will be played, and which type of die does each player have (regular
** or loaded). The game class will then be created, the dice will be
** rolled for the number of rounds specified, and a winner will be 
** declared.
*********************************************************************/

#include "Item.hpp"
#include "utility.hpp"
#include <iostream>
#include "List.hpp"


using std::cout;
using std::endl;

/*********************************************************************
** Description: 
** Running Instruction: This program doesn't use any command-line 
** arguments and is executed on the command line using the executable's
** name.
*********************************************************************/


int main()
{
	
	Item soap("Zest Soap", "bar(s)", 2, 4.56);
	
	soap.displayItem();
	
	List list;
	list.addItem();
	
	return 0;
}
