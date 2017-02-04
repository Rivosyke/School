#include "Instructor.hpp"

Instructor::Instructor(string tempName) : Person(tempName)
{
	rating = randomDouble(5);
	age = randomNum(55) + 18;
}
void Instructor::do_work(int work)
{
    cout << "Instructor " << name << " graded papers for " << work << " hours." << endl;
}
