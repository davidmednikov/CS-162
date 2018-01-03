/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the _3Ptr class. This class
** is derived from the Square class and contains 3 methods: a default
** constructor, and overloaded constructor, and a destructor.
************************************************************************/

#ifndef _3_PTR
#define _3_PTR

#include "Square.h" // Square Base class header

class _3Ptr : public Square
{
	public:
		_3Ptr(); // default constructor
		_3Ptr(int r, int c); // overloaded constructor
		~_3Ptr(); // destructor
};

#endif