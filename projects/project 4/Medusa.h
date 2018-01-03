/********************************************************************************
** Program name: CS162 Project 4
** Author: David Mednikov
** Date: 03/05/17
** Description: Medusa class specification file. The Medusa class is derived
** from the Creature class and has 5 functions: the default constructor, an overloaded
** constructor that sets the creature's name, the destructor, attack(), and defense().
*********************************************************************************/

#ifndef MEDUA
#define MEDUSA

#include "Creature.h" // Creature header

class Medusa :
	public Creature // derived from Creature class
{
public:
	Medusa(); // ctor
	Medusa(std::string); // overloaded constructor
	~Medusa(); // dtor
	int attack(); // calc attack
	int defense(); // calc defense
	void restoreHealth(); // restore health if creature won
};

#endif