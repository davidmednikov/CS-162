/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the Court class. This class
** has 1 member variable and 3 functions. The member variable is a 2D array
** of pointers to Square objects. It is defined as a 3D pointer. The functions
** are a constructor, a destructor, and an accessor function for the array.
************************************************************************/

#ifndef COURT
#define COURT

#include "Square.h" // Square header

class Court
{
	private:
		Square*** court; // 2D array of pointers

	public:
		Court(); // default constructor
		~Court(); // destructor
		Square*** getCourt(); // getCourt() accessor function
};

#endif