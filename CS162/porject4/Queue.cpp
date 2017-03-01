/*********************************************************************
** Author: Ryan McGinn
** Date: 26 February 2017
** Description: This is the implementation file for the Queue class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Queue.hpp"

/*********************************************************************
** Description: Constructor that calls the Creature constructor and
** allocates the memory for the Die objects.
*********************************************************************/
Queue::Queue()
{
    QueueNode* temp = new QueueNode;
    
    temp -> next = temp;
    temp -> prev = temp;
    temp -> data = -1;
    
    front = temp;
    back = temp;
}

/*********************************************************************
** Description: This method will add an int onto the back of the queue.
** If the queue is full, it will create a new node to store the data.
*********************************************************************/
void Queue::addBack(int newItem)
{
    // Checks if the Queue is full
    if (back -> next -> data != -1)
    {
        QueueNode* temp = new QueueNode;
        temp -> data = newItem;
        temp -> prev = back;
        temp -> next = back -> next;
        back -> next = temp;
        back = temp;
    }
    else
    {
        back -> next -> data = newItem;
    }
}

/*********************************************************************
** Description: This method will return an int with the value of the
** the front of the queue. If the queue is empty, a -1 is returned.
*********************************************************************/
int Queue::getFront()
{
    // This will indicate the queue is empty
    if (front -> data == -1)
    {
        return -1;
    }
    else
    {
        return front -> data;
    }
}

/*********************************************************************
** Description: This method traverses the queue, starting at the front
** and will output the values stored in it.
*********************************************************************/
void Queue::printQueue()
{
    QueueNode* temp = front -> next;

    // Checks to see if the queue has no data
    if (front -> data != -1)
    {
        // Prints out the first value;
        cout << "Value : " << front -> data << endl;
    
        while (temp != front and temp -> data != -1)
        {
            cout << "Value : " << temp -> data << endl;
            temp = temp -> next;
        }
    }
    else
    {
        cout << "Queue is empty!" << endl;
    }
}

/*********************************************************************
** Description: This method will remove the front of the queue. It 
** will not delete the object but rather set the value to -1 and move
** the front pointer to the next object.
*********************************************************************/
int Queue::removeFront()
{
    if (front -> data == -1)
    {
        return -1;
    }
    else
    {
        int temp = front -> data;
        front -> data = -1;
        front = front -> next;
        return temp;
    }
}

/*********************************************************************
** Description: Destructor that traverses the queue and deletes all
** objects.
*********************************************************************/
Queue::~Queue()
{
    QueueNode* temp = front -> next;
    QueueNode* tempDel = temp;

	while (temp != front)
	{
		tempDel = temp;
		temp = temp -> next;
		delete tempDel;
	}
	
	delete temp;
	delete tempDel;
	temp = nullptr;
	tempDel = nullptr;
}

        
