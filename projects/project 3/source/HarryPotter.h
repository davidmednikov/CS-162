/********************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 02/13/17
** Description: Harry Potter class specification file. The Harry Potter class is derived
** from the Creature class and has 4 functions: the constructor, destructor,
** attack, and defense. There is also a bool that tells the program whether Harry
** has already used his Hogwarts power, which revives him to 20 strength points
** after he already dies once.
*********************************************************************************/

#ifndef HARRY_POTTER
#define HARRY_POTTER

#include "Creature.h" // Creature header

class HarryPotter :
	public Creature // derived from Creature class
{
	private:
		bool diedOnce; // bool for Hogwarts power
        
	public:
		HarryPotter(); // default cstr
		~HarryPotter(); // dstr
		int attack(); // calc attack
		int defense(); // calc defense
		void removePoints(int damage); //overriden function to remove points due to Hogwarts power
};

#endif

