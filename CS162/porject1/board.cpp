/*********************************************************************
** Program name: Lab 1
** Author: Ryan McGinn
** Date: 14 January 2017
** Description: This program will ask the user to choose a 2x2 or a 
** 3x3 matrix and then fill the matrix with integers. Once the user
** is done filling in the integers, the matrix will be displayed to
** the console followed by the determinant of the matrix.
*********************************************************************/

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
                if ((ant->getColCoord() + 1) == boardSize)
                {
					ant->setColCoord(0);
				}
				else
				{
					ant->setColCoord(ant->getColCoord() + 1);
				}
                break;
            case Right:
                ant->setDirection(Down);
                if ((ant->getRowCoord() + 1) == boardSize)
                {
					ant->setRowCoord(0);
				}
				else
				{
					ant->setRowCoord(ant->getRowCoord() + 1);
				}
                break;
            case Left:
                ant->setDirection(Up);
                if ((ant->getRowCoord() - 1) == -1)
                {
					ant->setRowCoord(boardSize - 1);
				}
				else
				{
					ant->setRowCoord(ant->getRowCoord() - 1);
				}
                break;
            case Down:
                ant->setDirection(Left);
                if ((ant->getColCoord() - 1) == -1)
                {
					ant->setColCoord(boardSize - 1);
				}
				else
				{
					ant->setColCoord(ant->getColCoord() - 1);
				}
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
                if ((ant->getColCoord() -1) == -1)
                {
					ant->setColCoord(boardSize -1);
				}
				else
				{
					ant->setColCoord(ant->getColCoord() - 1);
				}
                break;
            case Right:
                ant->setDirection(Up);
                if ((ant->getRowCoord() - 1) == -1)
                {
					ant->setRowCoord(boardSize - 1);
				}
				else
				{
					ant->setRowCoord(ant->getRowCoord() - 1);
				}
                break;
            case Left:
                ant->setDirection(Down);
                if ((ant->getRowCoord() + 1) == boardSize)
                {
					ant->setRowCoord(0);
				}
				else
				{
					ant->setRowCoord(ant->getRowCoord() + 1);
				}
                break;
            case Down:
                ant->setDirection(Right);
                if ((ant->getColCoord() + 1) == boardSize)
                {
					ant->setColCoord(0);
				}
				else
				{
					ant->setColCoord(ant->getColCoord() + 1);
				}
                break;
        }
    }
}
	


Board::~Board()
{
	for (int x = 0; x < boardSize; x++)
	{
        //cout << board[x] << endl;
        //board[x] = NULL;
		delete [] board[x];
	}
	delete [] board;
}
