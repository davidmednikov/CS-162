/************************************************************************
** Program name: CS162 Project 2
** Author: David Mednikov
** Date: 02/01/17
** Description: This function validates doubles that the user inputs.
** It uses a while loop to keep asking the user to enter a decimal 
** until their input is validated. There are two overloaded methods, 
** one that takes a lower bound and another that takes a higher and lower 
** bound, to only accept numbers within the specified range.
************************************************************************/

#include "getDouble.h" // Include header file
#include <iostream> // for user input/output

using std::cin; // clean up code
using std::cout;

/*************************************************************************
getDouble()
no parameters
returns double
This function takes no parameters and validates the user's input by
making sure they entered a decimal number.
*************************************************************************/
double getDouble()
{
    double input; // initialize input variable
    bool valid = true; // set bool to true so that the loop runs
    while (valid)
    {
        cin >> input; // try assigning user input to input variable
    
        // if the input failed
        if (cin.fail())
        {
            cin.clear(); // clear the input stream
            cin.ignore(10000,'\n'); // ignore 10000 characters, up to the next newline
            
            // tell user that they didn't enter a double then go back to the top of the while loop
            cout << "You did not enter a decimal number. Please Try again: ";
        }
        // if the input did not fail
        else
        {
            cin.ignore(10000,'\n'); // clear the input stream
            
            // if anything other than a new line character was cleared, then the user inputted more than just an int
            if (cin.gcount() > 1) 
            {
                cout << "You did not enter a decimal number. Please Try again: ";
            }
            else
            {
                return input; // return input to whatever called this function
            }
        }
    }
}

/*************************************************************************
getDouble(double lowerBound)
parameters: double lowerBound
returns double
This overloaded function takes one parameter, the lower bound, and
validates the user's input by making sure that they entered a double
less than the lower bound.
*************************************************************************/
double getDouble(double lowerBound)
{
    double input; // initialize input variable
    bool valid = true; // set bool to true so that the loop runs
    while (valid)
    {
        cin >> input; // try assigning user input to input variable
    
        // if the user did not enter a valid double
        if (cin.fail())
        {
            cin.clear(); // clear the input stream
            cin.ignore(10000,'\n'); // ignore 10000 characters, up to the next newline
            
            // tell the user that they did not enter a double then go back to the top of the while loop
            cout << "You did not enter a decimal number. Please Try again: ";
        }
        // if the input did not fail
        else
        {
            cin.ignore(10000,'\n'); // clear the input stream
            
            // if anything other than a new line character was cleared, then the user inputted more than just an int
            if (cin.gcount() > 1)
            {
                cout << "You did not enter a decimal number. Please Try again: ";
            }
            // user inputted an integer but it is less than the lower bound
            else if (input < lowerBound)
            {
                // tell user that they didn't enter a number in the specified range then go back to the top of the while loop
                cout << "The number that you entered is too low. Please try again: ";
            }
            else
            {
                return input; // return input to whatever called this function
            }
        }
    }
}

/*************************************************************************
getDouble(double lowerBound, double higherBound)
parameters: double lowerBound, double higherBound
returns double
This overloaded function takes two parameters, a lower bound and a higher
bound, and validates the user's input by making sure that they entered 
a double within that range.
*************************************************************************/
double getDouble(double lowerBound, double higherBound)
{
    double input; // initialize input variable
    bool valid = true; // set bool to true so that the loop runs
    while (valid)
    {
        cin >> input; // try assigning user input to input variable
    
        // if the user did not enter a valid double
        if (cin.fail())
        {
            cin.clear(); // clear the input stream
            cin.ignore(10000,'\n'); // ignore 10000 characters, up to the next newline
            
            // tell the user that they did not enter a double then go back to the top of the while loop
            cout << "You did not enter a decimal number. Please Try again: ";
        }
        // if the input did not fail
        else
        {
            cin.ignore(10000,'\n'); // clear the input stream
            
            // if anything other than a new line character was cleared, then the user inputted more than just an int
            if (cin.gcount() > 1)
            {
                cout << "You did not enter a decimal number. Please Try again: ";
            }
            // user inputted an integer but it is less than the lower bound
            else if (input < lowerBound || input > higherBound)
            {
                // tell user that they didn't enter a number in the specified range then go back to the top of the while loop
                cout << "The number that you entered is not in the specified range. Please try again: ";
            }
            else
            {
                return input; // return input to whatever called this function
            }
        }
    }
}

/*************************************************************************
getDouble(double higherBound, string high)
parameters: double lowerBound, string high
returns double
This overloaded function takes two parameters, the higher bound and a
string so that the program knows not to use the lowerBound method.
It validates the user's input by making sure that they entered a double
that is less than the higher bound.
*************************************************************************/
double getDouble(double higherBound, std::string high)
{
    double input; // initialize input variable
    bool valid = true; // set bool to true so that the loop runs
    while (valid)
    {
        cin >> input; // try assigning user input to input variable
    
        // if the user did not enter a valid double
        if (cin.fail())
        {
            cin.clear(); // clear the input stream
            cin.ignore(10000,'\n'); // ignore 10000 characters, up to the next newline
            
            // tell the user that they did not enter a double then go back to the top of the while loop
            cout << "You did not enter a decimal number. Please Try again: ";
        }
        // if the input did not fail
        else
        {
            cin.ignore(10000,'\n'); // clear the input stream
            
            // if anything other than a new line character was cleared, then the user inputted more than just an int
            if (cin.gcount() > 1)
            {
                cout << "You did not enter a decimal number. Please Try again: ";
            }
            // user inputted an integer but it is less than the lower bound
            else if (input > higherBound)
            {
                // tell user that they didn't enter a number in the specified range then go back to the top of the while loop
                cout << "The number that you entered is not in the specified range. Please try again: ";
            }
            else
            {
                return input; // return input to whatever called this function
            }
        }
    }
}