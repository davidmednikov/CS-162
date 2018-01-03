/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the LonzoBall class. This
** class is derived from the Player class and has 3 functions: a default
** constructor, a destructor, and shoot(), which overrides the base class.
************************************************************************/

#ifndef LONZO_BALL
#define LONZO_BALL

#include "Player.h" // Player header

class LonzoBall : public Player
{
	public:
		LonzoBall(); // default constructor
		~LonzoBall(); // destructor
		int shoot(); // shoot the ball, overrides base class
};

#endif