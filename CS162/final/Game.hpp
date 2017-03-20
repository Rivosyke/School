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
#include "CommonRoom.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "utility.hpp"
#include "Engineering.hpp"


#ifndef GAME_HPP
#define GAME_HPP

class Game
{
    private:
		bool loopGame;
		bool playerWins;
		int moveCount;
        Player player;
        Corridor* southCorridor;
        Corridor* northCorridor;
        Corridor* westCorridor;
        Corridor* eastCorridor;
        CryoChamber* cryoRoom;
        StorageRoom* storageRoom;
        Space* currentRoom;
        CommonRoom* commonArea;
        Cockpit* cockpit;
        Airlock* airlock;
        CargoHold* cargoHold;
        O2Room* o2Room;
        Engineering* engineering;
        void printBanner();
        void printGameDesc();
        void printStartingScene();
        void primaryDecisionLoop();
        void printUserInputMenu();
        void changeRooms();
        void useItem();
        void getItemFromRoom();
        void performSpecialAction();
        void gameResults();
        

    public:
        Game();
        ~Game();
        void play();
};
        

#endif // GAME_HPP
