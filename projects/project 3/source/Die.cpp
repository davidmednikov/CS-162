/****************************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 01/28/17
** Description: Die class specification file. This class has 1 member variable: the
** number of sides. It also has two member functions, a constructor which sets the number
** of sides and a roll() function which simulates a roll of the die by returning a
** generated random number between 1 and the number of sides.
****************************************************************************************/

#include "Die.h" // Die header file
#include <stdlib.h> // rand() and srand()

/*************************************************************************************
Die class constructor
Parameters: sides
This constructor creates the Die member object and initializes the number of sides
to the amount set by the user
*************************************************************************************/
Die::Die(int s)
{
	sides = s;
}

/*************************************************************************************
roll()
This function simulates rolling the die by generating a random number between 1 and
the number of sides. The number that is generated is returned to the calling function.
*************************************************************************************/
int Die::roll()
{
	return rand() % sides + 1; // generate random row number
}