#include "utility.hpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int menu()
{
    int userInput;
    system("clear");
    
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*              Program Menu for:               *" << endl;
    cout << "*                Ryan McGinn                   *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl << endl;
    
    cout << "1) Run Program" << endl;
    cout << "2) Exit" << endl;
    cout << "User Input: ";
    
    cin >> userInput;
    
    return userInput;
}

void clearInput()
{
    cin.clear();
    cin.ignore(500, '\n');
}    
 
bool invalidInput(int userInput)
{
    if (userInput == 0);
    {
         
    }
    return true;
}
    

