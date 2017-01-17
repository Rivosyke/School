/*********************************************************************
** Program name: Lab 1
** Author: Ryan McGinn
** Date: 14 January 2017
** Description: This program will ask the user to choose a 2x2 or a 
** 3x3 matrix and then fill the matrix with integers. Once the user
** is done filling in the integers, the matrix will be displayed to
** the console followed by the determinant of the matrix.
*********************************************************************/

#include "determinant.hpp"


/*********************************************************************
** Description: This function will accept two parameters: a pointer to
** an array of pointers and an integer. It will return the determinant
** of either a 2x2 or a 3x3 matrix, depending on the int passed to it.
** This function requires that only a 2 or 3 get passed to it, which
** should be ensured by the main program.
*********************************************************************/
int determinant(int **matrix, int size)
{
    if (size == 2)
    {
        return ((matrix[0][0] * matrix[1][1]) -
                (matrix[0][1] * matrix[1][0]));
    }
    else
    {
        return ((matrix[0][0] * matrix[1][1] * matrix[2][2]) +
                (matrix[0][1] * matrix[1][2] * matrix[2][0]) +
                (matrix[0][2] * matrix[1][0] * matrix[2][1]) -               
                (matrix[0][2] * matrix[1][1] * matrix[2][0]) -
                (matrix[0][0] * matrix[1][2] * matrix[2][1]) - 
                (matrix[0][1] * matrix[1][0] * matrix[2][2]));
    }
}
