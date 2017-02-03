#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "Person.hpp"
#include "Building.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class University 
{
    private:
        vector <Person*> personListing;
        vector <Building*> buildingListing;
        string uniName;
        
    public:
        University();
        ~University();
        void addPerson(Person* newPerson);
        void addBuilding(Building* newBuilding);
        void printPeople();
        void printBuildings();
        void programMenu();
        void printMenu();
        void subPeopleMenu();
};


#endif // UNIVERSITY_HPP
