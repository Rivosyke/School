/*********************************************************************
** Author: Ryan McGinn
** Date: 04 February 2017
** Description: This is the specification file for the People class.
** This class has two data members: a string for the name and an int
** for the age. do_work is an abstract function that is virtualized
** and overloaded by other classes that inherit this class. 
*********************************************************************/

#ifndef PEOPLE_HPP
#define PEOPLE_HPP
#include <string>

using std::string;

class People
{
	protected:
		string name;
		int age;
	public:
		People(string tempName);
		virtual ~People();
		virtual void do_work(int work);
        string getName();
};
#endif // PEOPLE_HPP


