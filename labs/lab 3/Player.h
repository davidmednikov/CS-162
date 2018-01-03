/************************************************************************
** Program name: CS162 Lab 3
** Author: David Mednikov
** Date: 01/28/17
** Description: This is the header file for the Player class.
************************************************************************/

#include "Die.h" // include Die header

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    private:
        Die* die; // pointer to Die object
        int score; // player's score
        
    public:
        Player(int sides); // constructor, set number of sides
        Player(int sides, int loaded); // overloaded constructor that creates loaded die
        ~Player(); // destructor
        int turn(); // one turn, rolls dice and returns roll
        void winRound(); // increment score by one
        int getScore(); // return score
};

#endif