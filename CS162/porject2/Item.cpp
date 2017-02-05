/*********************************************************************
** Author: Ryan McGinn
** Date: 05 February 2017
** Description: This is the implementation file for the Item class.
** It contains the function definitions and a constructor.
*********************************************************************/

#include "Item.hpp"

/*********************************************************************
** Description: This constructor takes two strings, an int, and a 
** double and assigns them to the appropriate values.
*********************************************************************/
Item::Item(string name, string type, int quantity, double price)
{
	itemName = name;
	unitType = type;
	itemQuantity = quantity;
	itemPrice = price;
}

/*********************************************************************
** Description: This function returns the quantity times the price.
*********************************************************************/
double Item::extendedPrice()
{
	return itemQuantity * itemPrice;
}

/*********************************************************************
** Description: This function displays the pertinent information
** for the item.
*********************************************************************/
void Item::displayItem()
{
	cout << endl;
	cout << "Item name     : " << itemName << endl;
	cout << fixed << setprecision(2) << "Item price    : $" << itemPrice << endl;
	cout << "Item qty      : " << itemQuantity << " " << unitType << endl;
    cout << fixed << setprecision(2) << "Extended Price: $" << extendedPrice() << endl;
}

/*********************************************************************
** Description: This function returns the name of the item.
*********************************************************************/
string Item::getName()
{
    return itemName;
}
