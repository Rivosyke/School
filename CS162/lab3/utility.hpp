/*********************************************************************
** Author: Ryan McGinn
** Date: 26 January 2017
** Description: This is the specification file for the utility library.
** It contains the function declarations for this library. These 
** functions perform commonly called upon tasks in a program such as
** clearing the screen, making the program sleep (wait), and doing
** integer input validation.
*********************************************************************/

#ifndef UTILITY_HPP
#define UTILITY_HPP

int menu();
int getInt();
int randomNum(int modNumber);
void clearScreen();
void sleep(double time);
void seedRN();

#endif // UTILITY_HPP
