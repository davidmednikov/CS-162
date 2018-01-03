/************************************************************************
** Program name: CS162 Lab 5
** Author: David Mednikov
** Date: 02/09/17
** Description: This is the specification file for the triangularNum() method.
** This method takes an integer n and uses recursion to calculate and
** return the triangular number of n.
************************************************************************/

#include "triangularNum.h" // triangularNum() header

/***********************************************************************
triangularNum()
parameters: int n
returns: int
Takes an integer n and uses recursion to calculate the triangle number
of n. The triangular number is the number of pieces required to create
an equilateral triangle with n rows. For example, the bowling is played
with a 4-row equilateral triangle, and there are 10 pins. 10 is the
triangular number of 4.
***********************************************************************/
int triangularNum(int n)
{
    if (n == 1) // base case where n = 1
    {
        return 1; // only one "pin" in first row
    }
    
    return (n + triangularNum(n-1)); // use recursion to calculate n + (n-1) + (n-2) + ... + 1
    
}