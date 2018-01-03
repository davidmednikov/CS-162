/****************************************************************************
** Program name: CS162 Project 3
** Author: David Mednikov
** Date: 02/13/17
** Description: This program simulates a fantasy combat game. There are 
** 5 creatures in this game: Vampire, Barbarian, Blue Men, Medusa, and
** Harry Potter. Each creature has its own attributes, including an attack,
** defense, armor, and strength points. Some creatures also have special
** charactertics for their attack/defense/health. A game involves 2 characters 
** taking  turns attacking one another, using their attack, defense, and armor to
** determine how much damage the defending player takes. When a player has 0
** strength points left (except Harry Potter...) they lose and the other player
** is declared the winner of the match. This program randomly decides who goes
** first and randomly generates the attack and defense values for each player.
****************************************************************************/

#include "Creature.h" // Creature header
#include "Vampire.h" // Vampire header
#include "Barbarian.h" // Barbarian header
#include "BlueMen.h" // Blue Men header
#include "Medusa.h" // Medusa header
#include "HarryPotter.h" // Harry Potter header
#include "getInt.h" // getInt() header
#include "showMenu.h" // showMenu() header
#include <iostream> // input and output
#include <string> // string
#include <stdlib.h> // seed for rand()
#include <time.h> // time()
#include <vector> // vectors

using std::string; // clean up code
using std::vector;
using std::endl;
using std::cout;
using std::cin;
using std::getline;
using std::move;

