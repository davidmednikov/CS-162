/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the KobeBryant class. This
** class is derived from the Player class and has 2 functions: a default
** constructor and a destructor.
************************************************************************/

#ifndef KOBE_BRYANT
#define KOBE_BRYANT

#include "Player.h" // Player header

class KobeBryant : public Player
{
	public:
		KobeBryant(); // default constructor
		~KobeBryant(); // destructor
};

#endif