#include "Person.hpp"

Person::Person(string tempName)
{
	name = tempName;
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

