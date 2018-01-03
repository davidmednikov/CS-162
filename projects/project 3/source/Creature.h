/********************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 02/13/17
** Description: Creature base class specification file. The Creature class is
** an abstract class and has 3 member variables: int armor, int strengthPoints,
** and string name. There is a constructor which initializes those variables,
** a virtual destructor, accessor functions for the 3 variables, and 3 virtual
** functions. There is a virtual function that removes points from the creature.
** This function is overriden in some derived classes. The other 2 virtual
** functions, attack() and defense(), are overridden in all derived classes.
*********************************************************************************/

#ifndef CREATURE
#define CREATURE

#include <string> // strings

class Creature
{
	protected:
		int armor; // strength of armor
		int strengthPoints; // remaining strength points
		std::string name; // name of creature


	public:
		Creature(); // constructor
		virtual ~Creature(); // virtual destructor
		int getArmor(); // armor accessor
		int getStrengthPoints(); // strength points accessor
		std::string getName(); // name accessor
		virtual void removePoints(int damage); // virtual function that applies damage to creature
		virtual int attack() = 0; // pure virtual function that calcs attack
		virtual int defense() = 0; // pure virtual function that calcs defense
};

#endif
