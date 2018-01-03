/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the Shaq class. This
** class is derived from the Player class and has 2 functions: a default
** constructor and a destructor.
************************************************************************/

#ifndef SHAQ
#define SHAQ

#include "Player.h" // Player header

class Shaq : public Player
{
	public:
		Shaq(); // default constructor
		~Shaq(); // destructor
};

#endif