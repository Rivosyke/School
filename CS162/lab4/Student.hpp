#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

class Student : public Person 
{
	private:
		double gpa;
		
	public:
		Student(string tempName, int tempAge);
		int do_work(int work);
};

#endif // STUDENT_HPP
