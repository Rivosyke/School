#include "functions.hpp"
#include "utility.hpp"
#include <iostream>

void printMenu();
void menuFunctionality();

using namespace std;

int main()
{
	//menuFunctionality();
	reverse("This is a test");
	
	return 0;
}


void menuFunctionality()
{
    int userInput;
    do
    {
        clearScreen();
        printMenu();
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
				clearScreen();
                pauseScreen();
                break;
            case 2:
				clearScreen();
				pauseScreen();
				break;
            case 3:
				clearScreen();
                pauseScreen();
                break;
            case 4:
                break;
        }
        
    } while (userInput != 4);
    
}

/*********************************************************************
** Description: This function outputs a menu showing the options 
** available to this information system
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

