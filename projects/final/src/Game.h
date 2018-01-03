/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the Game class. This class
** has 6 member variables and 7 functions.
************************************************************************/

#ifndef GAME
#define GAME

#include "Court.h" // Court header
#include "Player.h" // Player header

class Game
{
	private:
		Court court; // Court object
		Square*** courtArray; // 3D pointer for storing court array
		char printCourt[32][63]; // array of chars for printing the court
		Player* player; // Pointer to player object
		int score; // current score
		int rounds; // rounds counter
	public:
		Game(int player); // constructor
		void play(); // play game
		void print(); // print current game scenario
		void round(); // play 1 round
		void printTrophy(); // print the trophy
		char validateInput(); // validate the user's input for a command
		~Game();
};

#endif