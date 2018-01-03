/************************************************************************
** Program name: CS162 Lab 1
** Author: David Mednikov
** Date: 01/12/17
** Description: This program will calculate the determininant of a user-
** entered square matrix. This particular file is the specification file
** for the determinant function, which will calculate the determinant
** of the matrix created by the user.
************************************************************************/
// determinant.cpp is the determinant method specification file

#include "determinant.h" // include header file

/* This method calculates the determinant of a matrix. Its parameters are
a 2D array and the size of the matrix. */
int determinant(int** array, int arraySize)
{
    // Calculate the determinant for a 2x2 matrix
    if (arraySize == 2)
    {
        return (array[0][0] * array[1][1] - array[0][1] * array[1][0]);
    }
    
    // Calculate the determinant for a 3x3 matrix
    else if (arraySize == 3)
    {
        // split calculation of the determinant into 3 parts
        int det1 = array[0][0] * (array[1][1] * array[2][2] - array[1][2] * array[2][1]);
        int det2 = array[0][1] * (array[1][0] * array[2][2] - array[1][2] * array[2][0]);
        int det3 = array[0][2] * (array[1][0] * array[2][1] - array[1][1] * array[2][0]);

        // calculate determinant using 3 calculations above
        return det1 - det2 + det3;
    }
}