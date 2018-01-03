/********************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 02/13/17
** Description: Barbarian class specification file. The Barbarian class is derived
** from the Creature class and has 4 functions: the constructor, destructor,
** attack, and defense. The attack and defense function both simulate the rolling
** of a die. The Die class is used for this calculation.
*********************************************************************************/

#include "Barbarian.h" // Barbarian header
#include "Die.h" // Include die

using std::string;

Barbarian::Barbarian() : Creature()// default constructor derived from base constructor, initialize attributes
{
	armor = 0;
	strengthPoints = 12;
	name = "Barbarian";
	type = "Barbarian";
}

Barbarian::Barbarian(string n) : Creature()// overloaded constructor that sets name
{
	armor = 0;
	strengthPoints = 12;
	name = n;
	type = "Barbarian";
}


Barbarian::~Barbarian() // destructor
{
}


int Barbarian::attack() // calc attack
{
	Die die1(6); // create 2 6-sided die
	Die die2(6);

	return die1.roll() + die2.roll(); // return sum of both rolls
}


int Barbarian::defense() // calc defense
{
	Die die1(6); // create 2 6-sided die
	Die die2(6);

	return die1.roll() + die2.roll(); // return sum of both rolls
}

void Barbarian::restoreHealth()
{
	strengthPoints += 4;
}