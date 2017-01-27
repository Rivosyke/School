/*********************************************************************
** Program Name: Lab 3
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This program will play a game that uses two players
** and two different dice. The user will be prompted for some starting
** information (number of sides the die will have, how many rounds 
** will be played, and which type of die does each player have (regular
** or loaded). The game class will then be created, the dice will be
** rolled for the number of rounds specified, and a winner will be 
** declared.
*********************************************************************/

#include <iostream>
#include "LoadedDie.hpp"
#include "Die.hpp"
#include "Game.hpp"
#include "utility.hpp"


using std::cout;
using std::endl;

/*********************************************************************
** Description: This program will play a game that uses two players
** and two different dice. The user will be prompted for some starting
** information (number of sides the die will have, how many rounds 
** will be played, and which type of die does each player have (regular
** or loaded). The game class will then be created, the dice will be
** rolled for the number of rounds specified, and a winner will be 
** declared.
** Running Instruction: This program doesn't use any command-line 
** arguments and is executed on the command line using the executable's
** name.
*********************************************************************/

int main()
{
    seedRN();
    clearScreen();
    
    int rounds = 0;
    int player1Sides = 0;
    int player2Sides = 0;
    int player1DieType = 0;
    int player2DieType = 0;
    
    cout << "Enter number of rounds to play: ";
    rounds = getInt();
    
    while (rounds < 1)
    {
        cout << endl << "Please enter a number greater than 0: ";
        rounds = getInt();
    }
    
    cout << "Enter number of sides for player #1's die: ";
    player1Sides = getInt();
    
    while (player1Sides < 2)
    {
        cout << endl << "The die must have at least 2 sides. Try again: ";
        player1Sides = getInt();
    }
    
    cout << "Enter number of sides for player #2's die: ";
    player2Sides = getInt();
    
    while (player2Sides < 2)
    {
        cout << endl << "The die must have at least 2 sides. Try again: ";
        player2Sides = getInt();
    }
    
    cout << "Which type of die will player 1 use? Enter 1 for regular or 2 for loaded: ";
    player1DieType = getInt();
    
    while ((player1DieType != 1) && (player1DieType != 2))
    {
        cout << endl << "Valid options are 1 or 2. Try again: ";
        player1DieType = getInt();
    }
    
    cout << "Which type of die will player 2 use? Enter 1 for regular or 2 for loaded: ";
    player2DieType = getInt();
    
    while ((player2DieType != 1) && (player2DieType != 2))
    {
        cout << endl << "Valid options are 1 or 2. Try again: ";
        player2DieType = getInt();
    }
    
    
    Game game(player1Sides, player2Sides, rounds, player1DieType, player2DieType);
    
    return 0;
}
