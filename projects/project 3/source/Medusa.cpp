/********************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 02/13/17
** Description: Medusa class specification file. The Medusa class is derived
** from the Creature class and has 4 functions: the constructor, destructor,
** attack, and defense. The attack and defense function both simulate the rolling
** of a die. The Die class is used for this calculation.
*********************************************************************************/

#include "Medusa.h" // Medusa header
#include "Die.h" // use a die

Medusa::Medusa() : Creature() // default constructor derived from base constructor, initialize attributes
{
	armor = 3;
	strengthPoints = 8;
	name = "Medusa";
}


Medusa::~Medusa() // destructor
{
}


int Medusa::attack() // calc attack or return glare
{
	Die die1(6); // create 2 6-sided die
	Die die2(6);

	int roll = die1.roll() + die2.roll(); // calculate total roll

	if (roll == 12) // if both die were 6
	{
		return 0; // use glare, return 0
	}

	return roll; // return roll total
}


int Medusa::defense() // calc defense
{
	Die die(6); //  1 6-sided die

	return die.roll(); // return roll
}