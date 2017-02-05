/*********************************************************************
** Author: Ryan McGinn
** Date: 04 February 2017
** Description: This is the specification file for the University class.
** This class has three data members: two vectors to hold people and
** buildings and a string for the university name. There are two setters
** and 4 printing functions.
*********************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "People.hpp"
#include "Building.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

class University 
{
    private:
        vector <People*> peopleListing;
        vector <Building*> buildingListing;
        string uniName;
        
    public:
        University();
        ~University();
        void addPeople(People* newPeople);
        void addBuilding(Building* newBuilding);
        void printPeople();
        void printBuildings();
        void programMenu();
        void printMenu();
        void subPeopleMenu();
};


#endif // UNIVERSITY_HPP
