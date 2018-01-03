/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the LebronJames class. This
** class is derived from the Player class and has 2 functions: a default
** constructor and a destructor.
************************************************************************/

#include "LebronJames.h"

/*************************************************************************
LebronJames default constructor
derived from Player base class constructor
Initializes a LebronJames object and initializes the variables
*************************************************************************/
LebronJames::LebronJames() : Player()
{
	name = "LeBron James";
	fgPct = 56.5;
	_3Pct = 40.6;
	initials = "LJ";
	number = "23";
}

/*************************************************************************
LebronJames destructor
*************************************************************************/
LebronJames::~LebronJames()
{
}
