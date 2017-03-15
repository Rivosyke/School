/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the Item class.
** This class has one data member: a string that is the name. 
*********************************************************************/

#include <string>

using std::string;

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
    private:
        string name;
    public:
        Item(string);
        string getName();
};

#endif // ITEM_HPP
