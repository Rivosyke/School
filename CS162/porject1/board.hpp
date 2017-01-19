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
