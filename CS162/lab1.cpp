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
#include "readMatrix.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::right;
using std::setw;

/*********************************************************************
** Description: This program will ask the user to choose a 2x2 or a 
** 3x3 matrix and then fill the matrix with integers. Once the user
** is done filling in the integers, the matrix will be displayed to
** the console followed by the determinant of the matrix.
** Running Instruction: This program doesn't use any command-line 
** arguments and is executed on the command line using the executable's
** name.
*********************************************************************/
int main()
{
    
    int matrixSize = 0;
    
    cout << "This program will find the determinant of a 2x2 or 3x3 matrix." <<endl;

    cout << "Which matrix size? ";
    cin >> matrixSize;    
    
    // Ensures that the value input will only be a 2 or a 3
    while (matrixSize != 2 && matrixSize != 3)
    {
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Invalid matrix size. Please input 2 or 3. " << endl;
        cout << "Which matrix size? ";
        cin >> matrixSize;
    } 
    
    // This block of code will instantiate a pointer to an array of 
	// pointers and then allocate new arrays into that pointer array
    int **matrix = new int*[matrixSize];

    for (int x = 0; x < matrixSize; x++)
    {
        matrix[x] = new int[matrixSize];
    }
    
    
    readMatrix(matrix, matrixSize);
    
    cout << endl << "Your chosen matrix: " << endl;
    
    // Sets the output so that negative numbers are properly aligned
    for (int x = 0; x < matrixSize; x++)
    {
        for (int y = 0; y < matrixSize; y++)
        {
            cout << setw(3) << right << matrix[x][y] << " ";
        }
        cout << endl;
    }
    
    cout << endl << "Determinant = " << determinant(matrix, matrixSize) << endl;
    
    delete matrix;
    
    return 0;
}
