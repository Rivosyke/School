/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the Item class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Item.hpp"

/*********************************************************************
** Description: Constructor that will take in a string and set the 
** name data member to the passed in value.
*********************************************************************/
Item::Item(string tempName)
{
    name = tempName;
}

/*********************************************************************
** Description: Method that returns the name data member.
*********************************************************************/ 
string Item::getName()
{
    return name;
}
