/********************************************************************************
** Program name: CS162 Project 4
** Author: David Mednikov
** Date: 03/05/17
** Description: Harry Potter class specification file. The Harry Potter class is derived
** from the Creature class and has 4 functions: the constructor, destructor,
** attack, and defense. The attack and defense function both simulate the rolling
** of a die. The Die class is used for this calculation.
*********************************************************************************/

#include "HarryPotter.h" // Harry Potter header
#include "Die.h" // use a die

using std::string;

HarryPotter::HarryPotter() : Creature() // default constructor derived from base constructor, initialize attributes. also initializes diedOnce bool
{
	armor = 0;
	strengthPoints = 10;
	name = "Harry Potter";
	type = "Harry Potter";
	diedOnce = false;
}

HarryPotter::HarryPotter(string n) : Creature() // overloaded constructor that sets name
{
	armor = 0;
	strengthPoints = 10;
	name = n;
	type = "Harry Potter";
	diedOnce = false;
}


HarryPotter::~HarryPotter() // destructor
{
}


int HarryPotter::attack() // calc attack
{
	Die die1(6); // create 2 6-sided die
	Die die2(6);

	return die1.roll() + die2.roll(); // return sum of both rolls
}


int HarryPotter::defense() // calc defense
{
	Die die1(6); // create 2 6-sided die
	Die die2(6);

	return die1.roll() + die2.roll(); // return sum of both rolls
}

void HarryPotter::removePoints(int damage) // override base function to use Hogwarts power
{
	strengthPoints -= damage; // subtract points like normal

	if (strengthPoints <= 0) // if points is 0 or negative
	{
		if (!diedOnce) // Harry has not used his Hogwarts power yet, so he goes back to 20 strength points
        {
            strengthPoints = 20; // back to 20 strength points
            diedOnce = true; // set diedOnce bool to true
        }
        else // Harry has already used his Hogwarts power and is no dead
        {
            strengthPoints = 0; // Harry ded
        }
	}
}

void HarryPotter::restoreHealth() // restore 50% of health
{
	strengthPoints *= 1.5;
}