/*********************************************************************
** Program Name: Project 4
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

#include "Game.hpp"

/*********************************************************************
** Running Instruction: This program doesn't use any command-line 
** arguments and is executed on the command line using the executable's
** name.
*********************************************************************/
int main()
{
	Game monsterTourney;
	
	monsterTourney.play();
	
	return 0;
}
