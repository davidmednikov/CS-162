/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the Player class. The player
** class has 10 variables: bools representing the possession of the ball
** and being in bounds, doubles representing their field goal and 3-point
** percentages, strings holding their name, number, and initials, a ball,
** and a pointer to a Square, representing the location of the player.
** The Player class has 15 member functions, described in the source file.
************************************************************************/

#ifndef PLAYER
#define PLAYER

#include "Ball.h" // Ball header
#include "Square.h" // Square header
#include <string> // fo stringz

class Player
{
	protected:
		int bagSize; // max number of items
		bool hasBall; // bool for playing posessing the ball
		bool inBounds; // bool for player being in bounds
		double fgPct; // double for player's field goal percentage
		double _3Pct; // double for player's 3-point percentage
		std::string name; // string holding name
		std::string initials; // string holding initials
		std::string number; // string holding number


	public:
		Player(); // default constructor
		Ball ball; // ball object
		Square* square; // pointer to Square (player's location)
		virtual ~Player(); // virtual destructor
		void move(char direction); // move player
		virtual int shoot(); // shoot ball
		void pickUpBall(); // gain possession of the ball
		bool has_Ball(); // access hasBall bool
		bool in_Bounds(); // access inBounds bool
		void resetPlayer(); // reset player's location and bools
		std::string getName(); // name accessor
		std::string getInitials(); // initials accessor
		std::string getNumber(); // number accessor
		int getRow(); // row accessor
		int getCol(); // col accessor
		int getBallRow(); // ball's row accessor
		int getBallCol(); // ball's col accessor
		int getBagSize(); // bag size accessor
};

#endif