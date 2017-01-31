/*********************************************************************
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This is the specification file for the Die class.
** This class has one data member: an int to hold the number of sides
** that the Die will have. Input validation in main() will ensure
** that the number will be greater than 1.
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

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
