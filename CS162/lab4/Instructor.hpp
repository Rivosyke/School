#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "Person.hpp"

class Instructor : public Person 
{
    private:
        double rating;
    public:
        Instructor(string tempName, int tempAge);
        void do_work(int work);
};        

#endif // INSTRUCTOR_HPP

