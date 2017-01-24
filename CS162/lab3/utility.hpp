/*********************************************************************
** Program Name: Project 1
** Author: Ryan McGinn
** Date: 20 January 2017
** Description: This program will implement Langont's Ant, a Turing
** machine that follow's two simple rules: 
** 1) On a blank char, flip the space to a #, turn right, move one
** 2) On a # char, flip the # to a blank, turn left, move one.
** The user will be prompted for various information: grid size,
** number of steps, speed of the simulation, and starting position of
** the ant. The simulation will then display each step until it is 
** finished.
*********************************************************************/

#ifndef UTILITY_HPP
#define UTILITY_HPP

int menu();
int getInt();
int randomNum(int modNumber);
int randomNum(int modNumber, int plusNumber);
void clearScreen();
void sleep(double time);

#endif // UTILITY_HPP
