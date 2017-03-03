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
#include "CreatureList.hpp"

using namespace std;

class Game
{
	private:
		int playerOneWins;
		int playerTwoWins;
		CreatureList playerOneFighters;
		CreatureList playerTwoFighters;
		CreatureList playerOneLosers;
		CreatureList playerTwoLosers;
		void printInitialMenu();
		void monsterInput(int playerNum, int monsterNum);
		void printMonsters();
		Creature* monsterChoice(int choice);
		void monsterFighting();
		void winner();
		
	public:
		Game();
	//	~Game();
		void play();
};

#endif // GAME_HPP




