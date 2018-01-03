/************************************************************************
** Program name: CS162 Lab 3
** Author: David Mednikov
** Date: 01/28/17
** Description: This is the header file for the LoadedDie class.
************************************************************************/

#include "Die.h" // include Die header

#ifndef LOADED_DIE_H
#define LOADED_DIE_H

class LoadedDie: public Die // derive class from public instance of Die class
{
    private:
        int sides; // number of sides
        
    public:
        // inherit constructor from base class, set sides variable
        LoadedDie(int s) : Die(s) {sides = s;};
        int roll(); // function that returns loaded roll
};

#endif