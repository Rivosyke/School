/*********************************************************************
** Program Name: Lab 6
** Author: Ryan McGinn
** Date: 19 February 2017
** Description: This program will implement a basic doubly linked list
** that will store a single double value in each node. The user will
** be prompted to enter a value for each new node and will then sum
** the values of all nodes, unless the list is empty.
*********************************************************************/

#include <iostream>
#include "utility.hpp"

using std::cout;
using std::endl;

struct ListNode
{
	int value;
	ListNode* prev;
	ListNode* next;
};

class SimpleList
{
	private:
		ListNode* head;
		ListNode* tail;
		int numOfElements;
		
	public:
/*********************************************************************
** Description: The constructor will set the pointers to nullptr and
** numOfElements to 0.
*********************************************************************/
		SimpleList()
		{
			head = nullptr;
			tail = nullptr;
			numOfElements = 0;
		}
/*********************************************************************
** Description: This method will add a node to the front of the list.
*********************************************************************/	
		void addNodeHead(int userValue)
		{
			ListNode* temp = new ListNode;
			
			temp -> value = userValue;
			temp -> prev = nullptr;
			
			// Different logic based on if this is the first element			
			if (numOfElements == 0)
			{
				
				temp -> next = nullptr;
				head = temp;
				tail = temp;
				numOfElements++;
			}
			else
			{
				
				temp -> next = head;
				head -> prev = temp;
				head = temp;
				numOfElements++;
			}
				
		}
/*********************************************************************
** Description: This method will add a node to the back of the list.
*********************************************************************/		
		void addNodeTail(int userValue)
		{
			ListNode* temp = new ListNode;
			
			temp -> value = userValue;
		
			// Different logic based on if this is the first element
			if (numOfElements == 0)
			{
				
				temp -> next = nullptr;
				temp -> prev = nullptr;
				head = temp;
				tail = temp;
				numOfElements++;
			}
			else
			{
				temp -> next = nullptr;
				temp -> prev = tail;
				tail -> next = temp;
				tail = temp;
				numOfElements++;
			}
			
		}
/*********************************************************************
** Description: This method will print the first element in the list
** provided the list isn't empty.
*********************************************************************/		
		void printHead()
		{
			if (numOfElements == 0)
			{
				cout << "The list is empty!" << endl;
			}
			else
			{
				cout << "The head value is: " << head -> value << endl;
			}
		}
/*********************************************************************
** Description: This method will delete the first element in the list,
** provided the list isn't empty.
*********************************************************************/
		void deleteHead()
		{
			if (numOfElements == 0)
			{
				cout << "The list is currently empty!" << endl;
			}
			else if (numOfElements == 1)
			{
				delete head;
				tail = nullptr;
				head = nullptr;
				numOfElements--;
				cout << "The list is now empty!" << endl;
			}
			else
			{
				ListNode* temp = head -> next;
				temp -> prev = nullptr;
				delete head;
				head = temp;
				numOfElements--;
				cout << "The new head is now: " << head -> value << endl;
			}
		}
/*********************************************************************
** Description: This method will delete the last element in the list
** provided it isn't empty.
*********************************************************************/		
		void deleteTail()
		{
			if (numOfElements == 0)
			{
				cout << "The list is currently empty!" << endl;
			}
			else if (numOfElements == 1)
			{
				delete tail;
				tail = nullptr;
				head = nullptr;
				numOfElements--;
				cout << "The list is now empty!" << endl;
			}
			else
			{
				ListNode* temp = tail -> prev;
				temp -> next = nullptr;
				delete tail;
				tail = temp;
				numOfElements--;
				cout << "The new tail is now: " << tail -> value << endl;
			}
		}
/*********************************************************************
** Description: This method will print the last item in the list,
** provided it isn't empty.
*********************************************************************/		
		void printTail()
		{
			if (numOfElements == 0)
			{
				cout << "The list is empty!" << endl;
			}
			else
			{
				cout << "The tail value is: " << tail -> value << endl;
			}
		}		
/*********************************************************************
** Description: This method will print the list, provided it isn't
** empty.
*********************************************************************/	
		void printList()
		{
			if (numOfElements == 0)
			{
				cout << "The list is currently empty!" << endl;
			}
			else
			{
				ListNode* temp = head;
			
				while (temp != nullptr)
				{
					cout << "Int value: " << temp -> value << endl;
					temp = temp -> next;
				}
			}
		}
/*********************************************************************
** Description: This method will print the list in reverse order,
** provided it isn't empty.
*********************************************************************/
		void printListReverse()
		{
			if (numOfElements == 0)
			{
				cout << "The list is currently empty!" << endl;
			}
			else
			{
				ListNode* temp = tail;
				
				while (temp != nullptr)
				{
					cout << "Int value: " << temp -> value << endl;		
					temp = temp -> prev;
				}
			}
		}
/*********************************************************************
** Description: This method will first check to see if the list is empty.
** If not, it will iterate through, sum the values, and print it out.
*********************************************************************/
		void listSum()
		{
			if (numOfElements == 0)
			{
				cout << "The list is currently empty!" << endl;
			}
			else
			{
				ListNode* temp = head;
				int total = 0;
			
				while (temp != nullptr)
				{
					total += temp->value;
					temp = temp->next;
				}
				
				cout << "The sum of the list is: " << total << endl;
			}
		}
/*********************************************************************
** Description: Destructor that will iterate through the list and 
** delete each element
*********************************************************************/		
		~SimpleList()
		{
			ListNode* nav = head;
			ListNode* temp = head;
			
			while (nav != nullptr)
			{
				temp = nav;
				nav = temp->next;
				delete temp;
			}
		}
		
};
/*********************************************************************
** Running Instruction: This program doesn't use any command-line 
** arguments and is executed on the command line using the executable's
** name.
*********************************************************************/

