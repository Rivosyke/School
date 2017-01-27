/*********************************************************************
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This is the implementation file for the Game class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "utility.hpp"
#include <iostream>

using std::cout;
using std::endl;



/*********************************************************************
** Description: This constructor first seed the random number generator,
** clear the screen and then will ask the user a series of questions
** whose responses will be used to set the private data members. Input
** validation is used to ensure appropriate values are used.
*********************************************************************/
Game::Game()
{
	seedRN();
    clearScreen();

	player1Sides = 0;
	player2Sides = 0;
    player1DieType = 0;
    player2DieType = 0;
	player1Score = 0;
    player2Score = 0;
    
	cout << "Enter number of rounds to play: ";
    roundsToPlay = getInt();
    
    while (roundsToPlay < 1)
    {
        cout << endl << "Please enter a number greater than 0: ";
        roundsToPlay = getInt();
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
      
    if (player1DieType == 1)
    {
        player1Die = new Die(player1Sides);
    }
    else
    {
        player1Die = new LoadedDie(player1Sides);
    }
    
    if (player2DieType == 1)
    {
        player2Die = new Die(player2Sides);
    }
    else
    {
        player2Die = new LoadedDie(player2Sides);
    }
    
    play();
}

/*********************************************************************
** Description: This function is the primary control of the class. It
** will clear the screen and then do a for loop controlled by the 
** roundsToPlay variable. Each iteration of the loop will call round(),
** which determines the "meat" of the class.
*********************************************************************/
void Game::play()
{
    clearScreen();
    for (int x = 0; x < roundsToPlay; x++)
    {
        round();
    }
    results();
}    


/*********************************************************************
** Description: This function will call the player's rollDice function
** in order to get their rolls for that round. Depending on the results
** of the rolls, the player's scores will be updated or it's a draw.
*********************************************************************/
void Game::round()
{
    int p1Roll = player1Die->rollDice();
    int p2Roll = player2Die->rollDice();
    
    cout << endl << "Player 1 dice roll: " << p1Roll << endl;
    cout << "Player 2 dice roll: " << p2Roll << endl;
    
    if (p1Roll > p2Roll)
    {
        cout << "The winner of the round is player #1!" << endl;
        player1Score++;
    }
    else if (p2Roll > p1Roll)
    {
        cout << "The winner of the round is player #2!" << endl;
        player2Score++;
    }
    else
    {
        cout << "Both players rolled the same number; it's a draw!" << endl;
    }
    sleep(.8);
 
}

/*********************************************************************
** Description: This function will check which player won or if the
** scores are tied. Depending on the result, it will output an 
** appropriate message.
*********************************************************************/
void Game::results()
{
    cout << endl << "***************************************************" << endl;
    cout << "Player 1 score: " << player1Score << endl;
    cout << "Player 1 sides: " << player1Sides << endl;
    if (player1DieType == 1)
    {
		cout << "Player 1 die  : Regular" << endl;
	}
	else
	{
		cout << "Player 1 die  : Loaded" << endl;
    }
    
    cout << endl;
	cout << "Player 2 score: " << player2Score << endl;
    cout << "Player 2 sides: " << player2Sides << endl;
    if (player2DieType == 1)
    {
		cout << "Player 2 die  : Regular" << endl;
	}
	else
	{
		cout << "Player 2 die  : Loaded" << endl;
    }

    cout << endl << "***************************************************" << endl;
    
    if (player1Score > player2Score)
    {
		cout << "Player #1 is the winner!" << endl;
    }
    else if (player2Score > player1Score)
    {
		cout << "Player #2 is the winner!" << endl;
    }
    else
    {
        cout << "The game is a tie!" << endl;
    }
}
    
    
/*********************************************************************
** Description: This destructor will delete the dynamically allocated
** Die objects. 
*********************************************************************/
Game::~Game()
{
    delete player1Die;
    player1Die = nullptr;
    delete player2Die;
    player2Die = nullptr;
}
