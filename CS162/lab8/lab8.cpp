#include <iostream>
#include "utility.hpp"
#include <fstream>
#include <string>

using namespace std;

void printMenu();
void menuFunctionality();
void linearSearch(int array[][10], int size);
int bubbleSort(string fileName, int array[][10], int size);
int binarySearch(int array[][10], int size, int value, int fileChoice);

int main ()
{
	menuFunctionality();
	
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
	string userFileName;
	
	
	ifstream early("early.txt");
	ifstream mid("middle.txt");
	ifstream end("end.txt");
	
	ifstream* array[3];			
	array[0] = &early;
	array[1] = &mid;
	array[2] = &end;
	
	int fileValue[3][10];	
	int tempInput = 0;	
	int counter = 0;
	int binarySearchValue = 0;
	int fileChoice = 0;
	bool sorted= false;
	
	// Reads in the data from the files and assigns it to the 2D int array
	for (int x = 0; x < 3; x++)
	{
		counter = 0;
		while (*array[x] >> tempInput)
		{
			fileValue[x][counter] = tempInput;
			counter++;
		}
	}
		
	early.close();
	mid.close();
	end.close();
	
	
	do
	{   
		clearScreen();
		printMenu();
		userInput = 0;
		cout << "User Input: ";
		
		userInput = getInt();
		
		while (userInput < 1 or userInput > 4)
        {
            cout << endl << "Choice is not valid: Please choose 1-4.";
            cout << endl << "Choice: ";
            userInput = getInt();
     
		}	
        switch (userInput)
        {
			// Search for a value
			// Basic idea of the code is from the "Searching" PDF, slide 6.
			case 1:		
				linearSearch(fileValue, 10);
				pauseScreen();
				break;
			// Sort Values
			case 2:
				cout << "Please enter a filename for the output file." << endl;
				cout << "User Input: ";
				getline(cin, userFileName);
				bubbleSort(userFileName, fileValue, 10);
				sorted = true;
				pauseScreen();
				break;
			// Search for target (binary)
			case 3:
				if (!sorted)
				{
					cout << "Can't do a binary search without sorted data!" << endl;
					cout << "Please sort the data first with option 2." << endl;
					pauseScreen();
				}
				else
				{

					cout << "Which file to search in? (1-3) ";
					fileChoice = getInt();
					while (fileChoice < 1 or fileChoice > 3)
					{
						cout << "File choice must be between 1 and 3" << endl;
						cout << "Input again: ";
						fileChoice = getInt();
					}
					cout << "Value to search for: ";
					binarySearchValue = getInt();
					cout << endl;
					
					int result = binarySearch(fileValue, 10, binarySearchValue, fileChoice);
					
					if (result == -1)
					{
						cout << "Value not found in that file." << endl;
					}
					else
					{
						cout << "Value " << binarySearchValue
							 << "found at position " << result 
							 << "in file " << fileChoice << endl;
					}
					pauseScreen();
				}
				break;
			// Exit
			case 4:
				break;
		}
	
	} while (userInput != 4);

	
}

void linearSearch(int array[][10], int size)
{
	cout << "File 1: early.txt" << endl;
	cout << "File 2: middle.txt" << endl;
	cout << "File 3: late.txt" << endl;				
		
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < size; y++)
		{	
			if (array[x][y] == 0)
			{
				cout << "Value '0' found at position "
				 << y + 1 << " in file number " << x + 1 << endl;
			}
		}
	}
}

// Bubble sort from the Sort-Bubble.pdf, slide 5
int bubbleSort(string fileName, int array[][10], int size)
{
	ofstream output(fileName);
	
	// Triple for loop to handle all the 2D array elements
	for (int x = 0; x < 3; x++)
	{
		for (int i = (size-1); i >= 0; i--)
		{
			for (int j = 1; j <= i; j++)
			{
				if (array[x][j-1] > array[x][j])
				{
					int temp = array[x][j-1];
					array[x][j-1] = array[x][j];
					array[x][j] = temp;
				}
			}
		}
	}
	
	for (int y = 0; y < size; y++)
	{
		output << array[0][y] << '\n';
	}
	
	
	output.close();
	
	return 0;
}

// Binary search from Searching.pdf, slide 11
int binarySearch(int array[][10], int size, int value, int fileChoice)
{
	
	int low = 0;
	int high = size -1;
	
	while (low <= high)
	{
		int mid = (low + high)/2;
		if (array[fileChoice][mid] == value)
		{
			return mid + 1;
		}
		else if (array[fileChoice][mid] < value)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	
	return -1;
}
	
