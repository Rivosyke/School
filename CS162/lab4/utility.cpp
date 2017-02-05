/*********************************************************************
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This is the implementation file for the utility library.
** It contains the function definitions for this library.
*********************************************************************/

#include "utility.hpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <ctime>

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
** Description: This function will return a double that has been properly
** input. It will test the user input for all non-digits and keep
** having the user try inputs until a valid double is input. This 
** includes negative numbers as well.
*********************************************************************/ 
double getDouble()
{
    double userInput = 0;
    bool validInput;
    
    do 
    {
        validInput = true;
        
        cin >> userInput;
        if (cin.fail())
        {
            cout << "Invalid Input - try again" << endl;
            cout << "User input: ";
            validInput = false;
        }
        cin.clear();
        cin.ignore(500, '\n');
    } while (!validInput);
    
    return userInput;
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
** Description: This function is just a wrapper for the system command
** in order to not have those libraries be included on every file 
** that needs to clear the screen.
*********************************************************************/
void clearScreen()
{
    system("clear");
}

/*********************************************************************
** Description: This function will prompt the user to choose an option
** for the speed of the simulation. The options correspond to constant
** ints that represent microseconds. 
*********************************************************************/
void sleep(double time)
{
    int msToS = 1000000;
    usleep(msToS * time);
}

/*********************************************************************
** Description: This function is just a wrapper for seeding the random
** number generator in order to not have those header files be included 
** on every file that needs to clear the screen.
*********************************************************************/
void seedRN()
{
    // Seeds the Pseudo-random number generator 
	srand(time(NULL));
}

double randomDouble(int modNumber)
{
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/modNumber));
}
