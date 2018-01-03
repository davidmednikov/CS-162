/************************************************************************
** Program name: CS162 Lab 4
** Author: David Mednikov
** Date: 02/03/17
** Description: This is the header file for the Building class.
************************************************************************/

#include <string> // strings

#ifndef BUILDING_H
#define BUILDING_H

class Building
{
    private:
        std::string name; // name of building
        std::string address; // address of building
        int sqft; // square footage of building
        
    public:
        Building(); // default constructor
        Building(std::string n, std::string a, int s); // overloaded constructor that sets all 3 variables
        std::string getName(); // building name accessor
        std::string getAddress(); // address accessor
        int getSqft(); // square footage accessor
};

#endif