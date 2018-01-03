/*********************************************************************
 ** Author: Group 18
 ** Date: 2/26/2017
 ** Description: RPSGame.cpp is the RPSGame class implementation file.
 *********************************************************************/
#include "RPSGame.hpp"
#include "getInt.h"
#include <stdlib.h> // rand() and srand()
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*********************************************************************
 ** Description: default constructor
 *********************************************************************/
RPSGame::RPSGame()
{
	human; // define human tool
	computer; // define computer tool
	human_wins = 0; // initialize human wins to 0
	computer_wins = 0; // initialize computer wins to 0
	ties = 0; // initialize ties to 0

	bool validInput = false; // loop until valid input
	string userChoice; // user's choice
	bool setStrength = false; // bool to set strength manually or default to 1

	while (!validInput) // loop until valid input
	{
		cout << "Do you want to set different strengths for the tools (y or n): ";
		cin >> userChoice;

		if (userChoice == "y" || userChoice == "Y") // set strength manurally
		{
			setStrength = true; // flip setStrength bool to true
			validInput = true; // break out of loop
		}

		else if (userChoice == "n" || userChoice == "N") // use default strength
		{
			validInput = true; // break out of loop
		}

		else // invalid input
		{
			cout << "You did not enter y or n.";
			cin.clear(); // clear input stream and try again
		}
	}

	if (setStrength) // user wants to set strength
	{
		// get and set strength of all tools for user and computer
		
		cout << "\nWhat will be the strength of your rock: ";
		rockStrH = getInt(1); // get an int >= 1

		cout << "What will be the strength of the computer's rock: ";
		rockStrC = getInt(1);

		cout << "What will be the strength of your paper: ";
		paperStrH = getInt(1);

		cout << "What will be the strength of the computer's paper: ";
		paperStrC = getInt(1);

		cout << "What will be the strength of your scissors: ";
		scissorsStrH = getInt(1);

		cout << "What will be the strength of the computer's scissors: ";
		scissorsStrC = getInt(1);
	}

	else // use default strength
	{
		rockStrH = 1;
		paperStrH = 1;
		scissorsStrH = 1;
		rockStrC = 1;
		paperStrC = 1;
		scissorsStrC = 1;
	}
			
}

/*********************************************************************
 ** Description: default destructor
 *********************************************************************/
RPSGame::~RPSGame()
{
}

/*********************************************************************
 ** Description: Computer guesses human's tool
 ** generating an int between 0 and 2
 ** Parameter: none
 ** Returns: int representing the tool: 0 = rock, 1 = paper, 2 = scissors
 *********************************************************************/
int RPSGame::guess()
{
	return rand() % 3;
}

/*********************************************************************
** Description: computer_wins accessor
** Parameter: none
** Returns: int representing the number of wins by the computer
*********************************************************************/
int RPSGame::getCompWins()
{
	return computer_wins;
}

/*********************************************************************
** Description: human_wins accessor
** Parameter: none
** Returns: int representing the number of wins by the human
*********************************************************************/
int RPSGame::getHumanWins()
{
	return human_wins;
}

/*********************************************************************
** Description: ties accessor
** Parameter: none
** Returns: int representing the number of ties
*********************************************************************/
int RPSGame::getTies()
{
	return ties;
}

/*********************************************************************
 ** Description: ask user for tool and have it fight the computer tool,
 ** then update score
 ** Parameter: none
 ** Returns: none
 *********************************************************************/
void RPSGame::round()
{
	bool validInput = false; // for input validation
	string userChoice; // user's choice

	while (!validInput) // loop until valid input
	{
		cout << "\nPick a tool (r = rock, p = paper, s = scissors): ";
		cin >> userChoice;

		if (userChoice == "r" || userChoice == "R") // user chooses rock
		{
			human = new Rock(rockStrH); // create rock and set strength
			cout << "\nYou chose rock this round.\n";
			validInput = true; // break out of loop
		}

		else if (userChoice == "p" || userChoice == "P") // create paper and set strength
		{
			human = new Paper(paperStrH);
			cout << "\nYou chose paper this round.\n";
			validInput = true; // break out of loop
		}
		
		else if (userChoice == "s" || userChoice == "S") // create scissors and set strength
		{
			human = new Scissors(scissorsStrH);
			cout << "\nYou chose scissors this round.\n";
			validInput = true; // break out of loop
		}

		else // invalid input
		{
			cout << "You did not enter a tool. Please try again.\n";
			cin.clear();
		}
	}
	
	int compGuess = guess(); // guess what human chose

	if (compGuess == 0) // computer guesses that human chose rock, so pick paper
	{
		computer = new Paper(paperStrC);
		cout << "Computer chose paper.\n";
	}

	else if (compGuess == 1) // computer guesses that human chose paper, so pick scissors
	{
		computer = new Scissors(scissorsStrC);
		cout << "Computer chose scissors.\n";
	}

	else // computer guesses that human chose scissors, so pick rock
	{
		computer = new Rock(rockStrC);
		cout << "Computer chose rock.\n";
	}

	int result = human->fight(computer); // get result of human tool fighting computer tool

	if (result == 0) // computer wins
	{
		++computer_wins;
		cout << "\nYou lost this round!\n";
	}
	else if (result == 1) // human wins
	{
		++human_wins;
		cout << "\nYou won this round!\n";
	}
	else // tie
	{ 
		++ties;
		cout << "\nThis round is a tie!\n";
	}

	cout << "\nHuman wins: " << human_wins << endl; // print out human wins
	cout << "Computer wins: " << computer_wins << endl; // print out computer wins
	cout << "Ties: " << ties << endl; // print out ties

	delete human; // deallocate memory for human tool
	delete computer; // deallocate memory for computer tool

/**********************************************************************
VALGRIND Summary

==6658==
==6658== HEAP SUMMARY:
==6658==     in use at exit: 0 bytes in 0 blocks
==6658==   total heap usage: 121 allocs, 121 frees, 2,546 bytes allocated
==6658==
==6658== All heap blocks were freed -- no leaks are possible
==6658==
==6658== For counts of detected and suppressed errors, rerun with: -v
==6658== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 1 from 1)

no memory leaks after 30 rounds
**********************************************************************/
	
}

/*********************************************************************
 ** Description: Overloaded Assignment (=) Operator
 ** Parameter: Reference to object of type RPSGame
 ** Returns: Reference to object of type RPSGame (*this)
 *********************************************************************/
RPSGame& RPSGame::operator=(const RPSGame& game)
{
	if(this == &game)
	{
		return *this;
	}
	
	this->human = game.human;
	this->computer = game.computer;
	this->human_wins = game.human_wins;
	this->computer_wins = game.computer_wins;
	this->ties = game.ties;
	
	return *this;
}