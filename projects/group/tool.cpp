/*********************************************************************
 ** Author: Group 18
 ** Date: 2/26/2017
 ** Description: tool.cpp is the Tool class implementation file.
 *********************************************************************/
#include "tool.hpp"

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
Tool::Tool(){}

/*********************************************************************
 ** Description: default destructor
 *********************************************************************/
Tool::~Tool(){}

/*********************************************************************
 ** Description: retrieve Tool type
 ** Returns: char
 *********************************************************************/
char Tool::getType() const
{
    return type;
}

/*********************************************************************
 ** Description: retrieve strength value
 ** Returns: int
 *********************************************************************/
int Tool::getStrength() const
{
    return strength;
}

/*********************************************************************
 ** Description: retrieve strength value
 ** Returns: int
 *********************************************************************/
void Tool::setStrength(int str)
{
    strength = str;
}

/*********************************************************************
 ** Description: overloaded assignment operator
 ** Parameters: Reference to object of type Tool
 ** Returns: reference to object of type Tool (*this)
 *********************************************************************/
Tool& Tool::operator=(const Tool& tool)
{
    //test for self-assignment
    if (this == &tool)
    {
    	return *this;
    }
    
    //copy data members
    this->strength = tool.getStrength();
    this->type = tool.getType();

    //return existing object so operator can be chained
    return *this; 
}

