/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the Ball Class. The ball class has
** a pointer to it's square (location on the court), a default constructor, 2
** member functions, and a destructor. The functions are move, getRow, and GetCol.
************************************************************************/

#include "Ball.h" // Ball header file

/*************************************************************************
Ball default constructor
Initializes a Ball object and makes its pointer null
*************************************************************************/
Ball::Ball()
{
	square = nullptr;
}

/*************************************************************************
move(char d)
returns: void
params: char direction
Moves the ball in the direction provided as an arguments
*************************************************************************/
void Ball::move(char direction)
{
	if (direction == 'w') // move up
	{
		square = square->up; // change square pointer to square above
	}
	else if (direction == 'a') // move left
	{
		square = square->left->left; // change square pointer to square to the left
	}
	else if (direction == 's') // move down
	{
		square = square->down; // change square pointer to square below
	}
	else // move right
	{
		square = square->right->right; // change square pointer to square to the right
	}
}

/*************************************************************************
getRow()
returns: int
params: none
Access the ball's row
*************************************************************************/
int Ball::getRow()
{
	return square->getRow();
}

/*************************************************************************
getCol()
returns: int
params: none
Access the ball's column
*************************************************************************/
int Ball::getCol()
{
	return square->getCol();
}

/*************************************************************************
Ball destructor
*************************************************************************/
Ball::~Ball()
{
}
