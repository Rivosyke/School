/*********************************************************************
** Author: Ryan McGinn
** Date: 20 March 2017
** Description: This is the specification file for the Space class.
** This class has four data members: four pointers to other Space 
** objects that will actually be derived classes. 
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
    protected:
        Space* Up;
        Space* Right;
        Space* Down;
        Space* Left;
    
    public:
        Space(Space* tempUp, Space* tempRight, Space* tempDown, Space* tempLeft);
        virtual ~Space();
        virtual void displayDesc();
        virtual void specialAction();
};

#endif // SPACE_HPP


