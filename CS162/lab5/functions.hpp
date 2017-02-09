/*********************************************************************
** Author: Ryan McGinn
** Date: 09 February 2017
** Description: This is the specification file for the functions library.
** It contains the function declarations for this library. These 
** functions perform three actions: Reversing a string, summing an array
** of ints, and calculating triangular numbers.
*********************************************************************/

#include "utility.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void reverse(string str);
int sumArray(int* array, int elements);
int triangleSum(int num);
