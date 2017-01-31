/*********************************************************************
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This is the implementation file for the Game class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Item.hpp"
#include "utility.hpp"
#include <iostream>
#include "List.hpp"

#include <string>

using namespace std;

List::List()
{
	listSize = 4;
	groceryList = new Item*[listSize];
	itemsUsed= 0;
}
List::~List()
{
    for (int x = 0; x < listSize; x++)
    {
        delete groceryList[x];
        groceryList[x] = nullptr;
    }
	delete [] groceryList;
}
void List::addItem()
{
	string tempName;
	string tempType;
	int tempQty;
	double tempPrice;
	
	if (itemsUsed == listSize)
	{
		expandArray();
	}
	
	cout << "******* New Item Input *******";
	cout << endl << "Item Name : ";
	getline(cin, tempName);
    
	cout << endl << "Item type : ";
	getline(cin, tempType);
    
	cout << endl << "Item qty  : ";
	tempQty = getInt();
    while (tempQty < 1)
    {
        cout << "Error - Quantity to order must be at least 1" << endl;
        cout << "Item qty   :";
        tempQty = getInt();
    }
    
	cout << endl << "Item price: ";
	tempPrice = getDouble();
    while (tempPrice < 0.01)
    {
        cout << "Error - cost of the item must be at least $0.01" << endl;
        cout << "Item Price:";
        tempPrice = getDouble();
    }
	
	groceryList[itemsUsed] = new Item(tempName, tempType, tempQty, tempPrice);
	itemsUsed++;
	
}

void List::addItem(Item* newItem)
{
    if (itemsUsed == listSize)
	{
		expandArray();
	}
    
    groceryList[itemsUsed] = newItem;
    itemsUsed++;
}

bool List::deleteItem(string searchTerm)
{
    bool foundValue = false;
    int itemPos = 0;
    
    for (int x = 0; x < itemsUsed; x++)
    {
        if (groceryList[x]->getName() == searchTerm)
        {
            itemPos = x;
            foundValue = true;
        }
    }
    if (!foundValue)
    {
        return false;
    }
    delete groceryList[itemPos];
    
    for (int x = itemPos; x < itemsUsed; x++)
    {
        groceryList[x] = groceryList[x+1];
    }
    itemsUsed--;
    return true;
    
}
void List::expandArray()
{
	Item** tempArray = new Item*[listSize+4];
	
	for (int x = 0; x < itemsUsed; x++)
	{
		tempArray[x] = groceryList[x];
	}
	
	delete []groceryList;
	
	listSize += 4;
	groceryList = tempArray;
	tempArray = nullptr;

}

void List::printList()
{
    double totalPrice = 0;
    //clearScreen();
    cout << "Current contents of the grocery list:" << endl;
    cout << "**************************************" << endl;
    
    if (itemsUsed == 0)
    {
        cout << "There are no items in the list." << endl;
    }
    else
    {
        for (int x = 0; x < itemsUsed; x++)
        {
            cout << endl << "Item # " << x + 1;
            groceryList[x]->displayItem();
            totalPrice += groceryList[x]->extendedPrice();
        }
    }
    cout << "**************************************" << endl;
    cout << "Total items in the cart: " << itemsUsed << endl;
    cout << "Total cost of all items: $" << totalPrice << endl;
}
