/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the Game class.
** This class has two data members: two pointers to Die objects that 
** represent attack and defense die. It inherits other data members
** and methods from the Creature super class.
*********************************************************************/

#include "Space.hpp"
#include "Cockpit.hpp"
#include "CryoChamber.hpp"
#include "Corridor.hpp"
#include "Airlock.hpp"
#include "CargoHold.hpp"
#include "O2Room.hpp"
#include "StorageRoom.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "utility.hpp"


#ifndef GAME_HPP
#define GAME_HPP

class Game
{
    private:
        Player player;
        CryoChamber* cryoRoom;
        Space* currentRoom;
        void printBanner();
        void printGameDesc();
        void printStartingScene();
        void primaryDecisionLoop();
        void printUserInputMenu();

    public:
        Game();
        ~Game();
        void play();
};
        

#endif // GAME_HPP
