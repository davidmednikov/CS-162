/*********************************************************************
 ** Author: Group 18
 ** Date: 2/26/2017
 ** Description: scissors.hpp is the Scissors class interface file.
 *********************************************************************/
#ifndef SCISSORS_HPP
#define SCISSORS_HPP

#include "tool.hpp"

// Defines the interface of the Scissors class
class Scissors : public Tool
{
public:
	Scissors();
	Scissors(int str);
	Scissors& operator=(const Scissors& scissors);
	~Scissors();
	int fight(Tool* tool);
};

#endif
