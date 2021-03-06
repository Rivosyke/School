/*********************************************************************
** Author: Ryan McGinn
** Date: 04 February 2017
** Description: This is the implementation file for the Building class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Building.hpp"

/*********************************************************************
** Description: This constructor takes in two stings and an int. It 
** then assigns them to the appropriate data members.
*********************************************************************/
Building::Building(string tempName, string tempAddress, int tempSqft)
{
	name = tempName;
	address = tempAddress;
	sqft = tempSqft;
}

/*********************************************************************
** Description: This destructor does nothing.
*********************************************************************/
Building::~Building()
{}

/*********************************************************************
** Description: This function returns the address data member.
*********************************************************************/
string Building::getAddress()
{
	return address;
}

/*********************************************************************
** Description: This function returns the name data member.
*********************************************************************/
string Building::getName()
{
	return name;
}

/*********************************************************************
** Description: This function returns the sqft data member.
*********************************************************************/
int Building::getSqft()
{
	return sqft;
}
