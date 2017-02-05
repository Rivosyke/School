/*********************************************************************
** Author: Ryan McGinn
** Date: 04 February 2017
** Description: This is the implementation file for the People class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "People.hpp"

/*********************************************************************
** Description: This constructor takes in a string and assigns it to
** the name data member.
*********************************************************************/
People::People(string tempName)
{
	name = tempName;
}

/*********************************************************************
** Description: This destructor does nothing.
*********************************************************************/
People::~People()
{}

/*********************************************************************
** Description: This function is overloaded by the two inherited 
** classes and does nothing on its own.
*********************************************************************/
void People::do_work(int work)
{
}

/*********************************************************************
** Description: This function returns the name data member.
*********************************************************************/
string People::getName()
{
    return name;
}
