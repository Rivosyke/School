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
#include <string>

using namespace std;


Item::Item(string name, string type, int quantity, double price)
{
	itemName = name;
	unitType = type;
	itemQuantity = quantity;
	itemPrice = price;
}

double Item::extendedPrice()
{
	return itemQuantity * itemPrice;
}


void Item::displayItem()
{
	cout << endl;
	cout << "Item name : " << itemName << endl;
	cout << "Item price: " << itemPrice << endl;
	cout << "Item qty  : " << itemQuantity << " " << unitType << endl;
}
