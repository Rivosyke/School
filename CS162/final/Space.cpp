/*********************************************************************
** Author: Ryan McGinn
** Date: 18 February 2017
** Description: This is the implementation file for the Space class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Space.hpp"


/*********************************************************************
** Description: Constructor that sets the passed in values to their 
** appropriate data member.
*********************************************************************/
Space::Space(Space* tempUp, 
             Space* tempRight, 
             Space* tempDown, 
             Space* tempLeft, 
             string tempName)
{
    Up = tempUp;
    Right = tempRight;
    Down = tempDown;
    Left = tempLeft;
    name = tempName;
}

/*********************************************************************
** Description: Destructor that does nothing.
*********************************************************************/
Space::~Space()
{}

/*********************************************************************
** Description: Method that returns the name of the space
*********************************************************************/
string Space::getName()
{
    return name;
}

/*********************************************************************
** Description: Method that will set a space's up/right/down/left
** Space pointers to a specific object using a direction and the ptr
** itself.
*********************************************************************/
void Space::setDirectionPointer(Space* spaceToSet, direction position)
{
	switch(position)
	{
		case UP:
			Up = spaceToSet;
			break;
		case RIGHT:
			Right = spaceToSet;
			break;
		case DOWN:
			Down = spaceToSet;
			break;
		case LEFT:
			Left = spaceToSet;
	}
}	

/*********************************************************************
** Description: Method that will take in a vector of Space pointers
** and fill that vector with Spaces connected to the current Space.
*********************************************************************/
void Space::fillSpaceVector(vector<Space*> *availableRooms)
{
	if (Up)
	{
		availableRooms -> push_back(Up);
	}
	if (Right)
	{
		availableRooms -> push_back(Right);
	}
	if (Down)
	{
		availableRooms -> push_back(Down);
	}
	if (Left)
	{
		availableRooms -> push_back(Left);
	}
}
