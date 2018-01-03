/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the LonzoBall class. This
** class is derived from the Player class and has 3 functions: a default
** constructor, a destructor, and shoot(), which overrides the Player base class.
************************************************************************/

#include "LonzoBall.h" // header

/*************************************************************************
LonzoBall default constructor
derived from Player base class constructor
Initializes a LonzoBall object and initializes the variables
*************************************************************************/
LonzoBall::LonzoBall()
{
	name = "Lonzo Ball";
	fgPct = 100.0;
	_3Pct = 100.0;
	initials = "LB";
	number = "02";
}

/*************************************************************************
LonzoBall destructor
*************************************************************************/
LonzoBall::~LonzoBall()
{
}

/*************************************************************************
shoot()
params: none
returns int
Lonzo Ball can't miss, so he automatically gets the number of points from
where the ball is shot. He gets points even if he's not holding the ball.
*************************************************************************/
int LonzoBall::shoot()
{
	return ball.square->getPoints();
}