/********************************************************************************
** Program name: CS162 Project 4
** Author: David Mednikov
** Date: 03/05/17
** Description: Vampire class specification file. The Vampire class is derived
** from the Creature class and has 5 functions: the default constructor, an overloaded
** constructor that sets the creature's name, the destructor, attack(), and defense().
*********************************************************************************/

#ifndef VAMPIRE
#define VAMPIRE

#include "Creature.h"

class Vampire :
	public Creature // derived from Creature abstract class
{
public:
	Vampire(); // default construcutor
	Vampire(std::string n); // overloaded constructor
	~Vampire(); // destructor
	int attack(); // calculate attack
	int defense(); // calculate defense
	void restoreHealth(); // restore health if creature won
};

#endif
