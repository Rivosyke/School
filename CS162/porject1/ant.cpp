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

#include "ant.hpp"
#include <iostream>

/*********************************************************************
** Description: Constructor that sets rowCoord and colCoord to the 
** passed in values. facing is set to "Up".
*********************************************************************/
Ant::Ant(int row, int col)
{
	rowCoord = row;
	colCoord = col;
    facing = Up;
}

// Accessor function that returns the rowCoord member
int Ant::getRowCoord()
{
	return rowCoord;
}
// Accessor function that returns the colCoord member
int Ant::getColCoord()
{
	return colCoord;
}

// Setter function that sets the rowCoord member to the passed value
void Ant::setRowCoord(int row)
{
	rowCoord = row;
}

// Setter function that sets the colCoord member to the passed value
void Ant::setColCoord(int col)
{
	colCoord = col;
}
// Accessor function that returns the Direction member
Direction Ant::getDirection()
{
    return facing;
}

// Setter function that sets the facing member to the passed value
void Ant::setDirection(Direction newDirection)
{
    facing = newDirection;
}

