/****************************************************************************************
** Program name: CS162 Lab 3
** Author: David Mednikov
** Date: 01/28/17
** Description: LoadedDie class specification file. This class is derived from the Die
** class and inherits its constructor. The LoadedDie class has 1 member variable: the
** number of sides. There are two member functions: a constructor and roll(), which
** simulates a roll of the loaded die. The LoadedDie rolls its highest number 50% of the 
** time and rolls a random number the other 50% of the time.
****************************************************************************************/

#include "LoadedDie.h" // Die header file
#include <stdlib.h> // rand() and srand()

/*************************************************************************************
roll()
This function simulates one roll of the loaded die. It first randomly generates a
random int between 0 and 1. If the number is 1 (50% of the time), the function returns
the highest number on the die. If the number is 0 (the other 50% of the time), the 
function randomly generates the number rolled and returns it to the calling function.
*************************************************************************************/
int LoadedDie::roll()
{
    bool highestNum = rand() % 2; // randomly decide if roll is loaded or not
    
    if (highestNum) // if loaded roll, return highest number
    {
        return sides;
    }
    
    return rand() % sides + 1; // if normal roll, return randomly generated number
}