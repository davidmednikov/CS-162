
/*********************************************************************
 ** Author: Group 18
 ** Date: 2/26/2017
 ** Description: rock.cpp is the Rock class implementation file.
 *********************************************************************/
#include "rock.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
Rock::Rock()
{
    strength = 1;
    type = 'r';
}

/*********************************************************************
 ** Description: 1 parameter  constructor that sets strength
 ** Parameter: int
 *********************************************************************/
Rock::Rock(int str)
{
    strength = str;
    type = 'r';
}

/*********************************************************************
 ** Description: default destructor
 *********************************************************************/
Rock::~Rock(){}

/*********************************************************************
 ** Description: Compare Tool Strengths
 ** Parameter: Tool Object Pointer
 ** Returns: bool
 *********************************************************************/
int Rock::fight(Tool* tool)
{
	if (tool->getType() == 'p') // playing paper
	{
		if (strength > tool->getStrength() * 2) // rock has a disadvantage
		{
			return 1; // rock wins
		}

		else if (strength == tool->getStrength() * 2) // rock has a disadvantage
		{
			return 2; // tie
		}

		else // rock strength < paper strength
		{
			return 0; // paper wins
		}

	}

	if (tool->getType() == 'r') // rock playing rock
	{
		if (strength > tool->getStrength()) // my rock is stronger
		{
			return 1; // my rock wins
		}

		else if (strength == tool->getStrength()) // my rock ties
		{
			return 2; // tie
		}

		else // my rock strength < other rock strength
		{
			return 0; // other rock wins
		}
	}

	if (tool->getType() == 's') // playing against scissors
	{
		if (strength * 2 > tool->getStrength()) // rock has advantage over scissors
		{
			return 1; // rock wins
		}

		else if (strength * 2 == tool->getStrength()) // rock has advantage over scissors
		{
			return 2; // tie
		}

		else // rock loses to scissors
		{
			return 0; // scissors wins
		}
	} 
}


/*********************************************************************
 ** Description: Overloaded Assignment (=) Operator
 ** Parameter: Reference to object of type Rock
 ** Returns: Reference to object of type Rock (*this)
 *********************************************************************/
Rock& Rock::operator=(const Rock& rock)
{
    //test for self-assignment
    if (this == &rock)
    {
    	return *this;
    }
    //copy data members
    this->strength = rock.getStrength();
    this->type = rock.getType();
    
    //return existing object so operator can be chained
    return *this;
}

