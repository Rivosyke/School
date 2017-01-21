/*********************************************************************
** Program name: Lab 1
** Author: Ryan McGinn
** Date: 14 January 2017
** Description: This program will ask the user to choose a 2x2 or a 
** 3x3 matrix and then fill the matrix with integers. Once the user
** is done filling in the integers, the matrix will be displayed to
** the console followed by the determinant of the matrix.
*********************************************************************/

#include "utility.hpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::string;
using std::cin;

/*********************************************************************
** Description: This function will accept two parameters: a pointer to
** an array of pointers and an integer. There is no return type (void).
** It will prompt the user to enter either 4 digits or 9 integers, 
** depending on the int passed to it. Each integer input will fill a spot
** in the matrix. Like determinant(), it requires that size be either
** a 2 or a 3.
*********************************************************************/

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
    
    userInput = getInt();
    
    while ((userInput < 1) || (userInput > 2))
    {
        cout << endl << "Choice is not valid: Please choose 1-2.";
        cout << endl << "Choice: ";
        userInput = getInt();
    }
    
    return userInput;
}
    

/*********************************************************************
** Description: This function will accept two parameters: a pointer to
** an array of pointers and an integer. There is no return type (void).
** It will prompt the user to enter either 4 digits or 9 integers, 
** depending on the int passed to it. Each integer input will fill a spot
** in the matrix. Like determinant(), it requires that size be either
** a 2 or a 3.
*********************************************************************/ 
int getInt()
{
    string userInput;
    getline(cin, userInput, '\n');
    bool validInput;
    
    do
    {
        validInput = true;
        
        if (userInput.length() == 0)
        {
            validInput = false;
        }
        else if (userInput[0] == '-' && (userInput.length() > 1))
        {
            for (unsigned int x = 1; x < userInput.length(); x++)
            {            
                if ((userInput[x] < '0') || (userInput[x] > '9'))
                {
                    validInput = false;
                }
            }
        }
        else
        {
            for (unsigned int x = 0; x < userInput.length(); x++)
            {            
                if ((userInput[x] < '0') || (userInput[x] > '9'))
                {
                    validInput = false;
                }
            }
        }
     
        if (!validInput)
        {
            cout << "Invalid Input - try again" << endl;
            cout << "User input: ";
            getline(cin, userInput, '\n');
        }
    } while (!validInput);
    
    return stoi(userInput);
}
    

