#include "Person.hpp"

Person::Person(string tempName, int tempAge)
{
	name = tempName;
	age = tempAge;
}
	
Person::~Person()
{}
void Person::do_work(int work)
{
}
string Person::getName()
{
    return name;
}

