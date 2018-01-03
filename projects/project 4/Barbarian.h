/********************************************************************************
** Program name: CS162 Project 4
** Author: David Mednikov
** Date: 03/05/17
** Description: Barbarian class specification file. The Barbarian class is derived
** from the Creature class and has 5 functions: the default constructor, an overloaded
** constructor that sets the creature's name, the destructor, attack(), and defense().
*********************************************************************************/

#ifndef BARBARIAN
#define BARBARIAN

#include "Creature.h" // Creature header

class Barbarian :
	public Creature  // derived from Creature abstract class
{
public:
	Barbarian(); // default constructor
	Barbarian(std::string n); // overloaded constructor
	~Barbarian(); // destructor
	int attack(); // calc attack
	int defense(); // calc defense
	void restoreHealth(); // restore health if creature won
};

#endif
