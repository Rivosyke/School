#include "board.hpp"
#include <iostream>
#include "ant.hpp"

using namespace std;

Board::Board(int size)
{
	boardSize = size;
	board = new char*[boardSize];
	
	for (int x = 0; x < boardSize; x++)
    {
        board[x] = new char[boardSize];
    }
    
    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
        {
            board[row][col] = ' ';
        }
    }    
}

void Board::displayBoard(Ant* ant)
{
    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
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

void Board::makeMove(Ant* ant)
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
	


Board::~Board()
{
	for (int x = 0; x < boardSize; x++)
	{
		delete board[x];
	}
	delete board;
}
