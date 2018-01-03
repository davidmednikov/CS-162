/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the _3Ptr class. This class
** is derived from the Square class and contains 3 methods: a default
** constructor, and overloaded constructor, and a destructor.
************************************************************************/

#include "_3Ptr.h" // _3Ptr header

/*************************************************************************
_3Ptr default constructor
derived from Square base class
Initializes a _3Ptr object and initializes the character and points
*************************************************************************/
_3Ptr::_3Ptr() : Square()
{
	character = ' ';
	points = 3;
}

/*************************************************************************
_3Ptr overloaded constructor
derived from Square base class
Initializes a _3Ptr object and initializes the row, column, character, and points
*************************************************************************/
_3Ptr::_3Ptr(int r, int c) : Square()
{
	row = r;
	col = c;
	character = ' ';
	points = 3;
}

/*************************************************************************
_3Ptr destructor
*************************************************************************/
_3Ptr::~_3Ptr()
{
}
