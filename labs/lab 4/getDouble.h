/************************************************************************
** Program name: CS162 Project 2
** Author: David Mednikov
** Date: 02/01/17
** Description: This is the getDouble() function header file
************************************************************************/

#include <string>

#ifndef GET_DOUBLE_H
#define GET_DOUBLE_H

double getDouble(); // Prototype for getDouble method
double getDouble(double lowerBound); // Prototype for overloaded getDouble method with lowerbound only
double getDouble(double lowerBound, double higherBound); // Prototype for  overloaded getDouble method with bounds
double getDouble(double higherBound, std::string high); // Prototype for getDouble method with higherbound only

#endif