/*********************************************************************
** Author: Ryan McGinn
** Date: 14 February 2017
** Description: This is the specification file for the Die class.
** This class has one data member: an int to hold the number of sides
** that the Die will have. Input validation in main() will ensure
** that the number will be greater than 1.
*********************************************************************/

#include <iostream>
#include "utility.hpp"
#include "QueueNode.cpp"

using namespace std;

class Queue
{
    private:
        QueueNode* front;
        QueueNode* back;
        
    public:
        Queue();
        void addBack(int newItem);
        int getFront();
        void printQueue();
        int removeFront();
};
