#include "Student.hpp"

Student::Student(string tempName) : Person(tempName)
{
	gpa = randomDouble(4);
	age = randomNum(55) + 18;
}
void Student::do_work(int work)
{
    cout << name << " did " << work << " hours of homework." << endl;
}
