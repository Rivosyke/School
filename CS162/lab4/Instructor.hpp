#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "Person.hpp"
#include "utility.hpp"
#include <iostream>

using std::cout;
using std::endl;

class Instructor : public Person 
{
    private:
        double rating;
    public:
        Instructor(string tempName);
        void do_work(int work);
};        

#endif // INSTRUCTOR_HPP

