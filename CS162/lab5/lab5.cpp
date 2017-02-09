/*********************************************************************
** Program Name: Lab 5
** Author: Ryan McGinn
** Date: 09 February 2017
** Description: This program will output a menu that gives the user
** four different options: 1) Reverse a String, 2) Sum an array of ints,
** 3) Calculate a Triangular Number, 4) Exit.
*********************************************************************/

#include "functions.hpp"
#include "utility.hpp"
#include <iostream>
#include <string>

void printMenu();
void menuFunctionality();

using std::cout;
using std::cin;
using std::endl;
using std::string;


/*********************************************************************
** Running Instruction: This program doesn't use any command-line 
** arguments and is executed on the command line using the executable's
** name.
*********************************************************************/
int main()
{
	menuFunctionality();
 
	return 0;
}

/*********************************************************************
** Description: This function will implement the functionality of the 
** options presented by the printMenu() function.
*********************************************************************/
void menuFunctionality()
{
    string reverseInput;
    int userInput;
    int arrayInput;
    int tNumInput = 0;
    
    // Large array to hold enough ints for a determined user to input
    int* array = new int[10000];
    for (int x = 0; x < 10000; x++)
    {
		array[x] = 0;
	}
    int counter = 0;
    
    do
    {
        // Clears the screen and prints the menu
        clearScreen();
        printMenu();
        userInput = getInt();
    
        while ((userInput < 1) || (userInput > 4))
        {
            cout << endl << "Choice is not valid: Please choose 1-4.";
            cout << endl << "Choice: ";
            userInput = getInt();
        }
        
        // Switch that executes various options based on the user's input
        switch (userInput)
        {
            case 1:
				clearScreen();
                cout << "Enter a string and it will be reversed" << endl;
                cout << "User Input: " ;
                getline(cin, reverseInput);
                reverse(reverseInput);
                pauseScreen();
                break;
            case 2:
				clearScreen();
                counter = 0;
                cout << "Enter a series of integers, one per line. " << endl;
                cout << "Enter any non-digit to stop inputting integers." << endl;
                cout << "This includes attempting to input a number with a decimal." << endl;
                cout << "User Input: " << endl;
                // do while loop that controls the integer input
                do
                {
                    cin >> arrayInput;
                    // Checks to see if the input is not an integer
                    if (cin.fail())
                    {
                        cout << endl << "Integer input terminated" << endl;
                    }
                    else
                    {
                        array[counter] = arrayInput;
                        counter++;
                    }
                } while (!cin.fail());
                
                cout << "Sum of the integers is: ";
                cout << sumArray(array, counter) << endl;
                
                // Clears the cin fail flag
                cin.clear();
                cin.ignore(500, '\n');
				pauseScreen();
				break;
            case 3:
				clearScreen();
                cout << "Enter a number to calculate the triangular number." << endl;
                cout << "User Input: ";
                tNumInput = getInt();
                
                cout << "Triangular Number is: ";
                cout << triangleSum(tNumInput) << endl;
                
                pauseScreen();
                break;
            case 4:
                break;
        }
        
    } while (userInput != 4);
    delete [] array;
}

/*********************************************************************
** Description: This function outputs a menu showing the options 
** available to the user.
*********************************************************************/
void printMenu()
{
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*            Recursive Functions               *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl << endl;
    
    cout << "1) Reverse a string" << endl;
    cout << "2) Sum a series of integers" << endl;
    cout << "3) Calculate triangular number" << endl;
    cout << "4) Exit Program" << endl;
    cout << "User Input: ";
}

