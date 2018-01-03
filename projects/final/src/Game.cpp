/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the header file for the Game class. This class
** has 6 member variables and 7 functions.
************************************************************************/

#include "Game.h" // Game header
#include "IvicaZubac.h" // headers for players
#include "LonzoBall.h"
#include "KobeBryant.h"
#include "LebronJames.h"
#include "Shaq.h"
#include "StephCurry.h"
#include <iostream> // input and output
#include <fstream> // read a file
#include <string> // strings

using std::cout; // clean up code
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;

/*************************************************************************
Game constructor
params: the player chosen by the user in the form of an int
Creates a game by initializing a player and printing the court. The
starting point of the player and the ball are also set
*************************************************************************/
Game::Game(int p)
{
	court; // define court
	courtArray = court.getCourt(); // get 3D array from court object

	printCourt; // define the 2D array of chars for printing

	for (int row = 0; row < 32; ++row) // step through each loop
	{
		for (int col = 0; col < 63; ++col) // step through each column
		{
			printCourt[row][col] = (courtArray[row][col])->getChar(); // place the character for each Square* into the char array
		}
	}

	if (p == 1) // user wants to play as Lebron
	{
		player = new LebronJames();
	}
	else if (p == 2) // user wants to play as Steph
	{
		player = new StephCurry();
	}
	else if (p == 3) // user wants to play as Kobe
	{
		player = new KobeBryant();
	}
	else if (p == 4) // user wants to play as Shaq
	{
		player = new Shaq();
	}
	else if (p == 5) // user wants to play as Ivica Zubac, who can't miss
	{
		player = new IvicaZubac();
		cout << "\nYou have selected the GOAT, who can't miss!\n" << endl;
	}
	else // user wants to play as LOnzo Ball, who can score without the ball and can't miss
	{
		player = new LonzoBall();
		cout << "\nYou have selected the GGOATOAT, who can score without the ball!\n" << endl;
	}

	score = 0; // initialize score as 0
	rounds = 1; // set rounds counter at 1

	player->square = courtArray[27][30]; // set location of player to starting spot
	player->square->occupy(); // flip occupied bool
	player->ball.square = courtArray[24][31]; // set location of ball to starting spot

	cout << "\n\nYour player:\n\n" << player->getInitials() << endl << player->getNumber() << endl << endl;
}

/*************************************************************************
play()
params: none
returns: none
Lets the user play the game by running a while loop until the user has
scored 21 points or exceeded the rounds limit (30)
*************************************************************************/
void Game::play()
{	
	// run while user's score is under 21 and they have not exceeded the rounds limit
	while (score < 21 && rounds <= 30)
	{
		cout << "\n\npossession #" << rounds << endl << endl; // print out possession number
		round(); // play 1 round
		player->resetPlayer(); // reset player's bools
		player->square = courtArray[27][30]; // reset player's position
		player->square->occupy(); // flip the occupied bool for the current square
		player->ball.square = courtArray[24][31]; // reset ball's  position
	}

	if (score >= 21) // player has won game
	{
		cout << endl << player->getName() << ", you have achieved the unthinkable." << endl; // yeah sick dude
		cout << "\nYour hard work, perseverence, and natural athletic ability have propelled you to the top of basketball's elite." << endl;
		cout << "\nAs the commissioner of NBA2K162, I hereby pronounce you, the almight champion!\n" << endl;

		printTrophy(); // call printTrophy() function to let the user know how special they are

		cout << "\nIt only took you " << rounds - 1 << " possessions. Well done." << endl; // count the number of rounds
	}
	else // player exceeded the rounds limit (Shaq, is that you?)
	{
		cout << "\nLooks like you've exceeded the possessions limit." << endl; 
		cout << "\nNo Participation Trophies here! Grab em by the bootstraps and try again!!" << endl; // murica
	}
}

/*************************************************************************
rounds()
params: none
returns: none
Plays one game of the round by printing the court, getting the player's
command, moving the player and ball, and displaying the result of each move.
The round is active until the user shoots or goes out of bounds.
*************************************************************************/
void Game::round()
{
	
	bool roundActive = true; // keep round running

	cout << endl;
	print(); // print the court before getting the user's command

	while (roundActive && (player->getBagSize() < 2)) // while the round is active and the player is only holding one item
	{		
		char command = validateInput(); // get user's command

		int ballRow = player->getBallRow(); // get the ball's location
		int ballCol = player->getBallCol();

		if (command == ' ') // user wants to shoot
		{			
			int points = player->shoot(); // call shoot function

			string message; // initialize string for storing the message

			if (points == -1) // player doesn't have ball
			{
				message = "\nYou don't have the ball!\n"; 
				roundActive = false; // end possession
			}
			else if (points == 0) // player missed
			{
				message = "\nYour shot missed!\n"; 
				roundActive = false; // end possession
			}
			else if (points == 2) // player made a 2 point shot
			{
				message = "\nYou made the basket! 2 points\n"; 
				score += 2; // increment score by 2
				player->ball.square = courtArray[4][31]; // place the ball in the basket
				roundActive = false; // end possession
				
			}
			else // player made a 3 point shot
			{
				message = "\nFrom downtown!! You made the 3!\n"; 
				score += 3; // increment score by 3
				player->ball.square = courtArray[4][31]; // place the ball in the basket
				roundActive = false; // end possession
			}

			cout << endl; // skip a line
			print(); // print court
			cout << message << endl; // print shot result
		}
		else // player wants to move
		{
			player->square->unOccupy(); // make current square unoccupied
			player->move(command); // call player's move command
			player->square->occupy(); // make the next square occupied

			cout << endl;
			print(); // print court after moving

			if (player->in_Bounds() == false) // if player went out of bounds
			{
				cout << "\nYou went out of bounds!\n" << endl;
				roundActive = false; // end possession
			}
			if ((player->has_Ball() == false) && (player->getRow() == (ballRow + 1)) && (player->getCol() == (ballCol - 1))) // if player is in the spot to pick up the ball
			{
				player->pickUpBall(); // pick up the ball
			}
		}
	}

	cout << "\nScore: " << score << endl << endl; // print score

	++rounds; // increment rounds by 1
}

