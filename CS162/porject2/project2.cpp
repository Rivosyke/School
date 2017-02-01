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
using std::cin;

/*********************************************************************
** Description: 
** Running Instruction: This program doesn't use any command-line 
** arguments and is executed on the command line using the executable's
** name.
*********************************************************************/

void listOperations(List *list);

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
   
	listOperations(&list);
    
	return 0;
}

void listOperations(List *list)
{
    
    int userInput;
    string userString;
    do
    {
        cout << "1) Print List" << endl;
        cout << "2) Add Item" << endl;
        cout << "3) Delete Item" << endl;
        cout << "4) Exit" << endl;
        cout << "User Input: ";
    
        userInput = getInt();
    
        while ((userInput < 1) || (userInput > 4))
        {
            cout << endl << "Choice is not valid: Please choose 1-4.";
            cout << endl << "Choice: ";
            userInput = getInt();
        }
        
        switch (userInput)
        {
            case 1:
                list->printList();
                break;
            case 2:
                list->addItem();
                break;
            case 3:
                cout << "Enter item name to delete: ";
                getline(cin, userString);
                if (!(list->deleteItem(userString)))
                {
                    cout << endl << "Item not found in the list" << endl;
                }
                break;
            case 4:
                break;
        }
        
    } while (userInput != 4);
}
