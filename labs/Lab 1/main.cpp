/************************************************************************
** Program name: CS162 Lab 1
** Author: David Mednikov
** Date: 01/12/17
** Description: This program will calculate the determininant of a user-
** entered square matrix. This particular file is the main method, which
** will ask the user how large the matrix should be, then call on the
** readMatrix method to fill the array, then use the determinant method
** to calculate the determinant of the matrix. It will then display the
** array and the determinant to the user.
************************************************************************/
#include "readMatrix.h" // include readMatrix header
#include "determinant.h" // include determinant header
#include <iostream> // Needed for output and user input

using std::cout; // clean up code
using std::cin;
using std::endl;

int main()
{
    int arraySize; // initialize int containing matrix size
	
    // ask user for size of matrix
    cout << "Please select the size of the matrix.\n";
    cout << "Enter 2 for a 2x2 matrix and enter 3 for a 3x3 matrix: ";
    cin >> arraySize;
    
    // dynamically allocate pointer to 2D array
    int** matrix = new int*[arraySize];
    
    // allocate pointers in the array to another array
    for (int i = 0; i < arraySize; i++)
    {
        matrix[i] = new int[arraySize];
    }

    // call readMatrix method, pass pointer to 2D array and matrix size as parameters
    readMatrix(matrix, arraySize);
    int det = determinant(matrix, arraySize); // calculate determinant

    cout << endl; // skip line
    
    // Loop through array to print the matrix to the cmd window
    for (int row = 0; row < arraySize; row++)
    {
        for (int col = 0; col < arraySize; col++)
        {
            cout << matrix[row][col];

            // If reaching the end of the row, skip a line
            if (col == arraySize - 1)
            {
                cout << endl << endl;
            }
            // If not at the end of a row, add 4 spaces and print the next element
            else
            {
                cout << "    ";
            }
        }
    }

    // Print out determinant
    cout << "\nThe determinant of this matrix is: " << det << endl << endl;;

    // delete dynamically allocated matrix
    delete[] matrix;
    
    return 0;
}
