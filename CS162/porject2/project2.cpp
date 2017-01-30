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
	List list;
    
	Item* soap = new Item("Zest Soap", "bar(s)", 2, 4.56);
	Item* protein = new Item("Protein Bars", "bar(s)", 12, 1.79);
    Item* lego = new Item("Legos", "box(s)", 5, 54.30);
    Item* bath = new Item("Bath Salts", "ounce(s)", 20, 2.90);
    Item* tissue = new Item("Tissue", "packet(s)", 15, 4.99);
    
	list.addItem(soap);
    list.addItem(protein);
    list.addItem(lego);
    list.addItem(bath);
    list.addItem(tissue);
    
	
	
    list.printList();

	
	return 0;
}
