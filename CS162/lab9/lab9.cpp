/*********************************************************************
** Program Name: Lab9
** Author: Ryan McGinn
** Date: 12 March 2017
** Description: This program will simulate a buffer by using a queue 
** and will output a palindrome by using a stack. This program is 
** intended to demonstrate the different input / output types of the 
** queue/stack STL containers.
*********************************************************************/

#include "utility.hpp"
#include <queue>
#include <stack>
#include <iostream>
#include <string>

void printMenu();
void menuFunctionality();
void palindrome();
void queueOperations();

using std::string;
using std::cout;
using std::queue;
using std::stack;
using std::cin;
using std::endl;

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
	cout << "*              Queues and Stacks               *" << endl;
	cout << "*                                              *" << endl;		
	cout << "*                                              *" << endl;
	cout << "************************************************" << endl << endl;
    
	cout << " 1) Perform Queue Operations" << endl;
	cout << " 2) Palindrome with a stack" << endl;
	cout << " 3) Exit" << endl;
	cout << endl;
}

/*********************************************************************
** Description: This function will implement the functionality of the 
** options presented by the printMenu() function.
*********************************************************************/
void menuFunctionality()
{	
	seedRN();
	int userInput = 0;	
	
	do
	{   
		clearScreen();
		printMenu();
		cout << "User Input: ";
		
		userInput = getInt();
		
		while (userInput < 1 or userInput > 3)
        {
            cout << endl << "Choice is not valid: Please choose 1-3.";
            cout << endl << "Choice: ";
            userInput = getInt();
		}	
        switch (userInput)
        {
			// Queue logic
			case 1:	
				queueOperations();
				pauseScreen();
				break;
			// Palindrome logic
			case 2:
				palindrome();
				pauseScreen();
				break;
			// Exit
			case 3:			
				break;
		}	
	} while (userInput != 3);
}

/*********************************************************************
** Description: This function will ask the user for a string. The 
** function will then push each character of the string onto a stack.
** The stack will then pop each character back onto the string and then
** output the final string to the console.
*********************************************************************/
void palindrome()
{
	stack<char> charStack;
	string userString;
	clearScreen();
	userString.clear();
	cout << "Enter a string to be turned into a palindrome." << endl;
	cout << "User Input: ";
	getline(cin, userString);
	
	// Push each char of the string onto the stack
	for (unsigned int x = 0; x < userString.size(); x++)
	{
		charStack.push(userString.at(x));
	}
	
	// Pop the chars off the stack and add them onto the string
	while (!charStack.empty())
	{
		userString.push_back(charStack.top());
		charStack.pop();
	}
	
	cout << "Palindrome: " << userString << endl;
}

/*********************************************************************
** Description: Function that will instantiate an int queue from the 
** STL, fill it with integers, then prompt the user for percentages.
** These percentages will be used to determine if the a random number
** will be pushed onto the queue or if a number will be popped off. 
** The user will also be prompted for the number of rounds to run the
** simulation. At the end of each round, the average length of the 
** queue will be outputted to the screen as well as the current length
** of the queue.
*********************************************************************/
void queueOperations()
{
	clearScreen();
	queue<int> intQueue;
	
	int randomChance = 0;
	int pushChance = 0;
	int popChance = 0;
	int numOfRounds = 0;
	double avgQLen = 0;
	double prevQLen = 0;
	
	// Populates the queue 
	for (int x = 0; x < 100; x++)
	{
		intQueue.push(x);
	}
	
	cout << "Enter the percentage the number is pushed: ";
	pushChance = getInt();
	
	// Value entered must be between 1 and 100 for percentages
	while (pushChance < 0 or pushChance > 100)
	{
		cout << "Percentage has to be between 0 and 100" << endl;
		cout << "Percentage input: ";
		pushChance = getInt();
	}

	cout << "Enter the percentage the number is popped: ";
	popChance = getInt();
	
	// Value entered must be between 1 and 100 for percentages
	while (popChance < 0 or popChance > 100)
	{
		cout << "Percentage has to be between 0 and 100" << endl;
		cout << "Percentage input: ";
		popChance = getInt();
	}

	
	cout << "Enter the number of rounds: ";
	numOfRounds = getInt();
	
	while (numOfRounds < 1)
	{
		cout << "Need at least one round. " << endl;
		cout << "Rounds: ";
		numOfRounds = getInt();
	}
	
	avgQLen = intQueue.size();
	prevQLen = avgQLen;
	
	// Main logic for the queue operations
	for (int x = 1; x <= numOfRounds; x++)
	{
		randomChance = randomNum(100);
		
		if (randomChance <= pushChance)
		{
			intQueue.push(randomNum(100));
			cout << "Number pushed onto the queue!" << endl;
		}
		
		if (randomChance <= popChance)
		{
			if (!intQueue.empty())
			{
				intQueue.pop();
				cout << "Queue popped!" << endl;
			}
			else
			{
				cout << "Queue is empty, not able to pop." << endl;
			}
		}
		
		// Calculates the average queue length
		avgQLen = ((prevQLen * (x - 1)) + intQueue.size()) / x;
		prevQLen = avgQLen;						
		cout << "Average Queue Length: " << avgQLen << endl;
		cout << "Real Queue Length   : " << intQueue.size() << endl;
		cout << endl;	
	}
}


