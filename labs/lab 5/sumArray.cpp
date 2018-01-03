/************************************************************************
** Program name: CS162 Lab 5
** Author: David Mednikov
** Date: 02/09/17
** Description: This is the specification file for the sumArray() method.
** This method takes an array of integers and the length of the array
** as arguments and uses recursion to calculate and return the sum of the array.
************************************************************************/

#include "sumArray.h" // sumArray() header

/***********************************************************************
sumArray()
parameters: int[] array, int length
returns: int
Takes an array of integers and the length of the array as parameters and
uses recursion to add up all elements of the array and returns the sum
to the function that called it.
***********************************************************************/
int sumArray(int array[], int length)
{        
    if (length == 1) // base case at second element
    {
        return array[length - 1]; // return first element
    }
    else
    {
        --length; // decrement length counter
        return array[length] + sumArray(array, length); // recursively call function
    }
}
    