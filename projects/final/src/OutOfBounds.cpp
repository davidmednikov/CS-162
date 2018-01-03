/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the OutOfBounds class. This
** class is derived from the Square class and contains 3 methods: a default
** constructor, and overloaded constructor, and a destructor.
************************************************************************/

#include "OutOfBounds.h"


/*************************************************************************
OutOfBounds default constructor
derived from Square base class
Initializes a OutOfBounds object and initializes the character and points
*************************************************************************/
OutOfBounds::OutOfBounds() : Square()
{
	character = '/';
	points = -1;
}

/*************************************************************************
OutOfBounds overloaded constructor
derived from Square base class
Initializes a OutOfBounds object and initializes the row, column, character, and points
*************************************************************************/
OutOfBounds::OutOfBounds(int r, int c, char ch) : Square()
{
	row = r;
	col = c;
	character = ch;
	points = -1;
}

/*************************************************************************
OutOfBounds destructor
*************************************************************************/
OutOfBounds::~OutOfBounds()
{
}
