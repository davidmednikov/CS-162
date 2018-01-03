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
#include <iostream> // input and output
#include <string> // string
#include <stdlib.h> // seed for rand()
#include <time.h> // time()

using std::string; // clean up code
using std::endl;
using std::cout;
using std::cin;

int main()
{
	srand(time(NULL)); // seed CPU time

	bool playAgain = true; // to keep playing

	while (playAgain) // loop until user wants to stop playing
	{
		cout << "\n\nUltimate Fantasy Combat Game\n\n"; // its the ultimate fantasy combat game

		cout << "1. Vampire\n"; // print out menu options
		cout << "2. Barbarian\n";
		cout << "3. Blue Men\n";
		cout << "4. Medusa\n";
		cout << "5. Harry Potter\n";

		cout << "\nEnter menu number for player 1: "; // get user choice for player 1 creature
		int choice1 = getInt(1, 5);

		cout << "Enter menu number for player 2: "; // get user choice for player 2 creature
		int choice2 = getInt(1, 5);

		Creature* player1; // create pointer to player1
		Creature* player2; // create pointer to player2

		switch (choice1) // instantiate object for player1 creature
        {
            case 1:
                player1 = new Vampire();
                break;
            case 2:
                player1 = new Barbarian();
                break;
            case 3:
                player1 = new BlueMen();
                break;
            case 4:
                player1 = new Medusa();
                break;
            case 5:
                player1 = new HarryPotter();
                break;
            default:
                break;
        }
        
        switch (choice2) // instantiate object for player2 creature
        {
            case 1:
                player2 = new Vampire();
                break;
            case 2:
                player2 = new Barbarian();
                break;
            case 3:
                player2 = new BlueMen();
                break;
            case 4:
                player2 = new Medusa();
                break;
            case 5:
                player2 = new HarryPotter();
                break;
            default:
                break;
        }
                
		bool p1GoesFirst = false; // initialize bool for who goes first
        bool p1Won = false; // initialize bool for who won

		if (rand() % 2) //      50/50 to see who goes first
		{
			cout << "\nPlayer 1 will go first.\n"; // player1 goes first
			p1GoesFirst = true; // set bool to true
		}
		else
		{
			cout << "\nPlayer 2 will go first.\n"; // don't do anything
		}


		if (p1GoesFirst) // if player 1 goes first, use while loop to alternate turns beginning with p1
		{

			bool gameActive = true; // game is still active

			while (gameActive) // while both creatures are alive
			{
                int p1Attack = (*player1).attack(); // calculate p1's attack
				int p2Defense = (*player2).defense(); // calculate p2's defense

				cout << "\nPlayer 1 attack: " << p1Attack << "\nPlayer 2 defense: " << p2Defense << endl;                  // debug

				int damage = p1Attack - p2Defense - (*player2).getArmor(); // calculate damage to p2

				if (p1Attack == 0) // Medusa Glare
				{
					cout << "\nMGlare!\n";
					damage = (*player2).getStrengthPoints(); // set damage to kill player 2
				}

				if (p2Defense == 0) // Vampire Charm
				{
					cout << "\nCharm!\n";
					damage = 0; // attack missed
				}

				if (damage < 0) // if damage is negative (defense > attack) set damage to 0
				{
					damage = 0;
				}

				cout << "\nTotal damage to player 2: " << damage << endl;                 // debug

				(*player2).removePoints(damage); // damage player 2's strength points

				cout << "\nPlayer 2 has " << (*player2).getStrengthPoints() << " strength points left.\n\n\n\n";             // debug
              
				if ((*player2).getStrengthPoints() == 0) // check if p2 is dead after attack
				{
                    p1Won = true; // set bool to true
					gameActive = false; // set bool to false
					cout << "\nPlayer 2 has died.\n";                   // debug
				}

				else
				{
                    int p2Attack = (*player2).attack(); // calculate p2's attack
					int p1Defense = (*player1).defense(); // calculate p1's attack

					cout << "\nPlayer 2 attack: " << p2Attack << "\nPlayer 1 defense: " << p1Defense << endl;               // debug

					int damage = p2Attack - p1Defense - (*player1).getArmor(); // calculate total damage to p1

					if (p2Attack == 0) // Medusa Glare
					{
						cout << "\nGlare!\n";
						damage = (*player1).getStrengthPoints(); // set damage to kill p1
					}

					if (p1Defense == 0) // Vampire Charm
					{
						cout << "\nCharm!\n";
						damage = 0; // attack missed
					}

					if (damage < 0) // if damage is negative, set to 0
					{
						damage = 0;
					}

					(*player1).removePoints(damage); // remove damage points from player 1

					cout << "\nTotal damage to player 1: " << damage << endl;                 // debug

					cout << "\nPlayer 1 has " << (*player1).getStrengthPoints() << " strength points left.\n\n\n\n";                 // debug
					
					if ((*player1).getStrengthPoints() == 0) // if player1 died
					{
						gameActive = false; // end the game
						cout << "\nPlayer 1 has died.\n";                     // debug
					}
				}
			}
		}

		else // Player 2 goes first
		{
			bool gameActive = true; // keep game running

			while (gameActive) // while user wants to play
			{
                int p2Attack = (*player2).attack(); // get player 2's attack
				int p1Defense = (*player1).defense(); // get player 1's attack

				cout << "\nPlayer 2 attack: " << p2Attack << "\nPlayer 1 defense: " << p1Defense << endl;                  // debug

				int damage = p2Attack - p1Defense - (*player1).getArmor(); // calculate total damage

				if (p2Attack == 0) // Medusa Glare
				{
					damage = (*player1).getStrengthPoints(); // damage = defender's strength points
					cout << "\nGlare!\n";                  // debug
				}

				if (p1Defense == 0) // Vampire Charm
				{
					damage = 0; // attack missed
					cout << "\nCharm!\n";                  // debug
				}

				if (damage < 0) // if damage is negative, set to 0
				{
					damage = 0;
				}

				(*player1).removePoints(damage); // hit Player1 with the damage

				cout << "\nTotal damage to player 1: " << damage << endl;                   // debug

				cout << "\nPlayer 1 has " << (*player1).getStrengthPoints() << " strength points left.\n";                    // debug
                
                if ((*player1).getStrengthPoints() == 0) // check if playe1 is out of strength points
				{
					gameActive = false; // if player1 is dead game is over
					cout << "\nPlayer 1 has died.\n";                 // debug
				}

				else
				{
                    int p1Attack = (*player1).attack(); // calc p1's attack
					int p2Defense = (*player2).defense(); // calc p2's defense

					cout << "\nPlayer 1 attack: " << p1Attack << "\nPlayer 2 defense: " << p2Defense << endl;                    // debug

					int damage = p1Attack - p2Defense - (*player2).getArmor(); // calculate damage to p2

					if (p1Attack == 0) // Medusa Glare
					{
						damage = (*player2).getStrengthPoints();
						cout << "\nGlare!\n";                   // debug
					}

					if (p2Defense == 0) // Vampire Charm
					{
						damage = 0;
						cout << "\nCharm!\n";                  // debug
					}

					if (damage < 0) // no negative damage
					{
						damage = 0;
					}

					cout << "\nTotal damage to player 2: " << damage << endl;                 // debug

					(*player2).removePoints(damage); // hitp2 with the damage

					cout << "\nPlayer 2 has " << (*player2).getStrengthPoints() << " strength points left.\n";                 // debug
                    
                    if ((*player2).getStrengthPoints() == 0) // check if p2 died
					{
                        p1Won = true; // set bool to true
						gameActive = false; // game is over
						cout << "\nPlayer 2 has died.\n";                 // debug
					}
                    // else loop back to p2's turn
				}
			}
		}

        if ((*player1).getName() == (*player2).getName()) // If both creatures were the same, the winner has to be printed differently
        {
            cout << endl << (*player1).getName() << " won the game, but you already knew that.\n";                // debug
            cout << "The winner is: ";
            
            if(p1Won)
            {
                cout << "Player 1! (" << (*player1).getName() << ")\n";
            }
            else
            {
                cout << "Player 2! (" << (*player1).getName() << ")\n";
            }
        }
        else // different creatures
        {
            if (p1Won) // player1 won
            {
                cout << "\nYour winner is: " << (*player1).getName() << endl; // print out winner
            }
            else // player 2 won
            {
                cout << "\nYour winner is: " << (*player2).getName() << endl; // print out winner
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
				delete player1; // deallocate memory
				delete player2; // deallocate memory
				validString = true; // break out of loop
			}
			else if (again == "n" || again == "N") // don't play again
			{
				cout << "\nToo bad. See you next time.\n\n"; // don't come back. nobody wants you here
				delete player1; // deallocate memory
				delete player2; // deallocate memory
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