#include "University.hpp"
#include "utility.hpp"



University::University()
{
    seedRN();
    uniName = "Oregon State University";
}
University::~University()
{
    for (unsigned int x = 0; x < personListing.size(); x++)
    {
        delete personListing[x];
    }
    for (unsigned int x = 0; x < buildingListing.size(); x++)
    {
        delete buildingListing[x];
    }
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
    cout << "University name: " << uniName << endl;
    cout << "Listing of all personnel in the system: " << endl;
    cout << "************************************************" << endl;
    
    for (unsigned int x = 0; x < personListing.size(); x++)
    {
        cout << personListing[x]->getName() << endl;
    }
}

void University::printBuildings()
{
    cout << "University name: " << uniName << endl;
    cout << "Listing of all buildings in the system: " << endl;
    cout << "************************************************" << endl;
    
    for (unsigned int x = 0; x < buildingListing.size(); x++)
    {
        cout << "Name   : " << buildingListing[x]->getName() << endl;
        cout << "Address: " << buildingListing[x]->getAddress() << endl;
        cout << endl;
    }
}

void University::programMenu()
{
    int userInput;
    do
    {
        clearScreen();
        printMenu();
        userInput = getInt();
    
        while ((userInput < 1) || (userInput > 4))
        {
            cout << endl << "Choice is not valid: Please choose 1-4.";
            cout << endl << "Choice: ";
            userInput = getInt();
        }
        
        switch (userInput)
        {
            case 1:
				clearScreen();
                printBuildings();
                cout << endl << "Hit enter to continue...";
                cin.get();
                break;
            case 2:
				clearScreen();
                printPeople();
				cout << endl << "Hit enter to continue...";
                cin.get();
                break;
            case 3:
                subPeopleMenu();
                break;
            case 4:
                break;
        }
        
    } while (userInput != 4);
    
}

void University::printMenu()
{
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*            Oregon State University           *" << endl;
    cout << "*               Information System             *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl << endl;
    
    cout << "1) Print Buildings" << endl;
    cout << "2) Print Personnel" << endl;
    cout << "3) Initiate Work" << endl;
    cout << "4) Exit Program" << endl;
    cout << "User Input: ";
}

void University::subPeopleMenu()
{
    clearScreen();
    
    unsigned int userInput = 0;
    
    cout << "************************************************" << endl;
    cout << "Choose a person: " << endl;
    for (unsigned int x = 0; x < personListing.size(); x++)
    {
        cout << x + 1 << ") " << personListing[x]->getName() << endl;
    }
    cout << endl << "User Input: ";
    
    userInput = getInt();
    
    while ((userInput < 1) || (userInput > personListing.size()))
    {
        cout << endl << "Choice is not valid: Please choose 1-" << personListing.size();
        cout << endl << "Choice: ";
        userInput = getInt();
    }
    
    cout << endl;
    personListing[userInput-1]->do_work(randomNum(1000));
    
	cout << endl << "Hit enter to continue...";
	cin.get();
    
}
    
