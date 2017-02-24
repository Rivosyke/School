/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the implementation file for the Die class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Queue.hpp"

Queue::Queue()
{
    QueueNode* temp = new QueueNode;
    
    temp -> next = temp;
    temp -> prev = temp;
    temp -> data = -1;
    
    front = temp;
    back = temp;
}

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


        
