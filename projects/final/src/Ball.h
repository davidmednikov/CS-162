/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the Ball Class. The ball class has
** a pointer to it's square (location on the court), a default constructor, 2
** member functions, and a destructor. The functions are move, getRow, and GetCol.
************************************************************************/

#ifndef BALL
#define BALL

#include "Square.h"

class Ball
{
	public:
		Square* square; // pointer to location on the court
		Ball(); // default constructor
		void move(char direction); // move the ball
		int getRow(); // row accessor
		int getCol(); // column accessor
		~Ball(); // destructor
};

#endif