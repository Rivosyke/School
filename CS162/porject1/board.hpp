/*********************************************************************
** Program name: Lab 1
** Author: Ryan McGinn
** Date: 14 January 2017
** Description: This program will ask the user to choose a 2x2 or a 
** 3x3 matrix and then fill the matrix with integers. Once the user
** is done filling in the integers, the matrix will be displayed to
** the console followed by the determinant of the matrix.
*********************************************************************/

#include "ant.hpp"

#ifndef BOARD_HPP
#define BOARD_HPP


class Board
{
	private:
		char** board;
		int boardSize;
	public:
		Board(int);
		void displayBoard(Ant* ant);
		void makeMove(Ant* ant);
		~Board();
};

#endif // BOARD_HPP
