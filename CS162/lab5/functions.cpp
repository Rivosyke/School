/*********************************************************************
** Author: Ryan McGinn
** Date: 09 February 2017
** Description: This is the implementation file for the functions library.
** It contains the function definitions for this library.
*********************************************************************/

#include "functions.hpp"

/*********************************************************************
** Description: This function recusively outputs a string in reverse,
** one character at a time
*********************************************************************/
void reverse(string str)
{
	if (str.length() == 1)
	{
		cout << str;
        cout << '\n';
	}
	else
	{
		cout << str.at(str.length() - 1);
		reverse(str.substr(0,(str.length()-1)));
	}
}

/*********************************************************************
** Description: This function takes a pointer to an array and an int
** to hold the number of elements to be processed. It will recursively
** call itself to calculate the sum of the elements of the array.
*********************************************************************/
int sumArray(int* array, int elements)
{
    if (elements < 0)
    {
        return 0;
    }
    return array[elements] + sumArray(array, elements - 1);
}

/*********************************************************************
** Description: This function will take in an int and return the 
** triangular number calculation based on the user input.
*********************************************************************/
int triangleSum(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return num + triangleSum(num-1);
}
