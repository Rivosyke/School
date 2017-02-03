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
        
    OSU.addPerson(new Student("Frank Zappa"));
    OSU.addPerson(new Instructor("Albert Einstein"));
    OSU.addBuilding(new Building("Adams Hall", 
                                 "606 SW 15th St Corvallis, OR 97331",
                                 11168));   
    OSU.addBuilding(new Building("Agricultural & Life Sciences Building",
                                 "2750 SW Campus Way Corvallis, OR 97331",
                                 185629));
    

    OSU.programMenu();

    
    
    
	return 0;
}
