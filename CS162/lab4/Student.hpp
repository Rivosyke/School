/*********************************************************************
** Author: Ryan McGinn
** Date: 04 February 2017
** Description: This is the specification file for the Student class.
** This class has one data member: a double that represents the GPA of
** the student. It is set by a random number. do_work is overloaded 
** from the People class.
*********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "People.hpp"
#include <iostream>
#include "utility.hpp"

using std::cout;
using std::endl;

class Student : public People 
{
	private:
		double gpa;
		
	public:
		Student(string tempName);
		void do_work(int work);
};

#endif // STUDENT_HPP
