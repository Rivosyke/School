/*********************************************************************
** Program Name: Project 3
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This program will pit 5 monster types against each 
** other. The user will choose types (including two of the same type)
** and then each monster will take turns attacking and defending. The
** monster that goes first is randomly decided. When the first monster
** has no more strength points, the fight is over. The user will then
** be told who won, how many rounds it took, and if they want to go
** again.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Creature.hpp"
#include "Die.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Queue.hpp"
#include "Vampire.hpp"
#include "utility.hpp"
#include <iostream>

class Game
{
	private:
		int blah;
	public:
		Game();
		~Game();
		void printMenu();
		Creature* monsterChoice(int choice);
		void menuFunctionality();
};

#endif // GAME_HPP



