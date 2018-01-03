/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the Square abstract class. The
** Square class represents one "space" on the court, and the location of
** the player and the ball. The class has 8 member variables. There are 3 
** ints representing the number of points that the square is worth, the 
** row of the square, and the column of the square. There is a character 
** variable for printing the court onto the screen, and four pointers to 
** other Squares (up, down, left right). There are 4 accessor methods 
** (for points, character, row, and col) and a pure virtual destructor.
************************************************************************/

#include "Square.h" // Square header file

/*************************************************************************
Square default constructor
Initializes a Square object and initializes each member
*************************************************************************/
Square::Square()
{
	Square* up = nullptr; // initialize points as null
	Square* left = nullptr;
	Square* right = nullptr;
	Square* down = nullptr;
	occupied = false;
	points; // define other variables
	character;
	row;
	col;
}

/*************************************************************************
getChar()
returns: char
params: none
Access the character variable
*************************************************************************/
char Square::getChar()
{
	return character;
}

/*************************************************************************
getPoints()
returns: int
params: none
Access the points variable
*************************************************************************/
int Square::getPoints()
{
	return points;
}

/*************************************************************************
getRow()
returns: int
params: none
Access the row variable
*************************************************************************/
int Square::getRow()
{
	return row;
}

/*************************************************************************
getCol()
returns: int
params: none
Access the column variable
*************************************************************************/
int Square::getCol()
{
	return col;
}


/*************************************************************************
occupy()
returns: none
params: none
Make the occupied bool true
*************************************************************************/
void Square::occupy()
{
	occupied = true;
}

/*************************************************************************
unOccupy()
returns: none
params: none
Make the occupied bool false
*************************************************************************/
void Square::unOccupy()
{
	occupied = false;
}

/*************************************************************************
getOccupied()
returns: bool
params: none
Access the occupied bool, return true if the player is there and false if not
*************************************************************************/
bool Square::getOccupied()
{
	return occupied;
}

Square::~Square()
{
}