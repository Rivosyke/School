/*********************************************************************
** Author: Ryan McGinn
** Date: 04 February 2017
** Description: This is the specification file for the Instructor class.
** This class has one data member: a double to represent the instructor
** rating. The constructor takes in the name for the instructor and 
** passes it to the People constructor as this class is inherited 
** from the People class. It overloads "do_work" from the People class.
*********************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "People.hpp"
#include "utility.hpp"
#include <iostream>

using std::cout;
using std::endl;

class Instructor : public People 
{
    private:
        double rating;
    public:
        Instructor(string tempName);
        void do_work(int work);
};        

#endif // INSTRUCTOR_HPP

