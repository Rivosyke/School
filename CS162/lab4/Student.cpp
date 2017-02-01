#include "Student.hpp"
#include "Person.hpp"

Student::Student(string tempName, int tempAge) : People(tempName, tempAge)
{
	gpa = 0.0;
}
int Student::do_work(int work)
{
	return 0;
}
