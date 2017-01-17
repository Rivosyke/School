/*********************************************************************
** Author: Ryan McGinn
** Date: 16 November 2016
** Description: This is the definition file for the Board class. This
** class has one data member - a 3x3 array of chars. 
** A constructor will initialize the array, print will display the 
** board, makeMove will attempt to set a value on the board, and 
** gameState will determine if the game has been won, if it's a draw,
** or if it's still in play.
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

enum Direction {Right, Left, Down};

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
        void setRowCoord(int);
        void setColCoord(int);
        
};
#endif // ANT_HPP
