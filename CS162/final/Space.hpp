/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the specification file for the Vampire class.
** This class has two data members: two pointers to Die objects that 
** represent attack and defense die. It inherits other data members
** and methods from the Creature super class.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

enum Direction {Up, Right, Left, Down};


class Space
{
    private:
        Space* Up;
        Space* Right;
        Space* Down;
        Space* Left;
    
    public:
        Space(Space*, Space*, Space*, Space*);
        ~Space();
        virtual void displayDesc();
};

#endif // SPACE_HPP


