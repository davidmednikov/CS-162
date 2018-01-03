/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the StephCurry class. This
** class is derived from the Player class and has 2 functions: a default
** constructor and a destructor.
************************************************************************/

#include "StephCurry.h" // header

/*************************************************************************
StephCurry default constructor
derived from Player base class constructor
Initializes a StephCurry object and initializes the variables
*************************************************************************/
StephCurry::StephCurry() : Player()
{
	name = "Stephen Curry";
	fgPct = 50.4;
	_3Pct = 45.4;
	initials = "SC";
	number = "30";
}

/*************************************************************************
StephCurry destructor
*************************************************************************/
StephCurry::~StephCurry()
{
}
