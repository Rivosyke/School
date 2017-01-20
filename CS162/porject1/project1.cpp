#include "ant.hpp"
#include "utility.hpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include "board.hpp"

using namespace std;

void programDesc();
int startingPositionChoice();
int simSpeedChoice();

int main()
{
    int boardSize = 0;
    int userSteps = 0;
    int userRowStart = 0;
    int userColStart = 0;
    
    Ant* ant = nullptr;
    
    if (menu() == 2)
    {
        return 0;
    }
    system("clear");
    
    programDesc();
    
    cout << "Number of rows and columns: ";
    boardSize = getInt();
    
    while (boardSize < 1)
    {
        cout << endl << "Choice is not valid: Please a positive number greater than 0.";
        cout << endl << "Choice: ";
        boardSize = getInt();
    }
    
    cout << "Number of steps: ";
    userSteps = getInt();
    
    while (userSteps < 1)
    {
        cout << endl << "Choice is not valid: Please a positive number greater than 0.";
        cout << endl << "Choice: ";
        userSteps = getInt();
    }
    
    switch (startingPositionChoice())
    {
        case 1:
            break;
        case 2:
            ant = new Ant(boardSize/2, boardSize/2);
            break;
        case 3:
            cout << "Starting row position: ";
            userRowStart = getInt();
            
            while ((userRowStart < 0) || (userRowStart > (boardSize -1)))
            {
                cout << "Starting position as to be within the bounds of the board. "
                     << "Please choose a number between 0 and " 
                     << (boardSize -1) << endl;
                cout << "Starting row position: ";
                userRowStart = getInt();
            }
            cout << "Starting column position: ";
            userColStart = getInt();
            while ((userColStart < 0) || (userColStart > (boardSize -1)))
            {
                cout << "Starting position as to be within the bounds of the board. "
                     << "Please choose a number between 0 and " 
                     << (boardSize -1) << endl;
                cout << "Starting col position: ";
                userColStart = getInt();
            }

            ant = new Ant(userRowStart, userColStart);
            break;
        default:
            cout << "This shouldn't be seen...";
    };
    
    int simSpeed = simSpeedChoice();

    Board* board = new Board(boardSize);
    
    int stepsTaken = 0;
    
    while (stepsTaken <= userSteps)
    {
        system("clear");
        board->displayBoard(ant);
        board->makeMove(ant);
        stepsTaken++;
        usleep(simSpeed);
    }
    
    delete ant;
    delete board;
    
    
    return 0;
}

void programDesc()
{
        
    cout << "This program will implement Langton's Ant, a turing machine that" << endl;
    cout << "uses two simple rules: " << endl;
    cout << "1) On a blank char, flip the space to a #, turn right, move one." << endl;
    cout << "2) On a # char, flip the # to a blank, turn left, move one." << endl;
    cout << "You will need to enter a few pieces of information to continue." << endl;
    cout << "****************************************************************" << endl;
}
int startingPositionChoice()
{
    int userInput = 0;
    
    cout << "Starting position options:" << endl;
    cout << "1) Random" << endl;
    cout << "2) Middle of the board" << endl;
    cout << "3) User specified" << endl;
    cout << "Choice: ";
    userInput = getInt();
    
    while ((userInput < 1) || (userInput > 3))
    {
        cout << endl << "Choice is not valid: Please choose 1-3.";
        cout << endl << "Choice: ";
        userInput = getInt();
    }
    
    return userInput;
    
}

int simSpeedChoice()
{
    const int SLOW = 1000000;
    const int MEDIUM = 500000;
    const int FAST = 100000;
    const int LUDICROUS = 10000;
    
    int userInput = 0;
    
    cout << endl;
    cout << "Simulation Speed:" << endl;
    cout << "1) Slow (1 second per step)" << endl;
    cout << "2) Medium (0.5 seconds per step)" << endl;
    cout << "3) Fast (0.1 seconds per step)" << endl;
    cout << "4) Ludicrous speed! (0.01 seconds per step)" << endl;
    cout << "Choice: ";
    userInput = getInt();
    
    while ((userInput < 1) || (userInput > 4))
    {
        cout << endl << "Choice is not valid: Please choose 1-4.";
        cout << endl << "Choice: ";
        userInput = getInt();
    }
    
    switch (userInput)
    {
        case 1:
            return SLOW;
        case 2:
            return MEDIUM;
        case 3:
            return FAST;
        case 4:
            return LUDICROUS;
        default:
            return 1;
    };
}
