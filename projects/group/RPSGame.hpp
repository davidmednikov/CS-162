/*********************************************************************
 ** Author: Group 18
 ** Date: 2/26/2017
 ** Description: RPSGame.hpp is the RPSGame class interface file.
 *********************************************************************/

#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include "tool.hpp"
#include "rock.hpp"
#include "paper.hpp"
#include "scissors.hpp"

// Defines the interface of the RPSGame class
class RPSGame
{
private:
	Tool* human; // human tool
	Tool* computer; // computer tool
	int human_wins; // human wins counter
	int computer_wins; // computer wins counter
	int ties; // ties counter
	int rockStrH; // human rock strength
	int paperStrH; // human paper strength
	int scissorsStrH; // human scissors strength
	int rockStrC; // computer rock strength
	int paperStrC; // computer paper strength
	int scissorsStrC; // computer scissors strength
public:
	RPSGame(); // default constructor
	~RPSGame();
	RPSGame& operator=(const RPSGame& game);
	int guess(); // guess human's choice
	void round(); // one round
	int getCompWins(); // accessor methods
	int getHumanWins();
	int getTies();
};

#endif
