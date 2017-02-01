#include "Building.hpp"

Building::Building(string tempName, string tempAddress, int tempSqft)
{
	name = tempName;
	address = tempAddress;
	sqft = tempSqft;
}
Building::~Building()
{}
string Building::getAddress()
{
	return address;
}
string Building::getName()
{
	return name;
}
int Building::getSqft()
{
	return sqft;
}
