/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the StephCurry class. This
** class is derived from the Player class and has 2 functions: a default
** constructor and a destructor.
************************************************************************/

#ifndef STEPH_CURRY
#define STEPH_CURRY

#include "Player.h" // Player header

class StephCurry : public Player
{
	public:
		StephCurry(); // default constructor
		~StephCurry(); // destructor
};

#endif