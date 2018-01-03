/*************************************************************************************
** Program name: CS162 Lab 3
** Author: David Mednikov
** Date: 01/28/17
** Description: This is the main method for Lab 3. This program will simulate a game
** of war between two players, each of which has a dice (normal or loaded) that they
** roll once per turn. The higher rolled score of each round wins the round. The winner
** of each round gets a point, and the game is played until the number of rounds 
** specified by the user have been played. This program asks the user whether each 
** player's die is loaded and how many sides the die has. It also asks the user how 
** many turns the game should go on for. After the game ends, the program declares 
** a winner and then quits.
*************************************************************************************/


#include "Game.h" // Game header
#include "getInt.h" // getInt() header
#include <string> // for strings
#include <iostream> // for output and user input
#include <stdlib.h> // seed for rand()
#include <time.h> // time()

using std::endl; // clean up code
using std::cout;
using std::cin;

int main()
{
    cout << "\nHello World War III\n\n"; // welcome user to the game
    
    cout << "Player 1\n";
    cout <<"Loaded Die? 1 for yes, 2 for no: "; // ask user of player 1's die is loaded
    int p1Loaded = getInt(1,2); // validate that input is either 1 or 2
    cout << "How many sides: "; // ask user for number of sides
    int p1Sides = getInt(1); // validate that number of sides is higher than 1
    
    cout << "\nPlayer 2\n";
    cout <<"Loaded Die? 1 for yes, 2 for no: "; // ask if player 2's die is loaded
    int p2Loaded = getInt(1,2); // validate that input is either 1 or 2
    cout << "How many sides: "; // ask user for number of sides
    int p2Sides = getInt(1); // validate that number of sides is higher than 1
    
    srand(time(0)); // seed CPU time
    
    cout << "\nHow many rounds: "; // ask user for number of rounds
    int rounds = getInt(1); // validate that number of rounds is higher than 1
    
    Game* game; // create pointer to Game object
    
    cout << endl;
    
    if (p1Loaded == 1 && p2Loaded == 1) // if both die are loaded
    {
        // initialize game so both players have loaded die
        game = new Game(rounds, p1Sides, p2Sides, 1, 1);
        cout << "Player 1 will be using a loaded die with " << p1Sides << " sides.\n";
        cout << "Player 2 will be using a loaded die with " << p2Sides << " sides.\n";
    }
    else if (p1Loaded == 2 && p2Loaded == 2) // if both die are normal
    {
        // initialize game so neither player has loaded die
        game = new Game(rounds, p1Sides, p2Sides, 0, 0);
        cout << "Player 1 will be using a normal die with " << p1Sides << " sides.\n";
        cout << "Player 2 will be using a normal die with " << p2Sides << " sides.\n";
    }
    else if (p1Loaded == 1 && p2Loaded == 2) // player 1 loaded, player 2 not loaded
    {
        // initialize game so that player 1's die is loaded and player 2's is not
        game = new Game(rounds, p1Sides, p2Sides, 1, 0);
        cout << "Player 1 will be using a loaded die with " << p1Sides << " sides.\n";
        cout << "Player 2 will be using a normal die with " << p2Sides << " sides.\n";
    }
    else // player 1 not loaded, player 2 loaded
    {
        // initialize game so that player 2's die is loaded and player 1's is not
        game = new Game(rounds, p1Sides, p2Sides, 0, 1);
        cout << "Player 1 will be using a normal die with " << p1Sides << " sides.\n";
        cout << "Player 2 will be using a loaded die with " << p2Sides << " sides.\n";
    }
    
    cout << "\nPress Enter to begin.";
    cin.ignore();
    
    cout << "\n\nCommence Battle!\n\n"; // start of game
    
    for (int i = 0; i < rounds; i++) // run game through number of rounds specified by the user
    {
        (*game).oneRound(); // call Game class' oneRound() method for each round
    }
    
    (*game).endGame(); // call endGame() method to print out winner and average rolls
    
    cout << endl; // skip a line
    
/******************************************************************************
VALGRIND report

==18156==
==18156== HEAP SUMMARY:
==18156==     in use at exit: 0 bytes in 0 blocks
==18156==   total heap usage: 5 allocs, 5 frees, 112 bytes allocated
==18156==
==18156== All heap blocks were freed -- no leaks are possible
==18156==
==18156== For counts of detected and suppressed errors, rerun with: -v
==18156== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 1 from 1)
flip2 ~/162/labs/lab3 188%
******************************************************************************/
    
    delete game; // delete allocated Game object
    
    return 0;
}