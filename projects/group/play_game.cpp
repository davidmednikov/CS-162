/*********************************************************************
 ** Program name:  Play Rock, Paper, Scissors!!!
 ** Author: Group 18 
 ** Date: 2/26/2017
 ** Description: a Rock, Paper, Scissors game simulation.
 *********************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h> // seed for rand()
#include <time.h> // time()
#include "getInt.h" // getInt input validation
#include "RPSGame.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	srand(time(NULL)); // seed CPU time
	
	cout << "\nWelcome to Group 18's Implementation of Rock Paper Scissors!\n" << endl;

	RPSGame game; // initialize game

	bool playAgain = true; // play until user wants to quit

	while (playAgain) // loop until user wants to quit
	{
		game.round(); // call round() function to play 1 round of game

		bool validInput = false; // for input validation
		string userChoice;

		while (!validInput) // loop until user enters valid input
		{
			cout << "\nDo you want to play again (y or n): ";
			cin >> userChoice;

			if (userChoice == "y" || userChoice == "Y") // user wants to play again
			{
				validInput = true; // break out of loop
			}

			else if (userChoice == "n" || userChoice == "N") // user wants to stop
			{
				playAgain = false; // set playAgain bool to false to break out of parent loop
				validInput = true; // break out of loop
			}

			else // invalid input
			{
				cout << "You did not enter y or n.";
				cin.clear();
			}
		}
	}

	// get final scores
	int wins = game.getHumanWins(); 
	int losses = game.getCompWins();
	int ties = game.getTies();

	// print final scores
	cout << "\nYour final score:\n"; 
	cout << "You won " << wins << " rounds.\n";
	cout << "The computer won " << losses << " rounds.\n";
	cout << "There were " << ties << " ties.\n";

	if (wins > losses) // if user won
	{
		cout << "\nCongratulations! You are the winner!!\n";
	}
	else if (wins < losses) // if computer won
	{
		cout << "\nToo bad! Looks like the computer won this game.\n";
	}
	else // if user and computer tied
	{
		cout << "\nI don't believe it! Looks like we have a tie!\n";
	}

	cout << "\nThank you for playing!\n\n";
}
