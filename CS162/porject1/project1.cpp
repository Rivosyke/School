#include "ant.hpp"
#include "utility.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void displayBoard (char** board, int size);

void fillBoard(char** board, int size);

int main()
{
    
    
    int boardSize = 0;
    
    cout << "Number of rows and columns: ";
    cin >> boardSize;
    
    char **board = new char*[boardSize];

    for (int x = 0; x < boardSize; x++)
    {
        board[x] = new char[boardSize];
    }
    
    fillBoard(board, boardSize);
    displayBoard(board, boardSize);
    
    
    
    return 0;
}


void displayBoard (char** board, int size)
{
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            cout << board[y][x];
        }
        cout << endl;
    }
}


void fillBoard(char** board, int size)
{
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            board[y][x] = ' ';
        }
    }
}
    
    
