/************************************************************************
** Program name: CS162 Lab 1
** Author: David Mednikov
** Date: 01/12/17
** Description: This program will calculate the determininant of a user-
** entered square matrix. This particular file is the specification file
** for the readMatrix function, which will prompt the user to fill a square
** matrix and store the input into a 2D array.
************************************************************************/
// readMatrix.cpp is the readMatrix method specification file

#include "readMatrix.h" // include readMatrix header
#include <iostream> // needed for output and user input

using std::cout; // clean up code
using std::cin;
using std::endl;

/* This method asks the user to enter a value for each element of the matrix.
The two parameters are a pointer to a 2D array and the size of the matrix. */
void readMatrix(int** array, int arraySize)
{
    // counter used for asking user to enter element
    int element = 1;
    
    // Loop through array, asking user to enter each eleent
    for (int row = 0; row < arraySize; row++)
    {
        for (int col = 0; col < arraySize; col++)
        {
            cout << "Please enter element #" << element << ": ";
            cin >> array[row][col];
            element++; // increase element counter by 1
        }
    }
}