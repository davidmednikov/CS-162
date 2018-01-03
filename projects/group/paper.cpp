/*********************************************************************
 ** Author: Group 18
 ** Date: 2/26/2017
 ** Description: paper.cpp is the Paper class implementation file.
 *********************************************************************/
#include "paper.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
Paper::Paper()
{
    strength = 1;
    type = 'p';
}

/*********************************************************************
 ** Description: 1 parameter  constructor that sets strength
 ** Parameter: int
 *********************************************************************/
Paper::Paper(int str)
{
    strength = str;
    type = 'p';
}

/*********************************************************************
 ** Description: default destructor
 *********************************************************************/
Paper::~Paper(){}

/*********************************************************************
 ** Description: Compare Tool Strengths
 ** Parameter: Tool Object Pointer
 ** Returns: int
 *********************************************************************/
int Paper::fight(Tool* tool)
{
    
	if (tool->getType() == 'r') // playing rock
	{
		if(strength * 2 > tool->getStrength()) // paper has advantage over rock
		{
			return 1; // paper wins
		}
	
		else if (strength * 2 == tool->getStrength()) // paper has advantage over rock
		{
			return 2; // tie
		}

		else // paper strength * 2 < rock strength
		{
			return 0; // rock wins
		}

	}

	else if (tool->getType() == 's') // playing scissors
	{
		if (strength > tool->getStrength() * 2) // paper has a disadvantage
		{
			return 1; // paper wins
		}

		else if (strength == tool->getStrength() * 2) // paper has a disadvantage
		{
			return 2; // tie
		}

		else
		{
			return 0; // scissors wins
		}
	}

	else if (tool->getType() == 'p') // playing paper
	{
		if (strength > tool->getStrength()) // paper playing paper
		{
			return 1; // my paper wins
		}

		else if (strength == tool->getStrength()) // paper playering paper
		{
			return 2; // tie
		}

		else // my paper strength < other paper strength
		{
			return 0; // other paper wins
		}
	}  
}

/*********************************************************************
 ** Description: Overloaded Assignment (=) Operator
 ** Parameter: Reference to object of type Paper
 ** Returns: Reference to object of type Paper (*this)
 *********************************************************************/
Paper& Paper::operator=(const Paper& paper)
{
    //test for self-assignment
    if (this == &paper)
    {
    	return *this;
    }
    //copy data members
    this->strength = paper.getStrength();
    this->type = paper.getType();
    
    //return existing object so operator can be chained
    return *this;
}