/*************************************************************************
print()
params: none
returns: none
Prints the court, and shows the location of the player and the ball on the court
*************************************************************************/
void Game::print()
{
	int ballRow = player->getBallRow(); // get the location of the ball for printing
	int ballCol = player->getBallCol(); // get the location of the ball for printing
	int playerRow = player->getRow(); // get the location of the player for printing
	int playerCol = player->getCol(); // get the location of the player for printing

	char ball = printCourt[ballRow][ballCol]; // temporarily store the court character in the ball's position
	char nameL = printCourt[playerRow][playerCol]; // temporarily store the court character in the player's top-left square
	char nameR = printCourt[playerRow][playerCol + 1]; // temporarily store the court character in the player's top-right square
	char numL = printCourt[playerRow + 1][playerCol]; // temporarily store the court character in the player's bottom-left square
	char numR = printCourt[playerRow + 1][playerCol + 1]; // temporarily store the court character in the player's bottom-right square

	printCourt[ballRow][ballCol] = '@'; // change the ball's position to the ball character]
	// place the player's number and initials in his location in the print array
	printCourt[playerRow][playerCol] = player->getInitials()[0];
	printCourt[playerRow][playerCol + 1] = player->getInitials()[1];
	printCourt[playerRow + 1][playerCol] = player->getNumber()[0];
	printCourt[playerRow + 1][playerCol + 1] = player->getNumber()[1];

	for (int row = 0; row < 32; ++row) // step through each row
	{
		for (int col = 0; col < 63; ++col) // step through each column
		{
			cout << printCourt[row][col]; // print out each element of the 2D array
		}

		cout << endl; // go to next row
	}

	printCourt[ballRow][ballCol] = ball; // place temp char back where ball was
	printCourt[playerRow][playerCol] = nameL; // place temp char back where person was
	printCourt[playerRow][playerCol + 1] = nameR; // place temp char back where person was
	printCourt[playerRow + 1][playerCol] = numL; // place temp char back where person was
	printCourt[playerRow + 1][playerCol + 1] = numR; // place temp char back where person was
}

/*************************************************************************
validateInput()
params: none
returns: char
Get the user's command: a for left, s for down, d for right, w for up, and 
space (' ') for shoot.
*************************************************************************/
char Game::validateInput()
{
	bool validInput = false; // for input validation
	string command; // store user's command

	while (!validInput) // loop until user enters valid input
	{
		cout << "\nEnter a command (w, a , s, d, space): ";
		getline(cin, command); // get user's input

		if (command == "w" || command == "W") // move up
		{
			return 'w';
		}
		else if (command == "a" || command == "A") // move left
		{
			return 'a';
		}
		else if (command == "s" || command == "s") // move down
		{
			return 's';
		}
		else if (command == "d" || command == "D") // move right
		{
			return 'd';
		}
		else if (command == " ") // shoot
		{
			return ' ';
		}
		else // invalid input
		{
			cout << "I did not recognize your input.";
			cin.clear();
		}
	}

	return '\0';
}

/*************************************************************************
printTrophy()
params: none
returns: none
Print the trophy if the user won
*************************************************************************/
void Game::printTrophy()
{
	int row = 1; // row counter
	
	ifstream trophy; // input stream
	trophy.open("trophy.txt"); // open text file of trophy graphic
	string line; // create string for each line

	while (getline(trophy, line)) // while reading lines from the file
	{
		if (row == 25) // in the 25th row, print the player's name for the plaque
		{
			if (player->getName() == "LeBron James")
			{
				cout << "      ******        LEBRON JAMES        ******" << endl;
			}
			else if (player->getName() == "Stephen Curry")
			{
				cout << "      ******        STEPHEN CURRY       ******" << endl;
			}
			else if (player->getName() == "Kobe Bryant")
			{
				cout << "      ******         KOBE BRYANT        ******" << endl;
			}
			else if (player->getName() == "Shaquille O'Neal")
			{
				cout << "      ******      SHAQUILLE O'NEAL      ******" << endl;
			}
			else if (player->getName() == "Ivica Zubac")
			{
				cout << "      ******         IVICA ZUBAC        ******" << endl;
			}
			else
			{
				cout << "      ******         LONZO BALL         ******" << endl;
			}
			
		}
		else // in all other rows, print the trophy graphic
		{
			cout << line << endl; // print line from text file
		}

		++row; // increment row counter
	}
}

/*************************************************************************
Game destructor
deallocate player from memory

==18300== HEAP SUMMARY:
==18300==     in use at exit: 0 bytes in 0 blocks
==18300==   total heap usage: 16,395 allocs, 16,395 frees, 994,051 bytes allocated
==18300==
==18300== All heap blocks were freed -- no leaks are possible
==18300==
==18300== For counts of detected and suppressed errors, rerun with: -v
==18300== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*************************************************************************/
Game::~Game()
{
	delete player;
}