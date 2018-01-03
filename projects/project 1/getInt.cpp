/************************************************************************
** Program name: CS162 Project 1
** Author: David Mednikov
** Date: 01/17/17
** Description: This function validates integers that the user inputs.
** It uses a while loop to keep asking the user to enter an integer 
** until their input is validated. There are two overloaded methods, 
** one that takes a lower bound and another that takes a higher and lower 
** bound, to only accept numbers within the specified range.
************************************************************************/

#include "getInt.h" // Include header file
#include <iostream> // for user input/output

using std::cin; // clean up code
using std::cout;

// This function takes no paramters and loops until the user enters a valid integer
int getInt()
{
    int input; // initialize input variable
    bool valid = true; // set bool to true so that the loop runs
    while (valid)
    {
        cin >> input; // try assigning user input to input variable
    
        // if the input failed
        if (cin.fail())
        {
            cin.clear(); // clear the input stream
            cin.ignore(10000,'\n'); // ignore 10000 characters, up to the next newline
            
            // tell user that they didn't enter an integer then go back to the top of the while loop
            cout << "You did not enter an integer. Please Try again: ";
        }
        // if the input did not fail
        else
        {
            cin.ignore(10000,'\n'); // clear the input stream
            
            // if anything other than a new line character was cleared, then the user inputted more than just an int
            if (cin.gcount() > 1) 
            {
                cout << "You did not enter an integer. Please Try again: ";
            }
            else
            {
                return input; // return input to whatever called this function
            }
        }
    }
}

// this function takes one parameter (a lower bound) and returns a validated inputted integer
// overload of getInt()
int getInt(int lowerBound)
{
    int input; // initialize input variable
    bool valid = true; // set bool to true so that the loop runs
    while (valid)
    {
        cin >> input; // try assigning user input to input variable
    
        // if the user did not enter a valid integer
        if (cin.fail())
        {
            cin.clear(); // clear the input stream
            cin.ignore(10000,'\n'); // ignore 10000 characters, up to the next newline
            
            // tell the user that they did not enter an integer then go back to the top of the while loop
            cout << "You did not enter an integer. Please Try again: ";
        }
        // if the input did not fail
        else
        {
            cin.ignore(10000,'\n'); // clear the input stream
            
            // if anything other than a new line character was cleared, then the user inputted more than just an int
            if (cin.gcount() > 1)
            {
                cout << "You did not enter an integer. Please Try again: ";
            }
            // user inputted an integer but it is less than the lower bound
            else if (input < lowerBound)
            {
                // tell user that they didn't enter an integer in the specified range then go back to the top of the while loop
                cout << "The number that you entered is too low. Please try again: ";
            }
            else
            {
                return input; // return input to whatever called this function
            }
        }
    }
}

// this function takes two parameters (a lower bound and higher bound) and returns a validated inputted integer
// overload of getInt()
int getInt(int lowerBound, int higherBound)
{
    int input; // initialize input variable
    bool valid = true; // set bool to true so that the loop runs
    while (valid)
    {
        cin >> input; // try assigning user input to input variable
    
        // if the user did not enter a valid integer
        if (cin.fail())
        {
            cin.clear(); // clear the input stream
            cin.ignore(10000,'\n'); // ignore 10000 characters, up to the next newline
            
            // tell the user that they did not enter an integer then go back to the top of the while loop
            cout << "You did not enter an integer. Please Try again: ";
        }
        // if the input did not fail
        else
        {
            cin.ignore(10000,'\n'); // clear the input stream
            
            // if anything other than a new line character was cleared, then the user inputted more than just an int
            if (cin.gcount() > 1)
            {
                cout << "You did not enter an integer. Please Try again: ";
            }
            // user inputted an integer but it is less than the lower bound or more than the higher bound
            else if (input < lowerBound || input > higherBound)
            {
                // tell user that they didn't enter an integer in the specified range then go back to the top of the while loop
                cout << "The number that you entered is not in the specified range. Please try again: ";
            }
            else
            {
                return input; // return input to whatever called this function
            }
        }
    }
}