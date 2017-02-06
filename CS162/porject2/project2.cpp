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
void addItemInput(List* tempList);

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

/*********************************************************************
** Description: This constructor takes in a string and assigns it to
** the name data member.
*********************************************************************/
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
                addItemInput(list);
                break;
            case 3:
                cout << "Enter item name to delete: ";
                getline(cin, userString);
                if (!(list->deleteItem(userString)))
                {
                    cout << endl << "Item not found in the list" << endl;
					pauseScreen();
                }
                else
                {
					cout << "Item successfully deleted. " << endl;
					pauseScreen();
				}
                break;
            case 4:
                break;
        }
        
    } while (userInput != 4);
}

/*********************************************************************
** Description: This constructor takes in a string and assigns it to
** the name data member.
*********************************************************************/
void addItemInput(List* tempList)
{
	string tempName;
	string tempType;
	int tempQty;
	double tempPrice;
	bool itemExists = false;
	
	do
	{
		cout << "******* New Item Input *******";
		cout << endl << "Item Name : ";
		getline(cin, tempName);
	
		if (*tempList == tempName)
		{
			itemExists = true;
			cout << "Item already exists in the cart, please enter a new item" << endl;
		}
		else
		{
			itemExists = false;
		}
	} while (itemExists);
	
    
	cout << "Item type : ";
	getline(cin, tempType);
    
	cout << "Item qty  : ";
	tempQty = getInt();
    while (tempQty < 1)
    {
        cout << "Error - Quantity to order must be at least 1" << endl;
        cout << "Item qty   :";
        tempQty = getInt();
    }
    
	cout << "Item price: ";
	tempPrice = getDouble();
    while (tempPrice < 0.01)
    {
        cout << "Error - cost of the item must be at least $0.01" << endl;
        cout << "Item Price:";
        tempPrice = getDouble();
    }
    
    tempList->addItem(tempName, tempType, tempQty, tempPrice);
    cout << "Item successfully added. " << endl;
    pauseScreen();
    clearScreen();
    
}
