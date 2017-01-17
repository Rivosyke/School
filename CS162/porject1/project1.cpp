#include "ant.hpp"
#include "utility.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void displayBoard(Ant* ant, char** board, int size);

void fillBoard(Ant* ant, char** board, int size);



int main()
{
    
    
    int boardSize = 0;
    

    
    cout << "Number of rows and columns: ";
    cin >> boardSize;
    
    Ant* ant = new Ant(boardSize/2, boardSize/2);
    
    char **board = new char*[boardSize];

    for (int x = 0; x < boardSize; x++)
    {
        board[x] = new char[boardSize];
    }
    
    fillBoard(ant, board, boardSize);
    displayBoard(ant, board, boardSize);
    
    
    
    return 0;
}


void displayBoard(Ant* ant, char** board, int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
			if ((col == ant->getColCoord()) && (row == ant->getRowCoord()))
			{
				cout << "*";
			}
            else
            {
				cout << board[row][col];
			}
        }
        cout << endl;
    }
}


void fillBoard(Ant* ant, char** board, int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            board[row][col] = ' ';
        }
    }
}
    
    
