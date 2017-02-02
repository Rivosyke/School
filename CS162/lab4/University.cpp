#include "Person.hpp"
#include "University.hpp"
#include "Building.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "utility.hpp"

using std::cout;
using std::endl;

University::University()
{
    seedRN();
    uniName = "Oregon State University";
}
University::~University()
{
}

void University::addPerson(Person* newPerson)
{
    personListing.push_back(newPerson);
}
void University::addBuilding(Building* newBuilding)
{
    buildingListing.push_back(newBuilding);
}

void University::printPeople()
{
    clearScreen();
    cout << "Listing of all personnel in the system: " << endl;
    cout << "************************************************" << endl;
    
    for (unsigned int x = 0; x < personListing.size(); x++)
    {
        cout << personListing[x]->getName() << endl;
    }
}

void University::printBuildings()
{
    clearScreen();
    cout << "Listing of all buildings in the system: " << endl;
    cout << "************************************************" << endl;
    
    for (unsigned int x = 0; x < buildingListing.size(); x++)
    {
        cout << "Name   : " << buildingListing[x]->getName() << endl;
        cout << "Address: " << buildingListing[x]->getAddress() << endl;
        cout << endl;
    }
}
