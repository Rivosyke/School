/*********************************************************************
** Author: Ryan McGinn
** Date: 05 February 2017
** Description: This is the specification file for the List class.
** This class has three data members: an array of pointers to Items,
** and int to represent the total size of the array, and an int to
** represent the amount of items used in the array. There are various
** methods that perform operations on the array.
*********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include "Item.hpp"


using std::string;
using std::cout;
using std::endl;


class List
{
	private:
		Item** groceryList;
		int listSize;
		int itemsUsed;
	public:
		List();
		~List();
		void addItem(string tempName, string tempType, int tempQty, double tempPrice);
        void addItem(Item*);
		bool deleteItem(string searchTerm);
		void expandArray();
        void printList();
        bool operator== (const string searchTerm);
		
};



#endif // LIST_HPP
