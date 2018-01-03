/************************************************************************
** Program name: CS162 Lab 3
** Author: David Mednikov
** Date: 01/28/17
** Description: This is the header file for the Die class.
************************************************************************/

#ifndef DIE_H
#define DIE_H

class Die
{
    private:
        int sides; // number of sides
        
    public:
        Die(int s); // constructor that sets number of sides
        
        // returns the dice roll, can be overridden by derived class
        virtual int roll();
};

#endif