/********************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 02/13/17
** Description: Blue Men class specification file. The Blue Men class is derived
** from the Creature class and has 4 functions: the constructor, destructor,
** attack, and defense.
*********************************************************************************/

#ifndef BLUE_MEN
#define BLUE_MEN

#include "Creature.h" // Creature header

class BlueMen :
	public Creature // derived from Creature class
{
public:
	BlueMen(); // def constr
	BlueMen(std::string n); // overloaded constructor
	~BlueMen(); // destr
	int attack(); // calc attack
	int defense(); // calc defense
	void restoreHealth(); // restore health if creature won
};

#endif
