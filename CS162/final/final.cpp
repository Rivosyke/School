#include "Space.hpp"
#include "utility.hpp"
#include <iostream>
#include "Player.hpp"
#include "Item.hpp"

//using namespace std;

int main()
{
    Player player;
    
    player.putOnPressureSuit();
    player.printInventory();
    
    player.pickUpItem(new Item("Flashlight"));
    player.pickUpItem(new Item("Medpack"));
    player.pickUpItem(new Item("Catalyst"));
    player.pickUpItem(new Item("EM Field Regulator"));
    
    player.printInventory();
    
    return 0;
}
