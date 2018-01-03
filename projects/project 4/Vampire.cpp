/********************************************************************************
** Program name: CS162 Project 4
** Author: David Mednikov
** Date: 03/05/17
** Description: Vampire class specification file. The Vampire class is derived
** from the Creature class and has 5 functions: the default constructor, an overloaded
** constructor that sets the creature's name, the destructor, attack(), and defense().
** The attack and defense function both simulate the rolling of a die. The Die class 
** is used for this calculation. 50% of the time, the Vampire's defense is "Charm",
** which causes the opponent to miss.
*********************************************************************************/

#include "Vampire.h" // Vampire header
#include "Die.h" // Include Die
#include <stdlib.h> // rand() and srand()

using std::string;

Vampire::Vampire() : Creature() // default constructor derived from base constructor, initialize attributes
{
	armor = 1;
	strengthPoints = 18;
	name = "Vampire";
	type = "Vampire";
}

Vampire::Vampire(string n) : Creature() // overloaded constructor that sets name
{
	armor = 1;
	strengthPoints = 18;
	name = n;
	type = "Vampire";
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

void Vampire::restoreHealth() // restore 50% of health
{
	strengthPoints *= 1.5;
}
