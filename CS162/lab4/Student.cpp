/*********************************************************************
** Author: Ryan McGinn
** Date: 04 February 2017
** Description: This is the implementation file for the Student class.
** It contains the function definitions and the constructor.
*********************************************************************/

#include "Student.hpp"


/*********************************************************************
** Description: This constructor calls the People constructor and passes
** it the string passed to the Student constructor. It also sets
** the gpa and age data members by calling appropriate randomNum
** functions.
*********************************************************************/
Student::Student(string tempName) : People(tempName)
{
	gpa = randomDouble(4);
	age = randomNum(55) + 18;
}

/*********************************************************************
** Description: This function is overloaded from the people class. It 
** takes in an integer and outputs a message.
*********************************************************************/
void Student::do_work(int work)
{
    cout << name << " did " << work << " hours of homework." << endl;
}
