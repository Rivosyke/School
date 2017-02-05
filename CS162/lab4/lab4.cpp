/*********************************************************************
** Program Name: Lab 4
** Author: Ryan McGinn
** Date: 05 February 2017
** Description: This program will manually instantiate two Buildings,
** one Student, and one Instructor during calls to the University object's
** addBuilding and addPeople methods, respectively. The University's 
** programMenu method will then be called.
*********************************************************************/

#include <iostream>
#include "University.hpp"
#include "People.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "utility.hpp"


/*********************************************************************
** Running Instruction: This program doesn't use any command-line 
** arguments and is executed on the command line using the executable's
** name.
*********************************************************************/

int main()
{
    University OSU;
        
    OSU.addPeople(new Student("Frank Zappa"));
    OSU.addPeople(new Instructor("Albert Einstein"));
    OSU.addBuilding(new Building("Adams Hall", 
                                 "606 SW 15th St Corvallis, OR 97331",
                                 11168));   
    OSU.addBuilding(new Building("Agricultural & Life Sciences Building",
                                 "2750 SW Campus Way Corvallis, OR 97331",
                                 185629));
    

    OSU.programMenu();

    
    
    
	return 0;
}
