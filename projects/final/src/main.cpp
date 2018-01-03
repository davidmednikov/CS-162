/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This program simulates a game of basketball. The user controls
** a player and moves around the court. The goal is to make enough baskets
** that the player scores 21 points. The user has a limit of 30 possessions
** to reach the goal. There are certain rules, such as the player not being
** allowed to shoot without the ball and the possession ending if the player
** steps out of bounds. This program allows the user to play as many times
** as they want, and has some sweet text-based graphics.
************************************************************************/

#include "Court.h" // Court header
#include "Square.h" // Square header
#include "showMenu.h" // showMenu utility function
#include "getInt.h" // getInt utility function
#include "Game.h" // Game header
#include <iostream> // output and input
#include <fstream> // read a file
#include <vector> // vector
#include <string> // for strings
#include <stdlib.h> // seed for rand()
#include <time.h> // time()

using std::cout; // clean up code
using std::endl;
using std::cin;
using std::ifstream;
using std::vector;
using std::string;
using std::getline;

void printLogo(); // prototype for printLogo() function
bool playAgain(); // prototype for playAgain() function

int main()
{
	srand(time(NULL)); // seed CPU time

	bool running = true; // run until usre wants to quit

	while (running)
	{
		cout << endl << endl; // skip a line
		printLogo(); // print the logo, Jerry West himself. With womanly hips.

		cout << "\n\n                      NBA 2K162" << endl; // title

		// print game details

		cout << "\n\nAbout this game:" << endl; 
		cout << "\nYou've achieved your lifelong dream of making it to the NBA, the most elite basketball league in the world." << endl; 
		cout << "But now you need to score some baskets and prove your worth!" << endl; 

		cout << "\nGoal:" << endl; 
		cout << "\nYou must score 21 or more points." << endl; 

		// how to play

		cout << "\nHow to Play:" << endl;
		cout << "\nMove your player around the court using the controls below. To make a move, type in your input and press enter." << endl;
		cout << "Follow the rules below and try to score the required number of points." << endl;

		// print game rules

		cout << "\nRules:" << endl; 
		cout << "\n - You will get one shot per possession." << endl; 
		cout << " - There is a limit of 30 possessions per game." << endl; 
		cout << " - If you go out of bounds, the possession is over." << endl; 
		cout << " - Shots from behind the 3-point line are worth 3 points, and shots inside the 3 point line are worth 2 points." << endl; 
		cout << " - The number of points is determined by the position of the ball, not the player." << endl; 
		cout << " - If the ball is on the 3-point line, the shot is worth 2 points." << endl; 
		cout << " - You are a right-handed player, so you must pick up the ball with your right hand (top-right corner of the player)." << endl; 
		cout << " - You must have the ball to shoot. Shooting without the ball will end your turn. Unless you're a legend." << endl; 

		// show the user the controls

		cout << "\nControls:" << endl; 
		cout << "\nMove Up: w" << endl; 
		cout << "Move Left: a" << endl; 
		cout << "Move Down: s" << endl; 
		cout << "Move Right: d" << endl; 
		cout << "Shoot: space (' ')" << endl; 

		vector<string> players = { "LeBron James", "Stephen Curry", "Kobe Bryant", "Shaquille O'Neal", "Ivica Zubac", "Lonzo Ball" };
		cout << "\nSelect a player:" << endl; // create vector of menu choices
		int player = showMenu(players, 1); // show choices to user and get their input

		if (player == 1) // Lebron
		{
			Game game(1); // create a game with lebron
			game.play(); // play the game
			running = playAgain(); // ask if the user wants to play again
		}
		else if (player == 2) // Steph
		{
			Game game(2); // create a game with steph
			game.play(); // play the game
			running = playAgain(); // ask if the user wants to play again
		}
		else if (player == 3) // Kobe
		{
			Game game(3); // create a game with kobe
			game.play(); // play the game
			running = playAgain(); // ask if the user wants to play again
		}
		else if (player == 4) // Shaq
		{
			Game game(4); // create a game with shaq
			game.play(); // play the game
			running = playAgain(); // ask if the user wants to play again
		}
		else if (player == 5) // Ivica Zubac
		{
			Game game(5); // create a game with ivica zubac
			game.play(); // play the game
			running = playAgain(); // ask if the user wants to play again
		}
		else // Lonzo Ball
		{
			Game game(6); // create a game with lonzo ball
			game.play(); // play the game
			running = playAgain(); // ask if the user wants to play again
		}
	}
	
	cout << "\n\nThanks for Playing!!\n" << endl; // user wants to quit

	return 0;
}

/*************************************************************************
printLogo()
Opens a text file containing a text graphic of the logo, reads it, and prints it
*************************************************************************/
void printLogo()
{
	ifstream logo; // input stream
	logo.open("logo.txt"); // open text file with graphic
	string line; // store each line

	while (getline(logo, line)) // while reading from the file
	{
		cout << line << endl; // print the line to the screen
	}
}

/*************************************************************************
printLogo()
returns: bool
Ask if the user wants to play again, return true if yes and false if no.
Valides input to make sure that user only enters y or n.
*************************************************************************/
bool playAgain()
{
	string again; // for user input

	cout << "\nDo you want to play again? y for yes, n for no: "; // ask user if they want to play again
	cin >> again; // get input from user

	bool validInput = false; // for input validation

	while (!validInput) // loop until valid input
	{
		if (again == "y" || again == "Y") // play again
		{
			return true;
		}
		else if (again == "n" || again == "N") // don't play again
		{
			return false;
		}
		else // invalid input
		{
			cout << "You did not enter y or n. Try again: ";
			cin.clear(); // clear input stream
			cin >> again; // loop back to top
		}
	}

	return false;
}