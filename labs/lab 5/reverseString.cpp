/************************************************************************
** Program name: CS162 Lab 5
** Author: David Mednikov
** Date: 02/09/17
** Description: This is the specification file for the reverseString() method.
** This method takes a string and the length of the string as input and
** prints out the string in reverse.
************************************************************************/

#include "reverseString.h" // reverseString header
#include <iostream> // for output

using std::string; // clean up code
using std::cout;
using std::endl;

/***********************************************************************
reverseString()
parameters: string input, int length
Takes a string as input and uses recursion to print it out in reverse.
***********************************************************************/
void reverseString(string input)
{
    int length = input.length();
    
    if (length == 0)
    {
        cout << input[length] << endl;
        return;
    }
    
    cout << input[length - 1];
    input.erase(length - 1, 1);
    
    reverseString(input); // call method recursively, reducing index by 1
}
    