#include "Student.hpp"
#include "Person.hpp"
#include <iostream>
#include "utility.hpp"

using namespace std;

Student::Student(string tempName, int tempAge) : Person(tempName, tempAge)
{
	gpa = randomDouble(4);
}
void Student::do_work(int work)
{
    cout << name << " did " << work << " hours of homework." << endl;
}
