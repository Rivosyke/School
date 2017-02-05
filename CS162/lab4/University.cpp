/*********************************************************************
** Author: Ryan McGinn
** Date: 04 February 2017
** Description: This is the implementation file for the University class.
** It contains the function definitions, the constructor, and the 
** destructor.
*********************************************************************/

#include "University.hpp"
#include "utility.hpp"


/*********************************************************************
** Description: This constructor will seed the random number generator
** and set the uniName.
*********************************************************************/
University::University()
{
    seedRN();
    uniName = "Oregon State University";
}

/*********************************************************************
** Description: This destructor will iterate through both vectors and 
** delete all the elements within them.
*********************************************************************/
University::~University()
{
    for (unsigned int x = 0; x < peopleListing.size(); x++)
    {
        delete peopleListing[x];
    }
    for (unsigned int x = 0; x < buildingListing.size(); x++)
    {
        delete buildingListing[x];
    }
}

/*********************************************************************
** Description: This function takes in a pointer to people object
** and then pushes it onto the vector.
*********************************************************************/
void University::addPeople(People* newPeople)
{
    peopleListing.push_back(newPeople);
}

/*********************************************************************
** Description: This function takes in a pointer to building object
** and then pushes it onto the vector.
*********************************************************************/
void University::addBuilding(Building* newBuilding)
{
    buildingListing.push_back(newBuilding);
}

/*********************************************************************
** Description: This function outputs the names of the people in the
** peopleListing vector.
*********************************************************************/
void University::printPeople()
{
    clearScreen();
    cout << "University name: " << uniName << endl;
    cout << "Listing of all personnel in the system: " << endl;
    cout << "************************************************" << endl;
    
    for (unsigned int x = 0; x < peopleListing.size(); x++)
    {
        cout << peopleListing[x]->getName() << endl;
    }
}

/*********************************************************************
** Description: This function outputs the buildings in the
** buildingsListing vector.
*********************************************************************/
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


/*********************************************************************
** Description: This function implements the functionality outputted
** by the menu() function. It handles the user input, the input
** validation, and the resulting function calls based on the output.
*********************************************************************/
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

/*********************************************************************
** Description: This function outputs a menu showing the options 
** available to this information system
*********************************************************************/
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

/*********************************************************************
** Description: This function will implement the functionality from
** option 3 in the programMenu function. It will print out the names
** of all personnel in the peopleListing vector and prompt the user to
** choose a person to perform the work.
*********************************************************************/
void University::subPeopleMenu()
{
    clearScreen();
    
    unsigned int userInput = 0;
    
    cout << "************************************************" << endl;
    cout << "Choose a person: " << endl;
    
    // Iterates through the peopleListing vector to print all names
    for (unsigned int x = 0; x < peopleListing.size(); x++)
    {
        cout << x + 1 << ") " << peopleListing[x]->getName() << endl;
    }
    cout << endl << "User Input: ";
    
    userInput = getInt();
    
    // This ensure the user chooses a valid input
    while ((userInput < 1) || (userInput > peopleListing.size()))
    {
        cout << endl << "Choice is not valid: Please choose 1-" << peopleListing.size();
        cout << endl << "Choice: ";
        userInput = getInt();
    }
    
    cout << endl;
    
    // Uses the user's input to call the appropriate person's do_work function
    peopleListing[userInput-1]->do_work(randomNum(1000));
    
	cout << endl << "Hit enter to continue...";
	cin.get();
    
}
    
