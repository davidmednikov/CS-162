/************************************************************************
** Program name: CS162 Project 1
** Author: David Mednikov
** Date: 01/17/17
** Description: This is the header file for the Ant class.
************************************************************************/

#ifndef ANT_H
#define ANT_H

enum Directions { NORTH, EAST, WEST, SOUTH }; // define 4 enums for the direction of the ant

class Ant // Ant class declaration
{
    private:
        Directions direction; // Directions enum containing direction that the ant is facing
        int row; // row of ant
        int column; // column of ant
        
    public:
        // Ant(); // default constructor (used only for testing)
        Ant(int r0w, int col); // constructor that takes 2 parameters
        
        void moveAnt(int** board, int thisSquare, int maxRows, int maxColumns); // function that moves the ant
        void hitWhiteSquare(int** board, int maxRows, int maxColumns); // function when ant is on a white square
        void hitBlackSquare(int** board, int maxRows, int maxColumns); // function when ant is on a black square
        
        int getRow(); // row accessor function
        int getColumn(); // column accessor function
        Directions getDirection(); // Directions enum accessor
};

#endif 