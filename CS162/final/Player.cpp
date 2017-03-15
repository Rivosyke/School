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
        cout << "You aren't wearing the pressure suit so you have no inventory." << endl;
    }
    else
    {
        cout << "*************************" << endl;
        cout << "Suit Inventory" << endl;
        if (suitInventory.size() == 0)
        {
            cout << " - The suit is empty!" << endl;
        }
        else
        {
            for (unsigned int x = 0; x < suitInventory.size(); x++)
            {
                cout << x + 1 << ") " << suitInventory.at(x) -> getName() << endl;
            }
        }
    }
}

/*********************************************************************
** Description: Method that returns a bool indicating the success or
** failure of adding an item to the suit's inventory.
*********************************************************************/ 
bool Player::pickUpItem(Item* newItem)
{
    if (!hasPressureSuit)
    {
        cout << "You haven't put on the pressure suit yet and therefore have no "
             << "pockets with which to store this item." << endl;
        return false;
    }
    else
    {
        if (newItem)
        {
            suitInventory.push_back(newItem);
            return true;
        }
        else
        {
            return false;
        }
    }
}

/*********************************************************************
** Description: Method that returns false if the player is already
** wearing the pressure suit and if not, sets the pressure suit status
** to true and returns true.
*********************************************************************/ 
bool Player::putOnPressureSuit()
{
    if (hasPressureSuit)
    {
        return false;
    }
    else
    {
        hasPressureSuit = true;
        return true;
    }
}
