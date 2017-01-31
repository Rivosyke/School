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
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::fixed;


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
	cout << "Item name     : " << itemName << endl;
	cout << fixed << setprecision(2) << "Item price    : $" << itemPrice << endl;
	cout << "Item qty      : " << itemQuantity << " " << unitType << endl;
    cout << fixed << setprecision(2) << "Extended Price: $" << extendedPrice() << endl;
}

string Item::getName()
{
    return itemName;
}
