/*********************************************************************
** Program name: Lab 1
** Author: Ryan McGinn
** Date: 14 January 2017
** Description: This program will ask the user to choose a 2x2 or a 
** 3x3 matrix and then fill the matrix with integers. Once the user
** is done filling in the integers, the matrix will be displayed to
** the console followed by the determinant of the matrix.
*********************************************************************/

#include "readMatrix.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


/*********************************************************************
** Description: This function will accept two parameters: a pointer to
** an array of pointers and an integer. There is no return type (void).
** It will prompt the user to enter either 4 digits or 9 integers, 
** depending on the int passed to it. Each integer input will fill a spot
** in the matrix. Like determinant(), it requires that size be either
** a 2 or a 3.
*********************************************************************/
void readMatrix(int **matrix, int size)
{
    cout << endl << "Please enter " << size*size << " integers to fill the array:" << endl;
    int userInput = 0;
    
    for (int x = 0; x < size; x++)
    {   
        for (int y = 0; y < size; y++)
        {
            cout << "Row:" << x << " Col:" << y << ": ";
            cin >> userInput;
            matrix[x][y] = userInput;
        }
        // Ensures that the last iteration will not output the new row statement
        if (!(x == size-1))
        {
            cout << "*** New Row ***" << endl;
        }
    }
}
