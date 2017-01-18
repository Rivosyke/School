#include "ant.hpp"
#include "utility.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void displayBoard(Ant* ant, char** board, int size);

void fillBoard(Ant* ant, char** board, int size);

void makeMove (char** board, Ant* ant);


int main()
{
    system("clear");
    int boardSize = 0;

    cout << "Number of rows and columns: ";
    cin >> boardSize;
    
    Ant* ant = new Ant(boardSize/2, boardSize/2);
    
    char **board = new char*[boardSize];

    for (int x = 0; x < boardSize; x++)
    {
        board[x] = new char[boardSize];
    }
    
    fillBoard(ant, board, boardSize);
    
     
    int moves = 0;
    
    while (moves <= 600)
    {
        system("clear");
        displayBoard(ant, board, boardSize);
        makeMove(board, ant);
        moves++;
        usleep(90000);
    }
    
    delete ant;
    delete board;
    
    
    return 0;
}


void displayBoard(Ant* ant, char** board, int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
			if ((col == ant->getColCoord()) && (row == ant->getRowCoord()))
			{
				cout << "*";
			}
            else
            {
				cout << board[row][col];
			}
        }
        cout << endl;
    }
}


void fillBoard(Ant* ant, char** board, int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            board[row][col] = ' ';
        }
    }
}
    
    
void makeMove (char** board, Ant* ant)
{
    if (board[ant->getRowCoord()][ant->getColCoord()] == ' ')
    {
        board[ant->getRowCoord()][ant->getColCoord()] = '#';
        
        switch(ant->getDirection())
        {
            case Up: 
                ant->setDirection(Right);
                ant->setColCoord(ant->getColCoord() + 1);
                break;
            case Right:
                ant->setDirection(Down);
                ant->setRowCoord(ant->getRowCoord() + 1);
                break;
            case Left:
                ant->setDirection(Up);
                ant->setRowCoord(ant->getRowCoord() - 1);
                break;
            case Down:
                ant->setDirection(Left);
                ant->setColCoord(ant->getColCoord() - 1);
                break;
        }
    }
    else
    {
        board[ant->getRowCoord()][ant->getColCoord()] = ' ';
        
        switch(ant->getDirection())
        {
            case Up: 
                ant->setDirection(Left);
                ant->setColCoord(ant->getColCoord() - 1);
                break;
            case Right:
                ant->setDirection(Up);
                ant->setRowCoord(ant->getRowCoord() - 1);
                break;
            case Left:
                ant->setDirection(Down);
                ant->setRowCoord(ant->getRowCoord() + 1);
                break;
            case Down:
                ant->setDirection(Right);
                ant->setColCoord(ant->getColCoord() + 1);
                break;
        }
    }
}   
