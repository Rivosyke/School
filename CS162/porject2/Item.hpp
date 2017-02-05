/*********************************************************************
** Author: Ryan McGinn
** Date: 05 February 2017
** Description: This is the specification file for the Item class.
** This class has four data members: two strings, an int, and a 
** double. This class represents one element in the grocery list.
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "utility.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::fixed;
using std::string;

class Item
{
	private:
		string itemName;
		string unitType;
		int itemQuantity;
		double itemPrice;
	public:
		Item(string name, string type, int quantity, double price);
		double extendedPrice();
		void displayItem();
        string getName();
        
};


#endif // ITEM_HPP
