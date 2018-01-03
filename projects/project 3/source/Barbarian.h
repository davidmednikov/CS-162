/********************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 02/13/17
** Description: Barbarian class specification file. The Barbarian class is derived
** from the Creature class and has 4 functions: the constructor, destructor,
** attack, and defense.
*********************************************************************************/

#ifndef BARBARIAN
#define BARBARIAN

#include "Creature.h" // Creature header

class Barbarian :
	public Creature  // derived from Creature abstract class
{
public:
	Barbarian(); // default constructor
	~Barbarian(); // destructor
	int attack(); // calc attack
	int defense(); // calc defense
};

#endif
