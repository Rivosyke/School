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
	cout << endl << "Item price: ";
	cin >> tempPrice;
	
	groceryList[itemsUsed] = new Item(tempName, tempType, tempQty, tempPrice);
	itemsUsed++;
	
}

void List::deleteItem(Item& oldItem)
{
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
