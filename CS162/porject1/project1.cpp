#include "ant.hpp"
#include "utility.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include "board.hpp"

using namespace std;

int main()
{
    system("clear");
    int boardSize = 0;

    cout << "Number of rows and columns: ";
    cin >> boardSize;
    
    Ant* ant = new Ant(boardSize/2, boardSize/2);
    
    Board* board = new Board(boardSize);
       
    int moves = 0;
    
    while (moves <= 1)
    {
        system("clear");
        board->displayBoard(ant);
        board->makeMove(ant);
        moves++;
        usleep(90000);
    }
    
   // delete ant;
   // delete board;
    
    
    return 0;
}
