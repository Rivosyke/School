#include "CreatureList.hpp"

/*********************************************************************
** Description: The constructor will set the pointers to nullptr and
** numOfElements to 0.
*********************************************************************/
CreatureList::CreatureList()
{
	head = nullptr;
	tail = nullptr;
	numOfElements = 0;
}

/*********************************************************************
** Description: Destructor that will iterate through the list and 
** delete each element
*********************************************************************/		
CreatureList::~CreatureList()
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

/*********************************************************************
** Description: This method will print the list in reverse order,
** provided it isn't empty.
*********************************************************************/
void CreatureList::printListReverse()
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
			cout << "Monster: " << temp -> monster -> getName() << endl;		
			temp = temp -> prev;
		}
	}
}
		
/*********************************************************************
** Description: This method will print the last item in the list,
** provided it isn't empty.
*********************************************************************/		
void CreatureList::printTail()
{
	if (numOfElements == 0)
	{
		cout << "The list is empty!" << endl;
	}
	else
	{
	//	cout << "The tail value is: " << tail -> value << endl;
	}
}	

/*********************************************************************
** Description: This method will print the list, provided it isn't
** empty.
*********************************************************************/	
void CreatureList::printList()
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
			cout << "Monster: " << temp -> monster -> getName() << endl;
			temp = temp -> next;
		}
	}
}

/*********************************************************************
** Description: This method will delete the last element in the list
** provided it isn't empty.
*********************************************************************/		
void CreatureList::deleteTail()
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
	//	cout << "The new tail is now: " << tail -> value << endl;
	}
}
		
/*********************************************************************
** Description: This method will delete the first element in the list,
** provided the list isn't empty.
*********************************************************************/
void CreatureList::deleteHead()
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
	//	cout << "The new head is now: " << head -> value << endl;
	}
}
		
/*********************************************************************
** Description: This method will print the first element in the list
** provided the list isn't empty.
*********************************************************************/		
void CreatureList::printHead()
{
	if (numOfElements == 0)
	{
		cout << "The list is empty!" << endl;
	}
	else
	{
		//cout << "The head value is: " << head -> value << endl;
	}
}
		
/*********************************************************************
** Description: This method will add a node to the back of the list.
*********************************************************************/		
void CreatureList::addNodeTail(Creature* newMonster)
{
	ListNode* temp = new ListNode;
			
	temp -> monster = newMonster;
		
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
** Description: This method will add a node to the front of the list.
*********************************************************************/	
void CreatureList::addNodeHead(Creature* newMonster)
{
	ListNode* temp = new ListNode;
			
	temp -> monster = newMonster;
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
