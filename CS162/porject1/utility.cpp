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
    
    userInput = getInt();
    
    while ((userInput < 1) || (userInput > 2))
    {
        cout << endl << "Choice is not valid: Please choose 1-2.";
        cout << endl << "Choice: ";
        userInput = getInt();
    }
    
    return userInput;
}

void clearInput()
{
    cin.clear();
    cin.ignore(100000, '\n');
    cout << "Exiting Clear Input" << endl;
}    
 
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
    

