/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the IvicaZubac class. This
** class is derived from the Player class and has 2 functions: a default
** constructor and a destructor.
************************************************************************/

#include "IvicaZubac.h" // header

/*************************************************************************
IvicaZubac default constructor
derived from Player base class constructor
Initializes a IvicaZubac object and initializes the variables
*************************************************************************/
IvicaZubac::IvicaZubac() : Player()
{
	name = "Ivica Zubac";
	fgPct = 100.0;
	_3Pct = 100.0;
	initials = "IZ";
	number = "40";
}

/*************************************************************************
IvicaZubac destructor
*************************************************************************/
IvicaZubac::~IvicaZubac()
{
}
