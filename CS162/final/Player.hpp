/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the Player class.
** This class has two data members: two pointers to Die objects that 
** represent attack and defense die. It inherits other data members
** and methods from the Creature super class.
*********************************************************************/

#include <vector>
#include <iostream>
#include "Item.hpp"
#include <string>
#include "utility.hpp"

using std::string;
using std::cout;
using std::endl;
using std::vector;

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
    private:
        bool hasPressureSuit;
        vector<Item*> suitInventory;
        
    public:
        Player();
        ~Player();
        bool pressureSuitEquipped();
        void printInventory();
        bool pickUpItem(Item* newItem);
        //bool putOnPressureSuit();
        Item* removeItem(int playerChoice);
};

#endif // PLAYER_HPP
