/********************************************************************************
** Program name: CS162 Project 4
** Author: David Mednikov
** Date: 03/05/17
** Description: Medusa class specification file. The Medusa class is derived
** from the Creature class and has 5 functions: the default constructor, an overloaded
** constructor that sets the creature's name, the destructor, attack(), and defense().
** The attack and defense function both simulate the rolling of a die. The Die class 
** is used for this calculation. If the Medusa rolls a 12, their attack strength
** automatically matches that of the defender. This is represented by 0.
*********************************************************************************/

#include "Medusa.h" // Medusa header
#include "Die.h" // use a die

using std::string;

Medusa::Medusa() : Creature() // default constructor derived from base constructor, initialize attributes
{
	armor = 3;
	strengthPoints = 8;
	name = "Medusa";
	type = "Medusa";
}

Medusa::Medusa(string n) : Creature() // overloaded constructor that sets name
{
	armor = 3;
	strengthPoints = 8;
	name = n;
	type = "Medusa";
}


Medusa::~Medusa() // destructor
{
}


int Medusa::attack() // calc attack or return glare
{
	Die die1(6); // create 2 6-sided die
	Die die2(6);

	int roll = die1.roll() + die2.roll(); // calculate total roll

	if (roll == 12) // if both die were 6, Medusa rolled glare
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

void Medusa::restoreHealth() // restore 100% of health (multiply by 2)
{
	strengthPoints *= 2;
}