int main()
{
	cout << "\n\nWelcome to the Ultimate Fantasy Combat Tournament!\n\n"; // its the ultimate fantasy combat game

	vector<string> creatures = { "Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter" };

	srand(time(NULL)); // seed CPU time

	bool playAgain = true; // to keep playing

	while (playAgain) // loop until user wants to stop playing
	{
		cout << "How many players will each team have: ";
		int players = getInt(1);
		int round = 1;
		int p1Score = 0;
		int p2Score = 0;

		vector<Creature*> p1Team;
		vector<Creature*> p2Team;
		vector<Creature*> deadPile;

		cout << "\nSelect your team.\n";

		for (int player = 0; player < players; ++player)
		{
			cout << "\nPick creature #" << player + 1 << " for your team:\n\n";
			int choice = showMenu(creatures, 1);
			cout << "\nEnter a name for this creature: ";
			string name;
			getline(cin, name);
			Creature* teamMember;
			switch (choice)
			{
			case 1:
				teamMember = new Vampire(name);
				break;
			case 2:
				teamMember = new Barbarian(name);
				break;
			case 3:
				teamMember = new BlueMen(name);
				break;
			case 4:
				teamMember = new Medusa(name);
				break;
			case 5:
				teamMember = new HarryPotter(name);
				break;
			default:
				break;
			}
			p1Team.push_back(teamMember);
		}

		cout << "\n\nSelect player 2's team.\n";

		for (int player = 0; player < players; ++player)
		{
			cout << "\nPick creature #" << player + 1 << " for the other team:\n\n";
			int choice = showMenu(creatures, 1);
			cout << "\nEnter a name for this creature: ";
			string name;
			getline(cin, name);
			Creature* teamMember;
			switch (choice)
			{
			case 1:
				teamMember = new Vampire(name);
				break;
			case 2:
				teamMember = new Barbarian(name);
				break;
			case 3:
				teamMember = new BlueMen(name);
				break;
			case 4:
				teamMember = new Medusa(name);
				break;
			case 5:
				teamMember = new HarryPotter(name);
				break;
			default:
				break;
			}
			p2Team.push_back(teamMember);
		}

		bool seeRoundResults = false;
		string seeRound;

		cout << "\nDo you want to see the score after each round? y for yes, n for no: ";
		getline(cin, seeRound);

		bool valid = false;

		while (!valid) // loop until valid input
		{
			if (seeRound == "y" || seeRound == "Y") // see score at end of each round
			{
				seeRoundResults = true;
				valid = true; // break out of loop
			}
			else if (seeRound == "n" || seeRound == "N") // don't see score at end of each round
			{
				valid = true; // break out of loop
			}
			else // invalid input
			{
				cout << "You did not enter y or n. Try again: ";
				cin.clear(); // clear input stream
				cin >> seeRound; // loop back to top
			}
		}
		
		bool p1GoesFirst = false; // initialize bool for who goes first

		if (rand() % 2) //      50/50 to see who goes first
		{
			cout << "\nPlayer 1's team will go first.\n"; // player1 goes first
			p1GoesFirst = true; // set bool to true
		}
		else
		{
			cout << "\nPlayer 2's team will go first.\n"; // don't do anything
		}


		if (p1GoesFirst) // if player 1 goes first, use while loop to alternate turns beginning with p1
		{

			bool gameActive = true; // game is still active

			while (gameActive) // while both teams have players left
			{
				Creature* player1 = p1Team[0];
				Creature* player2 = p2Team[0];

				int p1Attack = player1->attack(); // calculate p1's attack
				int p2Defense = player2->defense(); // calculate p2's defense

				// cout << endl << player1->getName() << "'s attack: " << p1Attack << endl << player2->getName() << "'s defense: " << p2Defense << endl;                  // debug

				int damage = p1Attack - p2Defense - player2->getArmor(); // calculate damage to p2

				if (p1Attack == 0) // Medusa Glare
				{
					// cout << "\nMGlare!\n";
					damage = player2->getStrengthPoints(); // set damage to kill player 2
				}

				if (p2Defense == 0) // Vampire Charm
				{
					// cout << "\nCharm!\n";
					damage = 0; // attack missed
				}

				if (damage < 0) // if damage is negative (defense > attack) set damage to 0
				{
					damage = 0;
				}

				// cout << "\nTotal damage to " << player2->getName() << ": " << damage << endl;                 // debug

				player2->removePoints(damage); // damage player 2's strength points

				// cout << endl << player2->getName() << " has " << player2->getStrengthPoints() << " strength points left.\n\n";             // debug

				if (player2->getStrengthPoints() == 0) // check if p2 is dead after attack
				{
					// cout << endl << player2->getName() << " has died.\n";
					cout << "\nRound " << round << ": " << "Player 1's " << player1->getName() << " (" << player1->getType() << ") vs. Player 2's " << player2->getName() << " (" << player2->getType() << ")\n";
					cout << endl << player1->getName() << " won this round!\n";
					++round;
					p1Score += 2;
					p2Score -= 1;
					if (p2Score < 0)
					{
						p2Score = 0;
					}
					if (seeRoundResults)
					{
						cout << "\nCurrent Score:\n";
						cout << "Player 1's team: " << p1Score << " points\n";
						cout << "Player 2's team: " << p2Score << " points\n";
					}
					Creature* dead = player2;
					deadPile.push_back(dead);
					player1->restoreHealth();
					Creature* temp = player1;
					p1Team.erase(p1Team.begin());
					p1Team.push_back(temp);
					// cout << "\nRestored some health to " << player1->getName() << " and moved to the back of the queue.\n";
					p2Team.erase(p2Team.begin());
					// cout << endl << player2->getName() << " has been added to the dead pile.\n";
					if (p2Team.size() == 0)
					{
						// Player 2 is out of players
						gameActive = false;
					}
				}

				else
				{
					int p2Attack = player2->attack(); // calculate p2's attack
					int p1Defense = player1->defense(); // calculate p1's attack

					// cout << endl << player2->getName() << "'s attack: " << p2Attack << endl << player1->getName() << "'s defense: " << p1Defense << endl;

					int damage = p2Attack - p1Defense - player1->getArmor(); // calculate total damage to p1

					if (p2Attack == 0) // Medusa Glare
					{
						// cout << "\nGlare!\n";
						damage = player1->getStrengthPoints(); // set damage to kill p1
					}

					if (p1Defense == 0) // Vampire Charm
					{
						// cout << "\nCharm!\n";
						damage = 0; // attack missed
					}

					if (damage < 0) // if damage is negative, set to 0
					{
						damage = 0;
					}

					player1->removePoints(damage); // remove damage points from player 1

					// cout << "\nTotal damage to " << player1->getName() << ": " << damage << endl;

					// cout << endl << player1->getName() << " has " << player1->getStrengthPoints() << " strength points left.\n\n";                 // debug

					if (player1->getStrengthPoints() == 0) // if player1 died
					{
						// cout << endl << player1->getName() << " has died.\n";
						cout << "\nRound " << round << ": " << "Player 1's " << player1->getName() << " (" << player1->getType() << ") vs. Player 2's " << player2->getName() << " (" << player2->getType() << ")\n";
						cout << endl << player2->getName() << " won this round!\n";
						++round;
						p2Score += 2;
						p1Score -= 1;
						if (p1Score < 0)
						{
							p1Score = 0;
						}
						if (seeRoundResults)
						{
							cout << "\nCurrent Score:\n";
							cout << "Player 1's team: " << p1Score << " points\n";
							cout << "Player 2's team: " << p2Score << " points\n";
						}
						Creature* dead = player1;
						deadPile.push_back(dead);
						player2->restoreHealth();
						Creature* temp = player2;
						p2Team.erase(p2Team.begin());
						p2Team.push_back(temp);
						// cout << "\nRestored some health to " << player2->getName() << " and moved to the back of the queue.\n";
						p1Team.erase(p1Team.begin());
						// cout << endl << player1->getName() << " has been added to the dead pile.\n";
						if (p1Team.size() == 0)
						{
							// Player 1 is out of players
							gameActive = false;
						}
					}
				}
			}
		}

		else // Player 2 goes first
		{
			bool gameActive = true; // keep game running

			while (gameActive) // while both teams have players left
			{
				Creature* player1 = p1Team[0];
				Creature* player2 = p2Team[0];

				int p2Attack = player2->attack(); // calculate p2's attack
				int p1Defense = player1->defense(); // calculate p1's attack

				// cout << endl << player2->getName() << "'s attack: " << p2Attack << endl << player1->getName() << "'s defense: " << p1Defense << endl;

				int damage = p2Attack - p1Defense - player1->getArmor(); // calculate total damage to p1

				if (p2Attack == 0) // Medusa Glare
				{
					// cout << "\nGlare!\n";
					damage = player1->getStrengthPoints(); // set damage to kill p1
				}

				if (p1Defense == 0) // Vampire Charm
				{
					// cout << "\nCharm!\n";
					damage = 0; // attack missed
				}

				if (damage < 0) // if damage is negative, set to 0
				{
					damage = 0;
				}

				player1->removePoints(damage); // remove damage points from player 1

				// cout << "\nTotal damage to " << player1->getName() << ": " << damage << endl;

				// cout << endl << player1->getName() << " has " << player1->getStrengthPoints() << " strength points left.\n\n";                 // debug

				if (player1->getStrengthPoints() == 0) // if player1 died
				{
					// cout << endl << player1->getName() << " has died.\n";
					cout << "\nRound " << round << ": " << "Player 1's " << player1->getName() << " (" << player1->getType() << ") vs. Player 2's " << player2->getName() << " (" << player2->getType() << ")\n";
					cout << endl << player2->getName() << " won this round!\n";
					++round;
					p2Score += 2;
					p1Score -= 1;
					if (p1Score < 0)
					{
						p1Score = 0;
					}
					if (seeRoundResults)
					{
						cout << "\nCurrent Score:\n";
						cout << "Player 1's team: " << p1Score << " points\n";
						cout << "Player 2's team: " << p2Score << " points\n";
					}
					Creature* dead = player1;
					deadPile.push_back(dead);
					player2->restoreHealth();
					Creature* temp = player2;
					p2Team.erase(p2Team.begin());
					p2Team.push_back(temp);
					// cout << "\nRestored some health to " << player2->getName() << " and moved to the back of the queue.\n";
					p1Team.erase(p1Team.begin());
					// cout << endl << player1->getName() << " has been added to the dead pile.\n";
					if (p1Team.size() == 0)
					{
						// Player 1 is out of players
						gameActive = false;
					}
				}

				else
				{
					int p1Attack = player1->attack(); // calculate p1's attack
					int p2Defense = player2->defense(); // calculate p2's defense

					// cout << endl << player1->getName() << "'s attack: " << p1Attack << endl << player2->getName() << "'s defense: " << p2Defense << endl;                  // debug

					int damage = p1Attack - p2Defense - player2->getArmor(); // calculate damage to p2

					if (p1Attack == 0) // Medusa Glare
					{
						// cout << "\nMGlare!\n";
						damage = player2->getStrengthPoints(); // set damage to kill player 2
					}

					if (p2Defense == 0) // Vampire Charm
					{
						// cout << "\nCharm!\n";
						damage = 0; // attack missed
					}

					if (damage < 0) // if damage is negative (defense > attack) set damage to 0
					{
						damage = 0;
					}

					// cout << "\nTotal damage to " << player2->getName() << ": " << damage << endl;                 // debug

					player2->removePoints(damage); // damage player 2's strength points

					// cout << endl << player2->getName() << " has " << player2->getStrengthPoints() << " strength points left.\n\n";             // debug

					if (player2->getStrengthPoints() == 0) // check if p2 is dead after attack
					{
						// cout << endl << player2->getName() << " has died.\n";
						cout << "\nRound " << round << ": " << "Player 1's " << player1->getName() << " (" << player1->getType() << ") vs. Player 2's " << player2->getName() << " (" << player2->getType() << ")\n";
						cout << endl << player1->getName() << " won this round!\n";
						++round;
						p1Score += 2;
						p2Score -= 1;
						if (p2Score < 0)
						{
							p2Score = 0;
						}
						if (seeRoundResults)
						{
							cout << "\nCurrent Score:\n";
							cout << "Player 1's team: " << p1Score << " points\n";
							cout << "Player 2's team: " << p2Score << " points\n";
						}
						Creature* dead = player2;
						deadPile.push_back(dead);
						player1->restoreHealth();
						Creature* temp = player1;
						p1Team.erase(p1Team.begin());
						p1Team.push_back(temp);
						// cout << "\nRestored some health to " << player1->getName() << " and moved to the back of the queue.\n";
						p2Team.erase(p2Team.begin());
						// cout << endl << player2->getName() << " has been added to the dead pile.\n";
						if (p2Team.size() == 0)
						{
							// Player 2 is out of players
							gameActive = false;
						}
					}
				}
			}
		}

		bool p1Won = false; // initialize bool for who won
		bool tie = false;

		if (p1Score > p2Score)
		{
			p1Won = true;
		}
		else if (p1Score == p2Score)
		{
			tie = true;
		}

		if (p1Won) // player1 won
		{
			cout << "\nPlayer 1's team (you) won the tournament!\n"; // print out winner
		}
		else if (tie)
		{
			cout << "\nWe have an unlikely tie!\n"; // print out that it was a tie
		}
		else // player 2 won
		{
			cout << "\nPlayer 2's team (not you) won the tournament!\n"; // print out winner
		}

		cout << "\nWould you like to see the dead pile? Enter y for yes or n for no: "; // ask user if they want to see the dead pile
		string showDead; // initialize input variable
		cin >> showDead; // assign input to variable

		bool validInput = false;

		while (!validInput) // loop until valid input
		{
			if (showDead == "y" || showDead == "Y") // play again
			{
				cout << "\nHere is the dead pile, beginning with the most recent to die.\n";
				for (int index = deadPile.size() - 1; index >= 0; --index)
				{
					cout << deadPile[index]->getName() << endl;
				}

				validInput = true; // break out of loop
			}
			else if (showDead == "n" || showDead == "N") // don't play again
			{
				cout << "\nOk, I guess I won't show you then!\n";
				validInput = true; // break out of loop
			}
			else // invalid input
			{
				cout << "You did not enter y or n. Try again: ";
				cin.clear(); // clear input stream
				cin >> showDead; // loop back to top
			}
		}

		bool validString = false; // for input to play again

		cout << "\nWould you like to play again? Enter y for yes or n for no: "; // ask user if they want to play again
		string again; // initialize input variable
		cin >> again; // assign input to variable

		while (!validString) // loop until valid input
		{
			if (again == "y" || again == "Y") // play again
			{
				cout << "\nYou are wise beyond your years.\n"; // (for continuing to use such a glorious program)
				for (int index = 0; index < p1Team.size(); ++index)
				{
					delete p1Team[index];
				}
				for (int index = 0; index < p2Team.size(); ++index)
				{
					delete p2Team[index];
				}
				for (int index = 0; index < deadPile.size(); ++index)
				{
					delete deadPile[index];
				}
				validString = true; // break out of loop
			}
			else if (again == "n" || again == "N") // don't play again
			{
				cout << "\nToo bad. See you next time.\n\n"; // don't come back. nobody wants you here
				for (int index = 0; index < p1Team.size(); ++index)
				{
					delete p1Team[index];
				}
				for (int index = 0; index < p2Team.size(); ++index)
				{
					delete p2Team[index];
				}
				for (int index = 0; index < deadPile.size(); ++index)
				{
					delete deadPile[index];
				}
				return 0;
			}

			/*************************************************************************
			VALGRIND Summary

			==17044== HEAP SUMMARY:
			==17044==     in use at exit: 0 bytes in 0 blocks
			==17044==   total heap usage: 35 allocs, 35 frees, 1,007 bytes allocated
			==17044==
			==17044== All heap blocks were freed -- no leaks are possible
			==17044==
			==17044== For counts of detected and suppressed errors, rerun with: -v
			==17044== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 1 from 1)
			flip2 ~/162/projects/proj3 182%
			**************************************************************************/

			else // invalid input
			{
				cout << "You did not enter y or n. Try again: ";
				cin.clear(); // clear input stream
				cin >> again; // loop back to top
			}
		}
	}
}