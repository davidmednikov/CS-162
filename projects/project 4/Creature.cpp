/********************************************************************************
** Program name: CS162 Project 4
** Author: David Mednikov
** Date: 03/05/17
** Description: Creature base class implementation file. The Creature class is
** an abstract class and has 4 member variables: int armor, int strengthPoints,
** string name, and string type. There is a default constructor which initializes
** those variables, an overloaded constructor that allows the user to select a name,
** a virtual destructor, accessor functions for the 4 variables, and 4 virtual
** functions. There is a virtual function that removes points from the creature.
** This function is overriden in some derived classes. The other 3 virtual
** functions, attack(), defense(), and restoreHealth() are overridden in all derived classes.
*********************************************************************************/

#include "Creature.h" // Creature header

using std::string; // clean up code

Creature::Creature() // default constructor, initializes 3 variables
{
	armor;
	strengthPoints;
	name;
	type;
}

Creature::Creature(string n) // overloaded constructor to set name
{
	armor;
	strengthPoints;
	name = n;
	type;
}

Creature::~Creature() // default destructor
{
}

int Creature::getArmor() // armor accessor
{
	return armor;
}

int Creature::getStrengthPoints() // strength points accessor
{
	return strengthPoints;
}

string Creature::getName() // name accessor
{
	return name;
}

string Creature::getType() // type accessor
{
	return type;
}

void Creature::removePoints(int damage) // remove points from creature's strength points
{
	strengthPoints -= damage; //subtract damage from points

	if (strengthPoints < 0) // if strength points < 0
	{
		strengthPoints = 0; // set to 0
	}
}