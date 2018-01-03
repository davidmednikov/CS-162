/************************************************************************
** Program name: getInt() Utility Function
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

/*************************************************************************
getInt()
no parameters
returns int
This function takes no parameters and validates the user's input by
making sure they entered an integer.
*************************************************************************/
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
			cin.ignore(10000, '\n'); // ignore 10000 characters, up to the next newline

									 // tell user that they didn't enter an integer then go back to the top of the while loop
			cout << "You did not enter an integer. Please Try again: ";
		}
		// if the input did not fail
		else
		{
			cin.ignore(10000, '\n'); // clear the input stream

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

/*************************************************************************
getInt(int lowerBound)
parameters: int lowerBound
returns int
This overloaded function takes one parameter, the lower bound, and
validates the user's input by making sure that they entered an integer
less than the lower bound.
*************************************************************************/
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
			cin.ignore(10000, '\n'); // ignore 10000 characters, up to the next newline

									 // tell the user that they did not enter an integer then go back to the top of the while loop
			cout << "You did not enter an integer. Please Try again: ";
		}
		// if the input did not fail
		else
		{
			cin.ignore(10000, '\n'); // clear the input stream

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

/*************************************************************************
getInt(int lowerBound, int higherBound)
parameters: int lowerBound, int higherBound
returns int
This overloaded function takes two parameters, a lower bound and a higher
bound, and validates the user's input by making sure that they entered
an integer within that range.
*************************************************************************/
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
			cin.ignore(10000, '\n'); // ignore 10000 characters, up to the next newline

									 // tell the user that they did not enter an integer then go back to the top of the while loop
			cout << "You did not enter an integer. Please Try again: ";
		}
		// if the input did not fail
		else
		{
			cin.ignore(10000, '\n'); // clear the input stream

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

/*************************************************************************
getInt(int higherBound, string high)
parameters: int higherBound, string high
returns int
This overloaded function takes two parameters, the higher bound and a
string so that the program knows not to use the lowerBound method.
It validates the user's input by making sure that they entered an integer
that is less than the higher bound.
*************************************************************************/
int getInt(int higherBound, std::string high)
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
			cin.ignore(10000, '\n'); // ignore 10000 characters, up to the next newline

									 // tell the user that they did not enter an integer then go back to the top of the while loop
			cout << "You did not enter an integer. Please Try again: ";
		}
		// if the input did not fail
		else
		{
			cin.ignore(10000, '\n'); // clear the input stream

									 // if anything other than a new line character was cleared, then the user inputted more than just an int
			if (cin.gcount() > 1)
			{
				cout << "You did not enter an integer. Please Try again: ";
			}
			// user inputted an integer but it is more than the higher bound
			else if (input > higherBound)
			{
				// tell user that they didn't enter an integer in the specified range then go back to the top of the while loop
				cout << "The number that you entered is too high. Please try again: ";
			}
			else
			{
				return input; // return input to whatever called this function
			}
		}
	}
}