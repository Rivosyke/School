/*********************************************************************
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This is the specification file for the Game class.
** This class has five data members: two Die pointers, two ints to
** represent the player's scores, and an int for the number of rounds
** to play. 
*********************************************************************/

#include "Die.hpp"
#include "LoadedDie.hpp"

#ifndef GAME_HPP
#define GAME_HPP


class Game
{
    private:
        Die* player1Die;
        Die* player2Die;
        int player1Score;
        int player2Score;
        int roundsToPlay;
        void round();
        void results();
        void play();
    
    public:
        Game(int player1Sides, int player2Sides, int rounds, int player1Type, int player2Type);
        ~Game();
        
}; 

#endif // GAME_HPP
