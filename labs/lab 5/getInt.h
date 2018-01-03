/************************************************************************
** Program name: getInt() Utility Function
** Author: David Mednikov
** Date: 01/17/17
** Description: This is the getInt() function header file
************************************************************************/

#include <string>

#ifndef GET_INT_H
#define GET_INT_H

int getInt(); // Prototype for getInt method
int getInt(int lowerBound); // Prototype for overloaded getInt method with lowerbound only
int getInt(int lowerBound, int higherBound); // Prototype for  overloaded getInt method with bounds
int getInt(int higherBound, std::string high); // Prototype for getInt method with higherbound only

#endif