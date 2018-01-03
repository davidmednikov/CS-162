/*********************************************************************************
** Program name: CS162 Project 1
** Author: David Mednikov
** Date: 01/17/17
** Description: This is the specification file for the Ant class. This class has 3 
** member variables: the direction the ant is facing, and the row and column that 
** the ant is located in. The class has 6 member functionss, one of which is the
** constructor. The constructor takes two variables: the starting row and starting 
** column of the ant. There is a function called moveAnt() that moves the ant one space. 
** There are also two functions that are called depending on whether or not the ant
** hits a white square or a black square. The class also has two methods to access
** the row and column of the ant. If the ant hits the edge of the board, it wraps
** around to the other side.
********************************************************************************/

#include "Ant.h" // Ant header file

/*Ant::Ant()       // Default Constructor used only for testing
{
    row = 13;
    column = 25;
    direction = NORTH;
}*/

/*************************************************************************
Constructor that takes the row and the column of the ant as parameters and initializes the ant at those coordinates facing north.
*************************************************************************/
Ant::Ant(int r0w, int col)
{
    row = r0w; // initalize row
    column = col; // initialize column
    direction = NORTH; // start off ant facing north
}

/*************************************************************************
This function moves the ant one space. Its parameters are a pointer to a 2d
array, the color of the square being occupied by the ant, the max number of
rows, and the max number of columns. If the square being occupied is white,
this method calls the hitWhiteSquare() function. If the square is black,
the hitBlackSquare() function is called.
*************************************************************************/
void Ant::moveAnt(int** board, int thisSquare, int maxRows, int maxColumns)
{    
    // 0 represents a white square
    if (thisSquare == 0)
    {
        // call hitWhiteSquare function, pass pointer to array, maxRows, and maxColumns to function
        hitWhiteSquare(board, maxRows, maxColumns);
    }
    // 1 is a black square
    else if (thisSquare == 1)
    {
        // call hitBlackSquare function, pass pointer to array, maxRows, and maxColumns to function
        hitBlackSquare(board, maxRows, maxColumns);
    }
}

/*************************************************************************
This function changes the color of the current square to black, turns the
ant 90 degrees to the right, and moves forward one space. If the ant hits
the edge of the board, it wraps around to the other side.
*************************************************************************/
void Ant::hitWhiteSquare(int** board, int maxRows, int maxColumns)
{
    // change color of square to black
    board[row][column] = 1;
    
    // if facing north
    if (direction == NORTH)
    {
        // if on right edge of board, turn 90 degrees to the right and go to left edge
        if (column == maxColumns - 1)
        {
            direction = EAST;
            column = 0;
        }
        // else turn 90 degrees right and move forward one space
        else
        {
            direction = EAST;
            column = column + 1;
        }
    }
    
    // if facing east
    else if (direction == EAST)
    {
        // if on bottom row, turn 90 degrees to the right and go to top row
        if (row == maxRows - 1)
        {
            direction = SOUTH;
            row = 0;
        }
        // else turn right 90 degrees and move forward one space
        else
        {
            direction = SOUTH;
            row = row + 1;
        }
    }
    
    // if facing south
    else if (direction == SOUTH)
    {
        // if in left edge, turn 90 degrees right and go to right edge
        if (column == 0)
        {
            direction = WEST;
            column = maxColumns - 1;
        }
        // else turn right 90 degrees and move forward one space
        else
        {
            direction = WEST;
            column = column - 1;
        }
    }
    
    // if facing west
    else if (direction == WEST)
    {
        // if on top row, turn 90 degrees right and go to bottom row
        if (row == 0)
        {
            direction = NORTH;
            row = maxRows - 1;
        }
        // else turn 90 degrees right and move forward one space
        else
        {
            direction = NORTH;
            row = row - 1;
        }
    }
}

/*************************************************************************
This function changes the color of the current square to white, turns the
ant 90 degrees to the left, and moves forward one space. If the ant hits
the edge of the board, it wraps around to the other side.
*************************************************************************/
void Ant::hitBlackSquare(int** board, int maxRows, int maxColumns)
{
    // change color of square to white
    board[row][column] = 0;
    
    if (direction == NORTH)
    {
        // if on left edge, turn 90 degrees left and go to right edge
        if (column == 0)
        {
            direction = WEST;
            column = maxColumns -1;
        }
        // else turn 90 degrees left and go forward one edge
        else
        {
            direction = WEST;
            column = column - 1;
        }
    }
    
    else if (direction == EAST)
    {
        // if on top row, turn 90 degrees left and go to bottom row
        if (row == 0)
        {
            direction = NORTH;
            row = maxRows - 1;
        }
        // else turn 90 degrees left and move forward one space
        else
        {
            direction = NORTH;
            row = row - 1;
        }
    }
    
    else if (direction == SOUTH)
    {
        // if on right edge, turn 90 degrees left and go to left edge
        if (column == maxColumns - 1)
        {
            direction = EAST;
            column = 0;
        }
        // else turn 90 degrees left and move forward one space
        else
        {
            direction = EAST;
            column = column + 1;
        }
    }
    
    else if (direction == WEST)
    {
        // if on bottom row, turn left 90 degrees and go to top row
        if (row == maxRows -1)
        {
            direction = SOUTH;
            row = 0;
        }
        // else turn left 90 degrees and move forward one space
        else
        {
            direction = SOUTH;
            row = row + 1;
        }
    }
}

// row accessor function
int Ant::getRow()
{
    return row;
}

// column accessor function
int Ant::getColumn()
{
    return column;
}

// Directions enum accessor
Directions Ant::getDirection()
{
    return direction;
}