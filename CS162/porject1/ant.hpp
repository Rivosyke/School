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

#ifndef ANT_HPP
#define ANT_HPP

// Represents the cardinal directions 
enum Direction {Up, Right, Left, Down};

class Ant
{
    private:
		int rowCoord;
		int colCoord;
		Direction facing;
		   
    public:
        Ant(int, int);
        int getRowCoord();
        int getColCoord();
        Direction getDirection();
        void setRowCoord(int);
        void setColCoord(int);
        void setDirection(Direction);
        
};
#endif // ANT_HPP
