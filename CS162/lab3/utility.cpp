/*********************************************************************
** Program Name: Project 1
** Author: Ryan McGinn
** Date: 20 January 2017
** Description: This program will implement Langont's Ant, a Turing
** machine that follow's two simple rules: 
** 1) On a blank char, flip the space to a #, turn right, move one
** 2) On a # char, flip the # to a blank, turn left, move one.
** The user will be prompted for various information: grid size,
** number of steps, speed of the simulation, and starting position of
** the ant. The simulation will then display each step until it is 
** finished.
*********************************************************************/

#include "utility.hpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <unistd.h>

using std::cout;
using std::endl;
using std::string;
using std::cin;

/*********************************************************************
** Description: This is a generic menu that will allow the user to
** either run the program they executed or quit.
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
** Description: This function will return an int that has been properly
** input. It will test the user input for all non-digits and keep
** having the user try inputs until a valid integer is input. This 
** includes negative numbers as well.
*********************************************************************/ 
int getInt()
{
    string userInput;
    getline(cin, userInput, '\n');
    bool validInput;
    
    do
    {
        validInput = true;
        
        // Checks to see if there is no input (user just hits enter)
        if (userInput.length() == 0)
        {
            validInput = false;
        }

        for (unsigned int x = 0; x < userInput.length(); x++)
		{       
			// This statement is here to ensure that a hyphen as the first
			// character doesn't get flagged as invalid as this would 
			// indicate negative numbers.
			if ((x == 0 && userInput[x] == '-') && userInput.length() > 1)
			{
				continue;
			}
			// If the character is not a digit, flag it as false   
			else if ((userInput[x] < '0') || (userInput[x] > '9'))
			{
				validInput = false;
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

/*********************************************************************
** Description: This version of getInt has been left here, commented
** out, in order to show what I would have had to do if I didn't use
** the continue keyword. I found that I'd need to do two separate for 
** loops to account for negative numbers. I thought that was far too
** messy, code wise.
*********************************************************************/ 
/*
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
*/

/*********************************************************************
** Description: This function will generate a random number based
** off of the number passed in. This will create a range from 0 to 
** that number.
*********************************************************************/
int randomNum(int modNumber)
{
	return (rand() % modNumber);
}	

/*********************************************************************
** Description: This function will generate a random number based
** off of the number passed in. This will create a range from 0 to 
** that number. This overloaded version will take another number that
** will add a certain number to the final output.
*********************************************************************/	
int randomNum(int modNumber, int plusNumber)
{
	return (rand() % modNumber) + plusNumber;
}
    
void clearScreen()
{
    system("clear");
}

void sleep(double time)
{
    int msToS = 1000000;
    usleep(msToS * time);
}
