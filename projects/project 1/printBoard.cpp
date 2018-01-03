/************************************************************************
** Program name: CS162 Project 1
** Author: David Mednikov
** Date: 01/17/17
** Description: This is the printBoard() specification file. This function
** prints out the board that Langston's Ant will navigate. White squares 
** are blank (' ') and black squares are pound (#). The ant's direction is
** represented by one of four characters: { <, ^, >, v }. This function 
** also creates a border around the board.
************************************************************************/

#include "printBoard.h" // include printBoard() header file
#include <iostream> // for outputting text

using std::cout; // clean up code
using std::endl;

/*************************************************************************
This function takes 4 inputs, a pointer to a 2D array, the number of rows,
number of columns, and the direction of the ant. It prints out the top edge 
of the table, then prints out each row one by one. White squares are displayed 
as blank squares (' '), black squares are displayed by the pound symbol (#), 
and the ant is represented by  one of four characters: { <, ^, >, v }. This 
function loops through each row and column to print out each element of the 2D array.
*************************************************************************/
void printBoard(int** board, int rows, int columns, Directions direction)
{
    cout << endl << " "; // create space between edge of terminal and top border of board
    
    // loop through the number of columns to print out the top border
    for (int cols = 0; cols < columns; cols++)
    {
        cout << "-";
    }
    
    cout << endl; // go to next line
    
    // loop through each row and table to print out entire board, starting with rows
    for (int row = 0; row < rows; row++)
    {
        
        cout << "|"; // print left border at start of row
        
        // loop through each column to print each individual square
        for (int col = 0; col < columns; col++)
        {
            if (board[row][col] == 0) // if square is white, print blank square
            {
                cout << " ";
            }
            else if (board[row][col] == 1) // if square is black, print a pound sign
            {
                cout << "#";
            }
            else if (board[row][col] == 2) // if square is occupied by the an ant, 
            {
                // ant facing north
                if (direction == NORTH)
                {
                    cout << "^";
                }
                // ant facing west
                else if (direction == WEST)
                {
                    cout << "<";
                }
                // ant facing south
                else if (direction == SOUTH)
                {
                    cout << "v";
                }
                // ant facing east
                else if (direction == EAST)
                {
                    cout << ">";
                }
            }
        }
        
        cout << "|" << endl; // print right border at end of row
        
    }
        
    cout << " "; // print space before bottom border
    
    // loop through number of columns to print out bottom border
    for (int cols = 0; cols < columns; cols++)
    {
        cout << "-";
    }
    
    cout << endl; // go to next line
}