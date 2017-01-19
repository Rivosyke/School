#include "ant.hpp"
#include "utility.hpp"
#include <iostream>
#include <iomanip>
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
    cin >> boardSize;
    cout << "Number of steps: ";
    cin >> userSteps;
    
    switch (startingPositionChoice())
    {
        case 1:
            break;
        case 2:
            ant = new Ant(boardSize/2, boardSize/2);
            break;
        case 3:
            do
            {
                cout << "Starting row position: ";
                cin >> userRowStart;
            } while (0);
            do
            {
                cout << "Starting column position: ";
                cin >> userColStart;
            } while (0);
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
    
    do 
    {
        cout << "Starting position options:" << endl;
        cout << "1) Random" << endl;
        cout << "2) Middle of the board" << endl;
        cout << "3) User specified" << endl;
        cout << "Choice: ";
        cin >> userInput;
    } while(0);
    
    return userInput;
    
}

int simSpeedChoice()
{
    int userInput = 0;
    do 
    {
        cout << endl;
        cout << "Simulation Speed:" << endl;
        cout << "1) Slow (1 second per step)" << endl;
        cout << "2) Medium (0.5 seconds per step)" << endl;
        cout << "3) Fast (0.1 seconds per step)" << endl;
        cout << "4) Ludicrous speed! (0.01 seconds per step)" << endl;
        cout << "Choice: ";
        cin >> userInput;
    } while(0);
    
    switch (userInput)
    {
        case 1:
            return 1000000;
        case 2:
            return 500000;
        case 3:
            return 100000;
        case 4:
            return 10000;
        default:
            return 1;
    };
}
