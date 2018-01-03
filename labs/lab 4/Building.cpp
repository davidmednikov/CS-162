/************************************************************************
** Program name: CS162 Lab 4
** Author: David Mednikov
** Date: 02/03/17
** Description: This is the implementation file for the Building class.
** The class has 3 member variables: the name (string), address(string),
** and the square footage (int). There is a default constructor and an
** overloaded constructor that sets all 3 variables. There are also
** accessor functions for the name, address, and square footage.
************************************************************************/

#include "Building.h" // Building header

using std::string; // strings

/*************************************************************************
Building default constructor
Initializes a Building object and initializes each variable.
*************************************************************************/
Building::Building()
{
    name;
    address;
    sqft;
}

/*************************************************************************
Building overloaded constructor
paramters: string name, string address, int square footage
Initializes a Building object and sets the variables using the
values passed by the parameters.
*************************************************************************/
Building::Building(string n, string a, int s)
{
    name = n;
    address = a;
    sqft = s;
}

/*************************************************************************
getName()
parameters: none
returns: string
Returns the name of the building
*************************************************************************/
string Building::getName()
{
    return name;
}

/*************************************************************************
getAddress()
parameters: none
returns: string
Returns the address of the building
*************************************************************************/
string Building::getAddress()
{
    return address;
}

/*************************************************************************
getSqft()
parameters: none
returns: int
Returns the square footage of the building
*************************************************************************/
int Building::getSqft()
{
    return sqft;
}