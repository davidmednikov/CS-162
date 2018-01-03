/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the OutOfBounds class. This 
** class is derived from the Square class and contains 3 methods: a default
** constructor, and overloaded constructor, and a destructor.
************************************************************************/

#ifndef OUT_OF_BOUNDS
#define OUT_OF_BOUNDS

#include "Square.h" // Square Base class header

class OutOfBounds : public Square
{
	public:
		OutOfBounds(); // default constructor
		OutOfBounds(int r, int c, char ch); // overloaded constructor
		~OutOfBounds(); // destructor
};

#endif