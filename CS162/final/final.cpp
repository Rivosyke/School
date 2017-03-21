/*********************************************************************
** Program Name: Final Project
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This program will play a game called "Escape the Black
** Hole". It will prompt the player to go through a series of rooms,
** perform a series of actions, and get items to fix a ship. The player
** has a set amount of time to perform all these actions before the
** ship drifts past the event horizon and dies.
*********************************************************************/

#include "Game.hpp"


/*********************************************************************
** Running Instruction: This program doesn't use any command-line 
** arguments and is executed on the command line using the executable's
** name.
*********************************************************************/

int main()
{
    
    Game game;
    game.play();
   
    return 0;
}
