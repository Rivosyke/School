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
    
    public:
        Game(int player1Sides, int player2Sides, int rounds, int player1Type, int player2Type);
        void play();
        ~Game();
        
}; 




#endif // GAME_HPP
