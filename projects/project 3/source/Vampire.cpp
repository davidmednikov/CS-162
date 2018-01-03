/********************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 02/13/17
** Description: Vampire class specification file. The Vampire class is derived
** from the Creature class and has 4 functions: the constructor, destructor,
** attack, and defense. The attack and defense function both simulate the rolling
** of a die. The Die class is used for this calculation. 50% of the time, the 
** Vampire's defense is "Charm", which causes the opponent to miss.
*********************************************************************************/

#include "Vampire.h" // Vampire header
#include "Die.h" // Include Die
#include <stdlib.h> // rand() and srand()

Vampire::Vampire() : Creature() // default constructor derived from base constructor, initialize attributes
{
	armor = 1;
	strengthPoints = 18;
	name = "Vampire";
}


Vampire::~Vampire() // destructor
{
}

int Vampire::attack() // calc attack
{
	Die die(12); // create a 12-sided die

	return die.roll(); // roll 12 sided die and return
}

int Vampire::defense() // calc defense, or return charm
{
	if (rand() % 2) // 50% chance
	{
		return 0; // defense of 0 means charm
	}

	Die die(6); // create a 6-sided die

	return die.roll(); // roll 6 sided die and return
}
