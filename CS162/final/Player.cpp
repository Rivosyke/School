/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the implementation file for the Player class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Player.hpp"

/*********************************************************************
** Description: Constructor that will set the pressure suit status
*********************************************************************/
Player::Player()
{
    hasPressureSuit = false;
}

/*********************************************************************
** Description: Constructor that will set the pressure suit status
*********************************************************************/
Player::~Player()
{
	for (unsigned int x = 0; x < suitInventory.size(); x++)
	{
		delete suitInventory.at(x);
		suitInventory.at(x) = nullptr;
	}
}
/*********************************************************************
** Description: Method that returns the whether or not the player
** is wearing the pressure suit.
*********************************************************************/ 
bool Player::pressureSuitEquipped()
{
    return hasPressureSuit;
}

/*********************************************************************
** Description: Method that prints the contents of the suit, if the
** suit is being worn and if it carrying anything
*********************************************************************/ 
void Player::printInventory()
{
    if (!hasPressureSuit)
    {
        printColor("You aren't wearing anything with pockets!\n",RED,BOLD);
    }
    else
    {
        printColor("******************************\n", RED, BOLD);
        printColor("Suit Inventory\n",CYAN,BOLD);
        if (suitInventory.size() == 0)
        {
            cout << " - The suit is empty!" << endl;
            cout << endl;
        }
        else
        {
            for (unsigned int x = 0; x < suitInventory.size(); x++)
            {
                cout << x + 1 << ") " << suitInventory.at(x) -> getName() << endl;
            }
            cout << endl;
        }
    }
}

/*********************************************************************
** Description: Method that returns a bool indicating the success or
** failure of adding an item to the suit's inventory.
*********************************************************************/ 
bool Player::pickUpItem(Item* newItem)
{
	if (!newItem)
	{
		return false;
	}
	else if (newItem -> getName() == "Pressure Suit")
	{
		printColor("You take the pressure suit out of the locker and put it on.\n",GREEN,BOLD);
		hasPressureSuit = true;
        delete newItem;
		return true;
	}
	/*
	else if (!hasPressureSuit)
    {
        cout << "You haven't put on the pressure suit yet and therefore have no "
             << "pockets with which to store this item." << endl;
        return false;
    }*/
    else
    {
		suitInventory.push_back(newItem);
		return true;
    }
}

/*********************************************************************
** Description: Method that takes in an int that represents the index
** that the item is at that needs to be returned to the caller.
*********************************************************************/
Item* Player::removeItem(int playerChoice)
{
	Item* temp = suitInventory.at(playerChoice - 1);
	suitInventory.erase(suitInventory.begin() + (playerChoice -1));
	return temp;
}

/*********************************************************************
** Description: Method that returns the size of the player's inventory.
*********************************************************************/
unsigned int Player::inventorySize()
{
    return suitInventory.size();
}

