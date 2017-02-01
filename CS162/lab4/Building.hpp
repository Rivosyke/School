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
