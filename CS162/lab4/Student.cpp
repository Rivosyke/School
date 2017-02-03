#include "Student.hpp"
#include "Person.hpp"
#include <iostream>
#include "utility.hpp"

using namespace std;

Student::Student(string tempName) : Person(tempName)
{
	gpa = randomDouble(4);
}
void Student::do_work(int work)
{
    cout << name << " did " << work << " hours of homework." << endl;
}
