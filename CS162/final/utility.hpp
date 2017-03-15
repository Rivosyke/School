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

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::cin;

enum c_color{BLACK=30,RED=31,GREEN=32,YELLOW=33,BLUE=34,MAGENTA=35,CYAN=36,WHITE=37};
enum c_decoration{NORMAL=0,BOLD=1,FAINT=2,ITALIC=3,UNDERLINE=4};

int menu();
int getInt();
double getDouble();
int randomNum(int modNumber);
void clearScreen();
void sleep(double time);
void seedRN();
void pauseScreen();
void printColor(const string str,c_color color,c_decoration decoration);

#endif // UTILITY_HPP
