/*********************************************************************
** Program name: Lab 1
** Author: Ryan McGinn
** Date: 14 January 2017
** Description: This program will ask the user to choose a 2x2 or a 
** 3x3 matrix and then fill the matrix with integers. Once the user
** is done filling in the integers, the matrix will be displayed to
** the console followed by the determinant of the matrix.
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

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
