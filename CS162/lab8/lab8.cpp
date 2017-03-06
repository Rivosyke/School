#include <iostream>
#include "utility.hpp"
#include <fstream>

using namespace std;

void printMenu();
void menuFunctionality();

int main ()
{
	menuFunctionality();
	
	int array[10];
	
	ifstream infile("early.txt");
	
	int a = 0;
	int counter = 0;
	
	while (infile >> a)
	{
		array[counter] = a;
		cout << "Value: " << array[counter] << endl;
		counter++;
	}
	
	infile.close();
	
	return 0;
}


void printMenu()
{
	cout << "************************************************" << endl;
	cout << "*                                              *" << endl;
	cout << "*                                              *" << endl;
	cout << "*            Searching and sorting             *" << endl;
	cout << "*                                              *" << endl;		
	cout << "*                                              *" << endl;
	cout << "************************************************" << endl << endl;
    
	cout << " 1) Search for target value" << endl;
	cout << " 2) Sort values" << endl;
	cout << " 3) Search for target value (binary search)" << endl;
	cout << " 4) Exit" << endl;
	cout << endl;
}

void menuFunctionality()
{	
	int userInput = 0;	
	
	ifstream early("early.txt");
	ifstream mid("middle.txt");
	ifstream end("end.txt");

	do
	{   
		clearScreen();
		printMenu();
		userInput = 0;
		cout << "User Input: ";
		
		userInput = getInt();
		
		while (userInput < 1 and userInput > 4)
        {
            cout << endl << "Choice is not valid: Please choose 1-4.";
            cout << endl << "Choice: ";
            userInput = getInt();
     
		}	
        switch (userInput)
        {
			// Search for a value
			case 1:		
				ifstream* array[3];			
				array[0] = &early;
				array[1] = &mid;
				array[2] = &end;
				
				for (int x = 0; x < 3; x++)
				{
					int y = 0;
					while (*array[x] >> y)
					{
						cout << y << endl;
					}
				}
				
				pauseScreen();
				break;
			// Sort Values
			case 2:						
				pauseScreen();
				break;
			// Search for target (binary)
			case 3:
				pauseScreen();
				break;
			// Exit
			case 4:
				break;
		}
	
	} while (userInput != 4);
	
	early.close();
	mid.close();
	end.close();
	
}
	
