#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"
#include <iostream>
#include "utility.hpp"

using std::cout;
using std::endl;

class Student : public Person 
{
	private:
		double gpa;
		
	public:
		Student(string tempName);
		void do_work(int work);
};

#endif // STUDENT_HPP
