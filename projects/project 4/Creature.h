/********************************************************************************
** Program name: CS162 Project 4
** Author: David Mednikov
** Date: 03/05/17
** Description: Creature base class specification file. The Creature class is
** an abstract class and has 4 member variables: int armor, int strengthPoints,
** string name, and string type. There is a default constructor which initializes
** those variables, an overloaded constructor that allows the user to select a name,
** a virtual destructor, accessor functions for the 4 variables, and 4 virtual
** functions. There is a virtual function that removes points from the creature.
** This function is overriden in some derived classes. The other 3 virtual
** functions, attack(), defense(), and restoreHealth() are overridden in all derived classes.
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
		std::string type; // type of creature


	public:
		Creature(); // constructor
		Creature(std::string n); // overloaded constructor that sets name
		virtual ~Creature(); // virtual destructor
		int getArmor(); // armor accessor
		int getStrengthPoints(); // strength points accessor
		std::string getName(); // name accessor
		std::string getType(); // type accessor
		virtual void removePoints(int damage); // virtual function that applies damage to creature
		virtual int attack() = 0; // pure virtual function that calcs attack
		virtual int defense() = 0; // pure virtual function that calcs defense
		virtual void restoreHealth() = 0; // pure virtual function to get health back
};

#endif
