/*********************************************************************
** Author: Ryan McGinn
** Date: 26 February 2017
** Description: This is the specification file for the Queue class.
** This class has two data members: pointers to QueueNodes that represent
** the front and back of the Queue.
*********************************************************************/

#include <iostream>
#include "utility.hpp"
#include "QueueNode.cpp"

using std::cout;
using std::endl;

class Queue
{
    private:
        QueueNode* front;
        QueueNode* back;
        
    public:
        Queue();
        ~Queue();
        void addBack(int newItem);
        int getFront();
        void printQueue();
        int removeFront();
};
