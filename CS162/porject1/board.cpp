/*********************************************************************
** Program Name: Project 1
** Author: Ryan McGinn
** Date: 20 January 2017
** Description: This program will implement Langont's Ant, a Turing
** machine that follow's two simple rules: 
** 1) On a blank char, flip the space to a #, turn right, move one
** 2) On a # char, flip the # to a blank, turn left, move one.
** The user will be prompted for various information: grid size,
** number of steps, speed of the simulation, and starting position of
** the ant. The simulation will then display each step until it is 
** finished.
*********************************************************************/

#include "board.hpp"
#include <iostream>
#include "ant.hpp"

using namespace std;


/*********************************************************************
** Description: This function will initialize the two Board class 
** variables: boardSize will be set to the passed in int value. The
** char pointer will be set to an array of char pointers and then each
** char pointer array will be allocated a new memory space. Then, each 
** cell in the arrays will be set to a blank character.
*********************************************************************/
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
/*********************************************************************
** Description: This function will iterate through the array and
** display the character held in each cell of the array. If the ant's
** coords match the current iterated location, it will display an 
** asterisk instead of the that cell's character.
*********************************************************************/
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

/*********************************************************************
** Description: This function is the moving logic behind the ant. Each
** time it's invoked, it will check the ant's current position on the
** board. If the cell is a blank char, the cell gets changed to a # and
** a switch statement bound to the direction the ant is currently facing
** will determine how the ant moves next. 
*********************************************************************/
void Board::makeMove(Ant* ant)
{
    if (board[ant->getRowCoord()][ant->getColCoord()] == ' ')
    {
        board[ant->getRowCoord()][ant->getColCoord()] = '#';
        
        switch(ant->getDirection())
        {
            case Up: 
                ant->setDirection(Right);
                // This checks to see if moving the ant will put it past
                // the board's array boundaries
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
				// This checks to see if moving the ant will put it past
                // the board's array boundaries
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
                // This checks to see if moving the ant will put it past
                // the board's array boundaries
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
                // This checks to see if moving the ant will put it past
                // the board's array boundaries
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
                // This checks to see if moving the ant will put it past
                // the board's array boundaries
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
                // This checks to see if moving the ant will put it past
                // the board's array boundaries
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
                // This checks to see if moving the ant will put it past
                // the board's array boundaries
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
                // This checks to see if moving the ant will put it past
                // the board's array boundaries
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
	

/*********************************************************************
** Description: This is the destructor for the board class. It will 
** iterate through the array of pointers and individually delete the
** dynamically allocated arrays.
*********************************************************************/
Board::~Board()
{
	for (int x = 0; x < boardSize; x++)
	{
		delete [] board[x];
	}
	delete [] board;
}
