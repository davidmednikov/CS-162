/****************************************************************************
** Program name: CS162 Project 4
** Author: David Mednikov
** Date: 03/05/17
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

int main()
{
	cout << "\nWelcome to the Ultimate Fantasy Combat Tournament!\n\n"; // its the ultimate fantasy combat game

	vector<string> creatures = { "Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter" }; // vector of creatures

	srand(time(NULL)); // seed CPU time

	bool playAgain = true; // to keep playing

	while (playAgain) // loop until user wants to stop playing
	{
		cout << "How many players will each team have: "; // ask for number of players per team
		int players = getInt(1); // validate input
		
		int round = 1; // start round counter
		int p1Score = 0; // initialize player 1's score
		int p2Score = 0; // initialize player 2's score

		vector<Creature*> p1Team; // create vector for player 1's team
		vector<Creature*> p2Team; // create vector for player 2's team
		vector<Creature*> deadPile; // create vector for dead pile

		cout << "\nSelect your team.\n"; // ask user to select their team

		for (int player = 0; player < players; ++player) // use loop to ask user for proper number of players
		{
			cout << "\nPick creature #" << player + 1 << " for your team:\n\n"; // ask user to pick a creature
			int choice = showMenu(creatures, 1); // show creature options
			
			cout << "\nEnter a name for this creature: "; // ask user for creature's name
			string name;
			getline(cin, name); // get name of creature from user
			
			Creature* teamMember; // create pointer to creature object
			
			switch (choice) // switch based on which creature user chose
			{
			case 1:
				teamMember = new Vampire(name); // create vampire creature and give it the user-defined name
				break;
			case 2:
				teamMember = new Barbarian(name); // create barbarian creature and give it the user-defined name
				break;
			case 3:
				teamMember = new BlueMen(name); // create blue men creature and give it the user-defined name
				break;
			case 4:
				teamMember = new Medusa(name); // create medusa creature and give it the user-defined name
				break;
			case 5:
				teamMember = new HarryPotter(name); // create harry potter creature and give it the user-defined name
				break;
			default:
				break;
			}
			
			p1Team.push_back(teamMember); // add new creature to player 1's team
		}

		cout << "\n\nSelect player 2's team.\n"; // ask user to select the other team

		for (int player = 0; player < players; ++player) // use loop to ask user for proper number of players
		{
			cout << "\nPick creature #" << player + 1 << " for the other team:\n\n"; // ask user to pick a creature
			int choice = showMenu(creatures, 1); // show creature options and get user's choice
			
			cout << "\nEnter a name for this creature: "; // ask user for creature's name
			string name;
			getline(cin, name); // get name of creature from user
			
			Creature* teamMember; // create pointer to creature object
			
			switch (choice) // switch based on which creature user chose
			{
			case 1:
				teamMember = new Vampire(name); // create vampire creature and give it the user-defined name
				break;
			case 2:
				teamMember = new Barbarian(name); // create barbarian creature and give it the user-defined name
				break;
			case 3:
				teamMember = new BlueMen(name); // create blue men creature and give it the user-defined name
				break;
			case 4:
				teamMember = new Medusa(name); // create medusa creature and give it the user-defined name
				break;
			case 5:
				teamMember = new HarryPotter(name); // create harry potter creature and give it the user-defined name
				break;
			default:
				break;
			}
			
			p2Team.push_back(teamMember); // add new creature to player 2's team
		}

		// ask user if they want to see the score at the end of each round
		bool seeRoundResults = false; // initialize as false
		string seeRound; // for user input

		cout << "\nDo you want to see the score after each round? y for yes, n for no: "; // ask user if they want to see the score after each round
		cin >> seeRound; // get input from user

		bool valid = false; // for input validation

		while (!valid) // loop until valid input
		{
			if (seeRound == "y" || seeRound == "Y") // see score at end of each round
			{
				seeRoundResults = true; // set bool to true
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
				Creature* player1 = p1Team[0]; // current creature is the first element in player 1's array
				Creature* player2 = p2Team[0]; // current creature is the first element in player 2's array

				int p1Attack = player1->attack(); // calculate p1's attack
				int p2Defense = player2->defense(); // calculate p2's defense

				int damage = p1Attack - p2Defense - player2->getArmor(); // calculate total damage to p2

				if (p1Attack == 0) // Medusa Glare
				{
					damage = player2->getStrengthPoints(); // set damage to kill player 2
				}

				if (p2Defense == 0) // Vampire Charm
				{
					damage = 0; // set damage to 0 because attack missed
				}

				if (damage < 0) // if damage is negative (defense > attack) set damage to 0 so that points aren't added to a defender's strength points
				{
					damage = 0;
				}

				player2->removePoints(damage); // damage player 2's strength points

				if (player2->getStrengthPoints() == 0) // if player 2's creature is dead after attack
				{
					// show user who was in the round and who won the round
					cout << "\nRound " << round << ": " << "Player 1's " << player1->getName() << " (" << player1->getType() << ") vs. Player 2's " << player2->getName() << " (" << player2->getType() << ")\n";
					cout << endl << player1->getName() << " (" << player1->getType() << ") won this round!\n";
					
					++round; // increment round counter
					
					p1Score += 2; // update player 1's score
					p2Score -= 1; // update player 2's score
					
					if (p2Score < 0) // if player 2's score is negative, set to 0
					{
						p2Score = 0;
					}
					
					if (seeRoundResults) // if user wants to see round results
					{
						cout << "\nCurrent Score:\n";
						cout << "Player 1's team: " << p1Score << " points\n"; // p1's score
						cout << "Player 2's team: " << p2Score << " points\n"; // p2's score
					}
					
					Creature* dead = player2; // create pointer to dead creature from p2's team
					deadPile.push_back(dead); // add dead creature to dead pile
					p2Team.erase(p2Team.begin()); // remove dead creature from player2's team
					
					player1->restoreHealth(); // restore some of player 1's creature's health
					Creature* temp = player1; // create temp pointer to player 1's creature
					p1Team.erase(p1Team.begin()); // remove creature from index 0
					p1Team.push_back(temp); // add creature to back of vector
					
					if (p2Team.size() == 0) // if player 2 is out of creatures
					{
						gameActive = false; // game is now over, break out of loop
					}
				}

				else
				{
					int p2Attack = player2->attack(); // calculate p2's attack
					int p1Defense = player1->defense(); // calculate p1's attack

					int damage = p2Attack - p1Defense - player1->getArmor(); // calculate total damage to p1

					if (p2Attack == 0) // Medusa Glare
					{
						damage = player1->getStrengthPoints(); // set damage to kill p1
					}

					if (p1Defense == 0) // Vampire Charm
					{
						damage = 0; // set damage to 0 because attack missed
					}

					if (damage < 0) // if damage is negative, set to 0 so that defender does not gain points
					{
						damage = 0;
					}

					player1->removePoints(damage); // remove strength points from player 1

					if (player1->getStrengthPoints() == 0) // if player1's creature died
					{
						// show user who was in the round and who won the round
						cout << "\nRound " << round << ": " << "Player 1's " << player1->getName() << " (" << player1->getType() << ") vs. Player 2's " << player2->getName() << " (" << player2->getType() << ")\n";
						cout << endl << player2->getName() << " (" << player2->getType() << ") won this round!\n";
						
						++round; // increment round counter
						
						p2Score += 2; // update player 2's score
						p1Score -= 1; // update player 1's score
						
						if (p1Score < 0) // if player 1's score is negative, set to 0
						{
							p1Score = 0;
						}
						
						if (seeRoundResults) // if user wants to see round results
						{
							cout << "\nCurrent Score:\n";
							cout << "Player 1's team: " << p1Score << " points\n";
							cout << "Player 2's team: " << p2Score << " points\n";
						}
						
						Creature* dead = player1; // create pointer to dead creature from p1's team
						deadPile.push_back(dead); // add dead creature to dead pile
						p1Team.erase(p1Team.begin()); // remove dead creature from p1's team
						
						player2->restoreHealth(); // restore some of player 2's creature's health
						Creature* temp = player2; // create temp pointer to player 2's creature
						p2Team.erase(p2Team.begin()); // remove creature from index 0
						p2Team.push_back(temp);// add creature to back of vector

						if (p1Team.size() == 0) // if Player 1 is out of players
						{
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

				int damage = p2Attack - p1Defense - player1->getArmor(); // calculate total damage to p1

				if (p2Attack == 0) // Medusa Glare
				{
					damage = player1->getStrengthPoints(); // set damage to kill p1
				}

				if (p1Defense == 0) // Vampire Charm
				{
					damage = 0; // set damage to 0 because attack missed
				}

				if (damage < 0) // if damage is negative, set to 0 so that defender does not gain points
				{
					damage = 0;
				}

				player1->removePoints(damage); // remove strength points from player 1

				if (player1->getStrengthPoints() == 0) // if player1's creature died
				{
					// show user who was in the round and who won the round
					cout << "\nRound " << round << ": " << "Player 1's " << player1->getName() << " (" << player1->getType() << ") vs. Player 2's " << player2->getName() << " (" << player2->getType() << ")\n";
					cout << endl << player2->getName() << " (" << player2->getType() << ") won this round!\n";
					
					++round; // increment round counter
					
					p2Score += 2; // update player 2's score
					p1Score -= 1; // update player 1's score
					
					if (p1Score < 0) // if player 1's score is negative, set to 0
					{
						p1Score = 0;
					}
					
					if (seeRoundResults) // if user wants to see round results
					{
						cout << "\nCurrent Score:\n";
						cout << "Player 1's team: " << p1Score << " points\n";
						cout << "Player 2's team: " << p2Score << " points\n";
					}
					
					Creature* dead = player1; // create pointer to dead creature from p1's team
					deadPile.push_back(dead); // add dead creature to dead pile
					p1Team.erase(p1Team.begin()); // remove dead creature from p1's team
					
					player2->restoreHealth(); // restore some of player 2's creature's health
					Creature* temp = player2; // create temp pointer to player 2's creature
					p2Team.erase(p2Team.begin()); // remove creature from index 0
					p2Team.push_back(temp);// add creature to back of vector

					if (p1Team.size() == 0) // if Player 1 is out of players
					{
						gameActive = false;
					}
				}

				else
				{
					int p1Attack = player1->attack(); // calculate p1's attack
					int p2Defense = player2->defense(); // calculate p2's defense

					int damage = p1Attack - p2Defense - player2->getArmor(); // calculate total damage to p2

					if (p1Attack == 0) // Medusa Glare
					{
						damage = player2->getStrengthPoints(); // set damage to kill player 2
					}

					if (p2Defense == 0) // Vampire Charm
					{
						damage = 0; // set damage to 0 because attack missed
					}

					if (damage < 0) // if damage is negative (defense > attack) set damage to 0 so that points aren't added to a defender's strength points
					{
						damage = 0;
					}

					player2->removePoints(damage); // damage player 2's strength points

					if (player2->getStrengthPoints() == 0) // if player 2's creature is dead after attack
					{
						// show user who was in the round and who won the round
						cout << "\nRound " << round << ": " << "Player 1's " << player1->getName() << " (" << player1->getType() << ") vs. Player 2's " << player2->getName() << " (" << player2->getType() << ")\n";
						cout << endl << player1->getName() << " (" << player1->getType() << ") won this round!\n";
						
						++round; // increment round counter
						
						p1Score += 2; // update player 1's score
						p2Score -= 1; // update player 2's score
						
						if (p2Score < 0) // if player 2's score is negative, set to 0
						{
							p2Score = 0;
						}
						
						if (seeRoundResults) // if user wants to see round results
						{
							cout << "\nCurrent Score:\n";
							cout << "Player 1's team: " << p1Score << " points\n"; // p1's score
							cout << "Player 2's team: " << p2Score << " points\n"; // p2's score
						}
						
						Creature* dead = player2; // create pointer to dead creature from p2's team
						deadPile.push_back(dead); // add dead creature to dead pile
						p2Team.erase(p2Team.begin()); // remove dead creature from player2's team
						
						player1->restoreHealth(); // restore some of player 1's creature's health
						Creature* temp = player1; // create temp pointer to player 1's creature
						p1Team.erase(p1Team.begin()); // remove creature from index 0
						p1Team.push_back(temp); // add creature to back of vector
						
						if (p2Team.size() == 0) // if player 2 is out of creatures
						{
							gameActive = false; // game is now over, break out of loop
						}
					}
				}
			}
		}

		bool p1Won = false; // initialize bool for who won
		bool tie = false; // initialize bool for tie

		if (p1Score > p2Score) // if p1 scored more points, they won
		{
			p1Won = true;
		}
		else if (p1Score == p2Score) // if p1 and p2 scored the same number of points, it is a tie
		{
			tie = true;
		}
		// else p2 won, so leave the above bools as they are

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

		bool validInput = false; // for input validation

		while (!validInput) // loop until valid input
		{
			if (showDead == "y" || showDead == "Y") // show dead pile
			{
				cout << "\nHere is the dead pile, beginning with the most recent to die:\n";
				for (int index = deadPile.size() - 1; index >= 0; --index)
				{
					cout << deadPile[index]->getName() << endl;
				}

				validInput = true; // break out of while loop
			}
			else if (showDead == "n" || showDead == "N") // don't show dead pile
			{
				cout << "\nOk, I guess I won't show you then!\n";
				validInput = true; // break out of while loop
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
				cout << "\nYou are wise beyond your years.\n\n\n"; // for continuing to use such a glorious program
				
				// dynamically allocated memory needs to be cleared before creating a new tournament
				for (int index = 0; index < p1Team.size(); ++index) // loop through p1's team to deallocate memory
				{
					delete p1Team[index]; // delete pointer at current index
				}
				for (int index = 0; index < p2Team.size(); ++index) // loop through p2's team to deallocate memory
				{
					delete p2Team[index]; // delete pointer at current index
				}
				for (int index = 0; index < deadPile.size(); ++index) // loop through dead pile to deallocate memory
				{
					delete deadPile[index]; // delete pointer at current index
				}
				validString = true; // break out of loop
			}
			else if (again == "n" || again == "N") // don't play again
			{
				cout << "\nToo bad. See you next time.\n\n"; // don't come back. nobody wants you here
				
				// dynamically allocated memory needs to be cleared before creating a new tournament
				for (int index = 0; index < p1Team.size(); ++index) // loop through p1's team to deallocate memory
				{
					delete p1Team[index]; // delete pointer at current index
				}
				for (int index = 0; index < p2Team.size(); ++index) // loop through p2's team to deallocate memory
				{
					delete p2Team[index]; // delete pointer at current index
				}
				for (int index = 0; index < deadPile.size(); ++index) // loop through dead pile to deallocate memory
				{
					delete deadPile[index]; // delete pointer at current index
				}
				return 0;
			}

			/*************************************************************************
			VALGRIND Summary

			==17577==
			==17577== HEAP SUMMARY:
			==17577==     in use at exit: 0 bytes in 0 blocks
			==17577==   total heap usage: 269 allocs, 269 frees, 8,366 bytes allocated
			==17577==
			==17577== All heap blocks were freed -- no leaks are possible
			==17577==
			==17577== For counts of detected and suppressed errors, rerun with: -v
			==17577== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 1 from 1)
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