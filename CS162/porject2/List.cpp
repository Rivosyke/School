/*********************************************************************
** Author: Ryan McGinn
** Date: 05 February 2017
** Description: This is the implementation file for the List class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "utility.hpp"
#include <iostream>
#include "List.hpp"


/*********************************************************************
** Description: This constructor takes no arguments and initializes 
** the array of Item pointers to the listSize of 4.
*********************************************************************/
List::List()
{
	listSize = 4;
	groceryList = new Item*[listSize];
    for (int x = 0; x < listSize; x++)
    {
        groceryList[x] = nullptr;
    }
	itemsUsed= 0;
}

/*********************************************************************
** Description: This destructor will iterate through the array and
** delete all the allocated items.
*********************************************************************/
List::~List()
{
    if (listSize != 0)
    {
        for (int x = 0; x < listSize; x++)
        {
            delete groceryList[x];
            groceryList[x] = nullptr;
        }
    }
	delete [] groceryList;
    groceryList = nullptr;
}

/*********************************************************************
** Description: This function will take in all the data members needed
** for an item object. If the number of items in the array is the same
** as the size of the array capacity, it will call the expandArray 
** method.
*********************************************************************/
void List::addItem(string tempName, string tempType, int tempQty, double tempPrice)
{	
	// Checks to see if the array is full
	if (itemsUsed == listSize)
	{
		expandArray();
	}

	groceryList[itemsUsed] = new Item(tempName, tempType, tempQty, tempPrice);
	itemsUsed++;
	
}

/*********************************************************************
** Description: This function takes in a pointer to an Item and adds
** it to the list. The function also checks to see if the list is at
** capacity. 
*********************************************************************/
void List::addItem(Item* newItem)
{
	// Checks to see if the array is full
    if (itemsUsed == listSize)
	{
		expandArray();
	}
    
    groceryList[itemsUsed] = newItem;
    itemsUsed++;
}

/*********************************************************************
** Description: This function will take in a string and iterate through
** the array looking for that search string. If the value is found,
** the position of the item is marked, that item will be deleted, and
** all other items above that position will be shifted down one
** position. If the item is not found, a value of false is returned.
*********************************************************************/
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

/*********************************************************************
** Description: This function will expand the array size by four.
*********************************************************************/
void List::expandArray()
{
	// Creates an array that is 4 larger than the existing array
	Item** tempArray = new Item*[listSize+4];
    for (int x = 0; x < listSize + 4; x++)
    {
        tempArray[x] = nullptr;
    }
	
	// Iterates through and assigns the existing values to the new array
	for (int x = 0; x < itemsUsed; x++)
	{
		tempArray[x] = groceryList[x];
	}
	
	// Deletes the 
	delete []groceryList;
	
	listSize += 4;
	groceryList = tempArray;
	tempArray = nullptr;
    delete [] tempArray;

}

/*********************************************************************
** Description: This function will output the contents of the list.
*********************************************************************/
void List::printList()
{
    double totalPrice = 0;
    clearScreen();
    cout << "Current contents of the grocery list:" << endl;
    cout << "**************************************" << endl;
    
    if (itemsUsed == 0)
    {
        cout << "There are no items in the list." << endl;
    }
    else
    {
		// Iterates through the array and outputs the list and 
		// totals up the price of all items in the list
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
    cout << endl;
}

/*********************************************************************
** Description: This function overloads the == relational operator. It
** checks to see if the passed in searchTerm is found in any of the list's
** Item objects.
*********************************************************************/
bool List::operator== (const string searchTerm)
{	
	for (int x = 0; x < itemsUsed; x++)
	{
		if ((groceryList[x]->getName()) == searchTerm)
		{
			return true;
		}
	}
	return false;
	
}
