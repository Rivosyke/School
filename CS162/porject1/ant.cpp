#include "ant.hpp"
#include <iostream>

Ant::Ant(int row, int col)
{
	rowCoord = row;
	colCoord = col;
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
