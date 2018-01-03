/********************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 02/13/17
** Description: Vampire class specification file. The Vampire class is derived
** from the Creature class and has 4 functions: the constructor, destructor,
** attack, and defense.
*********************************************************************************/

#ifndef VAMPIRE
#define VAMPIRE

#include "Creature.h"

class Vampire :
	public Creature // derived from Creature abstract class
{
public:
	Vampire(); // defauly construcutor
	~Vampire(); // destructor
	int attack(); // calculate attack
	int defense(); // calculate defense
};

#endif
