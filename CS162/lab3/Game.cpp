#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "utility.hpp"
#include <iostream>

using namespace std;

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
}
    
void Game::play()
{
    clearScreen();
    for (int x = 0; x < roundsToPlay; x++)
    {
        round();
    }
    results();
}    
Game::~Game()
{
    delete player1Die;
    delete player2Die;
}

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
    
    

