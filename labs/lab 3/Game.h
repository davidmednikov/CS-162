/************************************************************************
** Program name: CS162 Lab 3
** Author: David Mednikov
** Date: 01/28/17
** Description: This is the header file for the Game class.
************************************************************************/

#include "Player.h" // Include Player header

#ifndef GAME_H
#define GAME_H

class Game
{
    private:
        Player* player1; // pointer to player 1 object
        Player* player2; // pointer to player 2 object
        int rounds; // rounds negative counter
        int totalRounds; // total rounds, doesn't change
        double p1Total; // sum of player 1's rolls
        double p2Total; // sum of player 2's rolls
        int currentRound; // rounds incrementer
        
    public:
        Game(int r, int sidesP1, int sidesP2, int loadedP1, int loadedP2); // Game class constructor
        ~Game(); // destructor
        void oneRound(); // one round of game function
        void endGame(); // end of game function
};

#endif