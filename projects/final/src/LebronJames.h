/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the LebronJames class. This
** class is derived from the Player class and has 2 functions: a default
** constructor and a destructor.
************************************************************************/

#ifndef LEBRON_JAMES
#define LEBRON_JAMES

#include "Player.h" // Player header

class LebronJames : public Player
{
	public:
		LebronJames(); // default constructor
		~LebronJames(); // destructor
};

#endif