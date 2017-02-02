#include <iostream>
#include "University.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "utility.hpp"

using namespace std;

int main()
{
    University OSU;
    
    Person* student1 = new Student("Frank Zappa", 30);
    
    OSU.addPerson(student1);
    
    OSU.printPeople();
    

    
    
    
	return 0;
}
