/*********************************************************************
** Program Name: Lab 5
** Author: Ryan McGinn
** Date: 09 February 2017
** Description: This program will output a menu that gives the user
** four different options: 1) Reverse a String, 2) Sum an array of ints,
** 3) Calculate a Triangular Number, 4) Exit.
*********************************************************************/

#include <iostream>
#include "utility.hpp"
#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include <vector>




using namespace std;

void printMenu();
void menuFunctionality();
Creature* monsterChoice(int choice);

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
** Description: This function outputs a menu showing the options 
** available to the user.
*********************************************************************/
void printMenu()
{
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*             Monster Fighting!                *" << endl;
    cout << "*                                              *" << endl;
    cout << "*            Choose two monsters               *" << endl;
    cout << "*              to duke it out!                 *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl << endl;
    
    cout << "1) Barbarian" << endl;
    cout << "2) Vampire" << endl;
    cout << "3) Blue Men" << endl;
    cout << "4) Medusa" << endl;
    cout << "5) Harry Potter" << endl;
    cout << endl;
    
}

/*********************************************************************
** Description: This function will implement the functionality of the 
** options presented by the printMenu() function.
*********************************************************************/
void menuFunctionality()
{
    seedRN();
    int monsterChoiceOne;
    int monsterChoiceTwo;
    
    char userInput;
    
    Creature* monsters[2];

    do
    {
        // Clears the screen and prints the menu
        clearScreen();
        printMenu();
        
        cout << "1st Monster Choice: ";
        
        monsterChoiceOne = getInt();
    
        while ((monsterChoiceOne < 1) || (monsterChoiceOne > 5))
        {
            cout << endl << "Choice is not valid: Please choose 1-5.";
            cout << endl << "Choice: ";
            monsterChoiceOne = getInt();
        }
        
        cout << "2nd Monster Choice: ";
        
        monsterChoiceTwo = getInt();
    
        while ((monsterChoiceTwo < 1) || (monsterChoiceTwo > 5))
        {
            cout << endl << "Choice is not valid: Please choose 1-5.";
            cout << endl << "Choice: ";
            monsterChoiceTwo = getInt();
        }
        
        // Determines which fighter goes first
        int startingFighter = randomNum(2);
        
        if (startingFighter == 0)
        {
            monsters[0] = monsterChoice(monsterChoiceOne);
            monsters[1] = monsterChoice(monsterChoiceTwo);
        }
        else
        {
            monsters[0] = monsterChoice(monsterChoiceTwo);
            monsters[1] = monsterChoice(monsterChoiceOne);
        }
    
        
        while (monsters[0]->living() and monsters[1]->living())
        {
            cout << endl << "Attack: " << monsters[0]->getName() << endl;
            monsters[1]->defense(monsters[0]->attack());
            cout << "Remaining str for " << monsters[1]->getName() << " : " << monsters[1]->getStr() << endl;
            
            if (monsters[1]->living())
            {
                cout << "Attack: " << monsters[1]->getName() << endl;
                monsters[0]->defense(monsters[1]->attack());
                cout << "Remaining str for " << monsters[0]->getName() << " : " << monsters[0]->getStr() << endl;
            }
            cout << endl;
        }
        
        if (!monsters[1]->living())
        {
            cout << monsters[0]->getName() << " is the winner!" << endl;
        }
        else
        {
            cout << monsters[1]->getName() << " is the winner!" << endl;
        }
        
        cout << "Play again? (y) or (n): ";
        cin >> userInput;
        
        cin.clear();
        cin.ignore(500, '\n');
        
        delete monsters[0];
        delete monsters[1];
        
        monsters[0] = nullptr;
        monsters[1] = nullptr;
        
    } while (userInput != 'n');
    
}
Creature* monsterChoice(int choice)
{
    switch (choice)
        {
            case 1:
                return new Barbarian();
                break;
            case 2:
                return new Vampire();
                break;
            case 3:
                return new BlueMen();
                break;
            case 4:
                return new Medusa();
                break;
            case 5:
                return new HarryPotter();
                break;
            default:
                return nullptr;
        };
}
