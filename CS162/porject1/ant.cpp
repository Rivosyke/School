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
#include <iostream>

Ant::Ant(int row, int col)
{
	rowCoord = row;
	colCoord = col;
    facing = Up;
}

int Ant::getRowCoord()
{
	return rowCoord;
}
int Ant::getColCoord()
{
	return colCoord;
}
void Ant::setRowCoord(int row)
{
	rowCoord = row;
}
void Ant::setColCoord(int col)
{
	colCoord = col;
}

Direction Ant::getDirection()
{
    return facing;
}

void Ant::setDirection(Direction newDirection)
{
    facing = newDirection;
}

