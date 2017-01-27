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
** Description: This constructor will take the passed in values 
** and assign them to the appropriate data members. The player type
** ints will be used to determine which type of die that player will
** use and the player scores will be set to 0.
*********************************************************************/
Game::Game(int player1Sides, int player2Sides, int rounds, int player1Type, int player2Type)
{
    
    if (player1Type == 1)
    {
        player1Die = new Die(player1Sides);
    }
    else
    {
        player1Die = new LoadedDie(player1Sides);
    }
    
    if (player2Type == 1)
    {
        player2Die = new Die(player2Sides);
    }
    else
    {
        player2Die = new LoadedDie(player2Sides);
    }
    
    player1Score = 0;
    player2Score = 0;
    roundsToPlay = rounds;
    
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
    
    if (player1Score > player2Score)
    {
        cout << "The winner is player #1 with a score of " << player1Score << "!" << endl;
    }
    else if (player2Score > player1Score)
    {
        cout << "The winner is player #2 with a score of " << player2Score << "!" << endl;
    }
    else
    {
        cout << "The game is a tie!";
    }
}
    
    
/*********************************************************************
** Description: This destructor will delete the dynamically allocated
** Die objects. 
*********************************************************************/
Game::~Game()
{
    delete player1Die;
    delete player2Die;
}
