/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the Shaq class. This
** class is derived from the Player class and has 2 functions: a default
** constructor and a destructor.
************************************************************************/

#include "Shaq.h" // header

/*************************************************************************
Shaq default constructor
derived from Player base class constructor
Initializes a Shaq object and initializes the variables
*************************************************************************/
Shaq::Shaq() : Player()
{
	name = "Shaquille O'Neal";
	fgPct = 60.1;
	_3Pct = 0.0;
	initials = "SO";
	number = "34";
}

/*************************************************************************
Shaq destructor
*************************************************************************/
Shaq::~Shaq()
{
}
