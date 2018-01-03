/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the KobeBryant class. This
** class is derived from the Player class and has 2 functions: a default
** constructor and a destructor.
************************************************************************/

#include "KobeBryant.h" // header

/*************************************************************************
KobeBryant default constructor
derived from Player base class constructor
Initializes a KobeBryant object and initializes the variables
*************************************************************************/
KobeBryant::KobeBryant() : Player()
{
	name = "Kobe Bryant";
	fgPct = 45.9;
	_3Pct = 36.1;
	initials = "KB";
	number = "24";
}

/*************************************************************************
KobeBryant destructor
*************************************************************************/
KobeBryant::~KobeBryant()
{
}
