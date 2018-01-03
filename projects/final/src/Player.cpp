/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the Player class
** Square class represents one "space" on the court, and the location of
** the player and the ball. The class has 10 member variables. There are 3
** ints representing the number of points that the square is worth, the
** row of the square, and the column of the square. There is a character
** variable for printing the court onto the screen, and four pointers to
** other Squares (up, down, left right). There are 4 accessor methods
** (for points, character, row, and col) and a pure virtual destructor.
************************************************************************/

#include "Player.h"
#include <stdlib.h> // seed for rand()
#include <iostream>

using std::string; // for strings and output
using std::cout;
using std::endl;

/*************************************************************************
Player default constructor
Initializes a Player object and defines each member
*************************************************************************/
Player::Player()
{
	ball; // define
	square = NULL;
	hasBall = false;
	inBounds = true;
	name;
	fgPct;
	_3Pct;
	initials;
	number;
	bagSize = 0;
}

/*************************************************************************
move()
params: char direction
returns: void
Moves the player in the direction entered by the user. If the player has
the ball, the function moves the ball with the player. It also checks to
see if the player is in bounds and updates the inbounds bool accordingly.
*************************************************************************/
void Player::move(char direction)
{
	if (direction == 'w') // up
	{
		square = square->up; // change pointer to square above current
		
		if (hasBall) // if player has ball
		{
			ball.move(direction); // move the ball as well
			
			if (square->up->getPoints() == -1) // check if the ball's square is out of bounds // out of bounds spaces have -1 in the points int
			{
				inBounds = false;
			}
		}
		else // player does not have ball
		{
			if (square->getPoints() == -1) // if current square is out of bounds
			{
				inBounds = false;
			}
		}
	}
	else if (direction == 'a') // left
	{
		square = square->left->left; // move 2 squares to the left (takes too long for user to step through every column)

		if (hasBall) // if player has ball
		{
			ball.move(direction); // move ball with player
		}
		if (square->getPoints() == -1) // check if player is out of bounds
		{
			inBounds = false;
		}
	}
	else if (direction == 's')
	{
		square = square->down; // move pointer to square below

		if (hasBall) // if player has ball
		{
			ball.move(direction); // move ball with player
		}
		if (square->down->getPoints() == -1) // check if player is out of bounds
		{
			inBounds = false;
		}
	}
	else
	{
		square = square->right->right;; // move 2 squares to the right (takes too long for user to step through every column)

		if (hasBall) // if player has ball
		{
			ball.move(direction); // move ball with player
		}
		
		if (square->right->getPoints() == -1) // check if player is out of bounds
		{
			inBounds = false;
		}
	}
}

/*************************************************************************
shoot()
params: none
returns: int
This function shoots the ball.vIt returns the number of points earned by 
the shot. Missed shots are 0, shots without the ball are -1, made field 
goals are 2, and made 3-pointers are 3.
*************************************************************************/
int Player::shoot()
{
	int points = ball.square->getPoints(); // get points of ball's square
	
	if (!hasBall) // player does not have ball and can't shoot
	{
		return -1; // doesn't have ball
	}
	else // player has ball
	{
		if (points == 2) // 2 pointer
		{
			if ((rand() % 100 + 1) <= fgPct) // if rand < fg percentage
			{
				return 2; // earned 2 points
			}

			return 0; // missed
			
		}

		else // 3 pointer
		{
			if ((rand() % 100 + 1) <= _3Pct) // if rand < 3pt percentage
			{
				return 3; // earned 3 points
			}
			
			return 0; // missed
		}
	}
}

/*************************************************************************
pickUpBall()
params: void
returns: void
Flips the hasBall bool from false to true when the player picks up the ball
*************************************************************************/
void Player::pickUpBall()
{
	hasBall = true;
	bagSize = 1;
}

/*************************************************************************
has_Ball()
params: void
returns: bool
Accesses the hasBall bool
*************************************************************************/
bool Player::has_Ball()
{
	return hasBall;
}

/*************************************************************************
in_Bounds()
params: void
returns: bool
Accesses the inBounds bool
*************************************************************************/
bool Player::in_Bounds()
{
	return inBounds;
}

/*************************************************************************
resetPlayer()
params: void
returns: void
Resets the player's bools. The game function resets the player's square.
*************************************************************************/
void Player::resetPlayer()
{
	square->unOccupy(); // make current square unoccupied
	inBounds = true; // flip to true just in case
	hasBall = false; // flip to false
	bagSize = 0; // empty bag
}

/*************************************************************************
getName()
params: void
returns: string
Accesses the player's name
*************************************************************************/
string Player::getName()
{
	return name;
}

/*************************************************************************
getInitials()
params: void
returns: string
Accesses the player's initials
*************************************************************************/
string Player::getInitials()
{
	return initials;
}

/*************************************************************************
getNumber()
params: void
returns: string
Accesses the player's number
*************************************************************************/
string Player::getNumber()
{
	return number;
}

/*************************************************************************
getRow()
params: void
returns: int
Accesses the player's row
*************************************************************************/
int Player::getRow()
{
	return square->getRow();
}

/*************************************************************************
getCol()
params: void
returns: int
Accesses the player's column
*************************************************************************/
int Player::getCol()
{
	return square->getCol();
}

/*************************************************************************
getBallRow()
params: void
returns: int
Accesses the ball's row
*************************************************************************/
int Player::getBallRow()
{
	return ball.getRow();
}

/*************************************************************************
getBallCol()
params: void
returns: int
Accesses the ball's column
*************************************************************************/
int Player::getBallCol()
{
	return ball.getCol();
}

/*************************************************************************
getBagSize()
params: void
returns: int
Accesses the size of the player's bag
*************************************************************************/
int Player::getBagSize()
{
	return bagSize;
}

/*************************************************************************
Player destructor
*************************************************************************/
Player::~Player()
{
}