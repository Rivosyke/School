/*********************************************************************
** Author: Ryan McGinn
** Date: 26 February 2017
** Description: A struct to represent each object in the queue. It 
** contains three data members: pointers to a QueueNode and an int
** to hold the data.
*********************************************************************/

struct QueueNode
{
    QueueNode* prev;
    QueueNode* next;
    int data;
};
    
    
