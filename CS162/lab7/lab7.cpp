/*********************************************************************
** Program Name: Lab 7
** Author: Ryan McGinn
** Date: 26 February 2017
** Description: This program will implement a basic queue that adds
** items to the back and gets them from the front. Various options
** are presented to the user to perform operations on the queue.
*********************************************************************/

#include <iostream>
#include "Queue.hpp"
#include "utility.hpp"


using std::cout;
using std::endl;

void printMenu();
void queueOperations(Queue* queue);


/*********************************************************************
** Running Instruction: This program doesn't use any command-line 
** arguments and is executed on the command line using the executable's
** name.
*********************************************************************/
int main()
{
    
    Queue queue;
        
    queueOperations(&queue);
    
    
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
    cout << "*             Queue Operations                 *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl << endl;
    
    cout << "1) Enter a value to be added to the queue" << endl;
    cout << "2) Display first node (front) value" << endl;
    cout << "3) Remove first node (front) value" << endl;
    cout << "4) Display the queue contents" << endl;
    cout << "5) Exit" << endl;
    cout << endl;
    
}

/*********************************************************************
** Description: This function will implement the functionality of the 
** options presented by the printMenu() function.
*********************************************************************/
void queueOperations(Queue* queue)
{

    int userInput;
    int menuInput;
    int frontNode = 0;

    do
    {
        clearScreen();
        printMenu();
        
        cout << "User Input: ";
        userInput = getInt();
    
        while ((userInput < 1) || (userInput > 5))
        {
            cout << endl << "Choice is not valid: Please choose 1-5.";
            cout << endl << "Choice: ";
            userInput = getInt();
        }
        // Switch that executes various options based on the user's input
        switch (userInput)
        {
            case 1:
				cout << endl;
                cout << "Enter a value to add (positive integers only!): ";
                menuInput = getInt();
                queue -> addBack(menuInput);
                pauseScreen();
                break;
            case 2:
				cout << endl;
                frontNode = queue -> getFront();
                
                if (frontNode == -1)
                {
                    cout << "No node could be removed as the queue is empty!" << endl;
                }
                else
                {                
                    cout << "Front node value is: " << queue -> getFront() << endl;
                }
                
				pauseScreen();
				break;
            case 3:
                frontNode = queue -> removeFront();
                if (frontNode == -1)
                {
                    cout << "No node could be removed as the queue is empty!" << endl;
                }
                else
                {                    
                    cout << "Removed node's value: " << frontNode << endl;
                }
                pauseScreen();
                break;
            case 4:
                cout << endl;
                queue -> printQueue();
                pauseScreen();
                break;
            case 5:
                break;
        }
        
    } while (userInput != 5);
}
