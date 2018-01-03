/********************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 02/13/17
** Description: Medusa class specification file. The Medusa class is derived
** from the Creature class and has 4 functions: the constructor, destructor,
** attack, and defense.
*********************************************************************************/

#ifndef MEDUA
#define MEDUSA

#include "Creature.h" // Creature header

class Medusa :
	public Creature // derived from Creature class
{
public:
	Medusa(); // ctor
	~Medusa(); // dtor
	int attack(); // calc attack
	int defense(); // calc defense
};

#endif