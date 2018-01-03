/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the _2Ptr class. This class
** is derived from the Square class and contains 3 methods: a default
** constructor, and overloaded constructor, and a destructor.
************************************************************************/

#include "_2Ptr.h" // _2Ptr header


/*************************************************************************
_2Ptr default constructor
derived from Square base class
Initializes a _2Ptr object and initializes the character and points
*************************************************************************/
_2Ptr::_2Ptr() : Square()
{
	character = ' ';
	points = 2;
}

/*************************************************************************
_2Ptr overloaded constructor
derived from Square base class
Initializes a _2Ptr object and initializes the row, column, character, and points
*************************************************************************/
_2Ptr::_2Ptr(int r, int c, char ch) : Square()
{
	row = r;
	col = c;
	character = ch;
	points = 2;
}

/*************************************************************************
_2Ptr destructor
*************************************************************************/
_2Ptr::~_2Ptr()
{
}
