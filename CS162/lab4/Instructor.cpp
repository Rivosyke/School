/*********************************************************************
** Author: Ryan McGinn
** Date: 04 February 2017
** Description: This is the implementation file for the Instructor class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "Instructor.hpp"

/*********************************************************************
** Description: This constructor calls the People constructor and passes
** it the string passed to the Instructor constructor. It also sets
** the rating and age data members by calling appropriate randomNum
** functions.
*********************************************************************/
Instructor::Instructor(string tempName) : People(tempName)
{
	rating = randomDouble(5);
	age = randomNum(55) + 18;
}

/*********************************************************************
** Description: This function is overloaded from the people class. It 
** takes in an integer and outputs a message.
*********************************************************************/
void Instructor::do_work(int work)
{
    cout << "Instructor " << name << " graded papers for " << work << " hours." << endl;
}
