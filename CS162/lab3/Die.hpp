/*********************************************************************
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This is the specification file for the Die class.
** This class has one data member: an int to hold the number of sides
** that the Die will have. Input validation in main() will ensure
** that the number will be greater than 1.
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP


class Die
{
    protected:
        int numOfSides;
        
    public:
        Die(int);
        virtual ~Die();
        virtual int rollDice();
};
    

#endif // DIE_HPP
