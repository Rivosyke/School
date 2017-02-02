#include "Person.hpp"
#include "Instructor.hpp"
#include "utility.hpp"
#include <iostream>

using std::cout;
using std::endl;

Instructor::Instructor(string tempName, int tempAge) : Person(tempName, tempAge)
{
	rating = randomDouble(5);
}
void Instructor::do_work(int work)
{
    cout << "Instructor " << name << " graded papers for " << work << " hours." << endl;
}
