/*********************************************************************
 ** Author: Group 18
 ** Date: 2/26/2017
 ** Description: Scissors.cpp is the Scissors class implementation file.
 *********************************************************************/
#include "scissors.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
Scissors::Scissors()
{
    strength = 1;
    type = 's';
}

/*********************************************************************
 ** Description: 1 parameter  constructor that sets strength
 ** Parameter: int
 *********************************************************************/
Scissors::Scissors(int str)
{
    strength = str;
    type = 's';
}

/*********************************************************************
 ** Description: default destructor
 *********************************************************************/
Scissors::~Scissors(){}

/*********************************************************************
 ** Description: Compare Tool Strengths
 ** Parameter: Tool Object Pointer
 ** Returns: bool
 *********************************************************************/
int Scissors::fight(Tool* tool)
{

	if (tool->getType() == 'r') // playing rock
	{
		if (strength > tool->getStrength() * 2) // scissors has a disadvantage
		{
			return 1; // paper wins
		}

		else if (strength == tool->getStrength() * 2) // scissors has a disadvantage
		{
			return 2; // tie
		}

		else // scissors strength < rock strength
		{
			return 0; // rock wins
		}

	}

	else if (tool->getType() == 's') // playing scissors
	{
		if (strength > tool->getStrength()) // scissors playing scissors
		{
			return 1; // my scissors wins
		}

		else if (strength == tool->getStrength()) //  scissors playing scissors
		{
			return 2; // tie
		}

		else // scissors strength < scissors strength
		{
			return 0; // other scissors wins
		}
	}

	else if (tool->getType() == 'p') // playing paper
	{
		if (strength * 2 > tool->getStrength()) // scissors has advantage
		{
			return 1; // scissors
		}

		else if (strength * 2 == tool->getStrength()) // scissors has advantage
		{
			return 2; // tie
		}

		else // scissors strength < paper strength
		{
			return 0; // paper wins
		}
	}
}


/*********************************************************************
 ** Description: Overloaded Assignment (=) Operator
 ** Parameter: Reference to object of type scissors
 ** Returns: reference to object of type scissors (*this)
 *********************************************************************/
Scissors& Scissors::operator=(const Scissors& scissors)
{
    //test for self-assignment
    if (this == &scissors)
    {
    	return *this;
    }
    //copy data members
    this->strength = scissors.getStrength();
    this->type = scissors.getType();
    
    //return existing object so operator can be chained
    return *this;
}
