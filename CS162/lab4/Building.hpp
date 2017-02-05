/*********************************************************************
** Author: Ryan McGinn
** Date: 04 February 2017
** Description: This is the specification file for the Building class.
** This class has three data members: two strings and one int. There 
** are three get functions, a constructor, and a destructor.
*********************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>

using std::string;

class Building
{
	private:
		string name;
		string address;
		int sqft;
	public:
		Building(string tempName, string tempAddress, int tempSqft);
		~Building();
		string getAddress();
		string getName();
		int getSqft();
};
	


#endif // BUILDING_HPP
