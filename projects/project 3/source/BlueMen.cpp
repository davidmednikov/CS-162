/********************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 02/13/17
** Description: Blue Men class specification file. The Blue Men class is derived
** from the Creature class and has 4 functions: the constructor, destructor,
** attack, and defense. The attack and defense function both simulate the rolling
** of a die. The Die class is used for this calculation.
*********************************************************************************/

#include "BlueMen.h" // Blue Men header
#include "Die.h" // use a Die

BlueMen::BlueMen() : Creature() // default constructor derived from base constructor, initialize attributes
{
	armor = 3;
	strengthPoints = 12;
	name = "Blue Men";
}


BlueMen::~BlueMen() // destructor
{
}


int BlueMen::attack() // calc attack
{
	Die die1(10); // create 2 10-sided die
	Die die2(10);

	return die1.roll() + die2.roll(); // return sum of both die
}


int BlueMen::defense() // calc defense, use Mob to affect defense die
{
	Die die1(6); // create 3 6-sided die
	Die die2(6);
	Die die3(6);

	if (strengthPoints > 8) // less than 4 strength points lost
	{
		return die1.roll() + die2.roll() + die3.roll(); // return sum of all 3 die
	}

	else if (strengthPoints <= 4) // more than 8 strength points lost
	{
		return die1.roll(); // return just 1 die
	}
	
	else // 4 < strength points lost < 8
	{
		return die1.roll() + die2.roll(); // return sum of 2 die
	}

	
}