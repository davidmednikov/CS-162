/*********************************************************************
 ** Author: Group 18
 ** Date: 2/26/2017
 ** Description: paper.hpp is the Paper class interface file.
 *********************************************************************/

#ifndef PAPER_HPP
#define PAPER_HPP

#include "tool.hpp"

// Defines the interface of the Paper class
class Paper: public Tool
{
public:
    Paper();
    Paper(int str);
    Paper& operator=(const Paper& paper);
    ~Paper();
    int fight(Tool* tool);
};

#endif
