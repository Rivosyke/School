/*********************************************************************
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This is the specification file for the Die class.
** This class has one data member: an int to hold the number of sides
** that the Die will have. Input validation in main() will ensure
** that the number will be greater than 1.
*********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include "Item.hpp"

using std::string;

class List
{
	private:
		Item** groceryList;
		int listSize;
		int itemsUsed;
	public:
		List();
		~List();
		void addItem();
        void addItem(Item*);
		bool deleteItem(string searchTerm);
		void expandArray();
        void printList();
		
};



#endif // LIST_HPP
