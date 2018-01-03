/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the _2Ptr class. This class
** is derived from the Square class and contains 3 methods: a default
** constructor, and overloaded constructor, and a destructor.
************************************************************************/

#ifndef _2_PTR
#define _2_PTR

#include "Square.h" // Square Base class header

class _2Ptr : public Square
{
	public:
		_2Ptr(); // default constructor
		_2Ptr(int r, int c, char ch); // overloaded constructor
		~_2Ptr(); // destructor
};

#endif