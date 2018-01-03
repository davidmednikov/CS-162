/*********************************************************************
 ** Author: Group 18
 ** Date: 2/26/2017
 ** Description: rock.hpp is the Rock class interface file.
 *********************************************************************/

#ifndef ROCK_HPP
#define ROCK_HPP

#include "tool.hpp"

// Defines the interface of the Rock class
class Rock : public Tool
{
public:
	Rock();
	Rock(int str);
	Rock& operator=(const Rock& rock);
	~Rock();
	int fight(Tool* tool);
};

#endif
