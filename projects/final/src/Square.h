/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the Square abstract class. The
** Square class represents one "space" on the court, and the location of
** the player and the ball. The class has 8 member variables. There are 3 
** ints representing the number of points that the square is worth, the 
** row of the square, and the column of the square. There is a character 
** variable for printing the court onto the screen, and four pointers to 
** other Squares (up, down, left right). There are 4 accessor methods 
** (for points, character, row, and col) and a pure virtual destructor.
************************************************************************/

#ifndef SQUARE
#define SQUARE

class Square
{
	protected:
		int points; // points that the square is worth
		char character; // character to print court
		int row; // row of square
		int col; // column of square
		bool occupied; // occupied by player

	public:
		Square(); // default constructor
		void occupy(); // occupy the space
		void unOccupy(); // unoccupy the space
		Square* up; // pointer to square above
		Square* left; // pointer to left square
		Square* right; // pointer to right square
		Square* down; // pointer to square below
		int getPoints(); // points accessor
		char getChar(); // character accessor
		int getRow(); // row accessor
		int getCol(); // column accessor
		bool getOccupied(); // get occupied bool
		virtual ~Square() = 0; // pure virtual destructor, Square is an abstract class
};

#endif