int main()
{
	int userInput;
	int newValue = 0;
	
	SimpleList list;
	
	
	do
	{
		clearScreen();
		userInput = 0;
		
		cout << "************************************************" << endl;
		cout << "*                                              *" << endl;
		cout << "*                                              *" << endl;
		cout << "*            Linked List Operations            *" << endl;
		cout << "*                                              *" << endl;		
		cout << "*                                              *" << endl;
		cout << "************************************************" << endl << endl;
    
		cout << " 1) Add new value at the head" << endl;
		cout << " 2) Add new value at the tail" << endl;
		cout << " 3) Delete Head node" << endl;
		cout << " 4) Delete Tail node" << endl;
		cout << " 5) Print Head node" << endl;
		cout << " 6) Print Tail node" << endl;
		cout << " 7) Print the list" << endl;
		cout << " 8) Print the list (reverse)" << endl;
		cout << " 9) Sum the list" << endl;
		cout << "10) Exit" << endl;
		cout << endl;
		
		cout << "User Input: ";
		
		userInput = getInt();
		
		while (userInput < 1 and userInput > 10)
        {
            cout << endl << "Choice is not valid: Please choose 1-10.";
            cout << endl << "Choice: ";
            userInput = getInt();
        }
        
        switch (userInput)
        {
			// Add new value at the head
			case 1:			
				cout << "Enter value: " << endl;
				newValue = getInt();				
				list.addNodeHead(newValue);				
				pauseScreen();
				break;
			// Add new value at the tail
			case 2:				
				cout << "Enter value: " << endl;
				newValue = getInt();				
				list.addNodeTail(newValue);				
				pauseScreen();
				break;
			// Delete the head node
			case 3:
				list.deleteHead();
				pauseScreen();
				break;
			// Delete the tail node
			case 4:
				list.deleteTail();
				pauseScreen();
				break;
			// Print the head node
			case 5:
				list.printHead();
				pauseScreen();
				break;
			// Print the tail node
			case 6:
				list.printTail();
				pauseScreen();
				break;
			// Print the list
			case 7:
				list.printList();
				pauseScreen();
				break;
			// Print the list in reverse order
			case 8:
				list.printListReverse();
				pauseScreen();
				break;
			// Sum the list
			case 9:
				list.listSum();
				pauseScreen();
				break;
			case 10:
				break;
		}
	
	} while (userInput != 10);
	
	return 0;
}
