/*********************************************************************
 ** Author: Group 18
 ** Date: 2/26/2017
 ** Description: tool.hpp is the Tool class interface file.
 *********************************************************************/

#ifndef TOOL_HPP
#define TOOL_HPP

// Defines the interface of the Tool class
class Tool
{
protected:
    int strength;
    char type;
public:
    Tool();
    virtual ~Tool();
    virtual int fight(Tool* tool)=0;
    Tool& operator=(const Tool& tool);
    char getType() const;
    int getStrength() const;
    void setStrength(int str);
};

#endif
