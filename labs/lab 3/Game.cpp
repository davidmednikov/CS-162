/*************************************************************************************
** Program name: CS162 Lab 3
** Author: David Mednikov
** Date: 01/28/17
** Description: Game class specification file. This class has 7 member variables. 2
** pointers to player 1 and player 2 objects, doubles holding their totals, and three
** ints holding the current round, the number of rounds left, and the total number of
** rounds. There are 4 functions. The constructor creates a game and sets the sides
** of each die and whether the die is loaded. The destructor deletes the player
** pointers. The oneRound() function rolls both dice and adds a point to the winner's
** score. The endGame() function prints out who won and what the average scores were.
*************************************************************************************/

#include "Game.h" // Game header
#include <iostream> // for output and output
#include <unistd.h> // pause(sleep) for each turn

using std::cout; // code cleanup
using std::endl;


/*************************************************************************************
Game class constructor
Parameters: rounds, player 1 sides, p 2 sides, player 1 loaded, p2 sides
This constructor creates each player for the game. If a die is loaded, the constructor
calls an overloaded Player constructor that contains a loaded die. Otherwise it 
creates players with normal dice. The constructor also sest the number of sides, 
rounds, current round, and rounds left, as well as initializes the running totals at 0.
*************************************************************************************/
Game::Game(int r, int sidesP1, int sidesP2, int loadedP1, int loadedP2)
{
    if (loadedP1) // if player 1's dice is loaded
    {
        player1 = new Player(sidesP1, loadedP1); // overload player constructor
    }
    else // not loaded
    {
        player1 = new Player(sidesP1); // create player object
    }
    
    if (loadedP2) // if player 2's dice is loaded
    {
        player2 = new Player(sidesP2, loadedP2); // overload player constructor
    }
    else // not loaded
    {
        player2 = new Player(sidesP2); //  create player object
    }
    
    rounds = r; // initialize rounds decrementer
    totalRounds = rounds; // set total rounds
    currentRound = 1; // initialize round incrementer
    p1Total = 0.0; // initialize player 1 total score
    p2Total = 0.0; // initialize player 2 total score
}

/*************************************************************************************
Game class destructor
This destructor deletes the two pointers to player obects
*************************************************************************************/
Game::~Game()
{
    delete player1;
    delete player2;
}

/*************************************************************************************
oneRound()
This function carries out one round of the game. It prints out the current round, gets
the number that each player rolled, prints that out to the screen, adds the number to
each player's total, then prints out the winner of the round. The function also adds 
one point to the winner's score, and then tells the user how many rounds are left.
*************************************************************************************/
void Game::oneRound()
{
    cout << "Round " << currentRound << endl << endl; // print out current round
    currentRound++; // increment current round
    
    int p1 = (*player1).turn(); // get player 1's roll
    int p2 = (*player2).turn(); // get player 2's roll
    
    p1Total += p1; // add player 1's roll to player 1's total
    p2Total += p2; // add player 2's roll to player 2's total
    
    cout << "Player 1 rolls a " << p1 << "!\n"; // print out what player 1 rolled
    cout << "Player 2 rolls a " << p2 << "!\n"; // print out what player 1 rolled
    
    if (p1 > p2) // if player 1 won the round
    {
        (*player1).winRound(); // add 1 to player 1's score
        cout << "\nPlayer 1 wins this round!\n"; // print out that player 1 won
    }
    else if (p2 > p1) // if player 2 won the round
    {
        (*player2).winRound(); // ad 1 to player 2's sore
        cout << "\nPlayer 2 wins this round!\n"; // print out that player 2 won
    }
    else // draw
    {
        cout << "\nLooks like this round is a draw!\n"; // tell user it was a draw
    }
    
    cout << "\nCurrent Score:\n"; // print out current scores
    
    // grammar matters folks
    if ((*player1).getScore() == 1)
    {
        cout << "Player 1: " << (*player1).getScore() << " round won" << endl; // player 1's score
    }
    else
    {
        cout << "Player 1: " << (*player1).getScore() << " rounds won" << endl; // player 1's score
    }
    
    if ((*player2).getScore() == 1)
    {
        cout << "Player 2: " << (*player2).getScore() << " round won" << endl; // player 2's score
    }
    else
    {
        cout << "Player 2: " << (*player2).getScore() << " rounds won" << endl; // player 2's score
    }
    
    rounds--; // decrement rounds left counter
    
    if (rounds > 1) // to print out plural number of rounds left
    {
        cout << "\nThere are " << rounds << " rounds left.\n\n\n";
    }
    else if (rounds == 1) // one more round, to avoid saying "There are 1 rounds left"
    {
        cout << "\nThere is 1 round left.\n\n\n";
    }
    
    usleep(750000); // 0.75 second pause // wait 0.75 seconds at end of each turn
}

/*************************************************************************************
endGame()
This function displays the end of game information. It tells the user that the game is
over, then gets the scores of the two players and tells the user which player won. If
the game was a draw, the program tells the user that. It then prints out the average
roll of each player. I did this so that I could make sure that my random rolls were
actually random and so that I could test the weighted dice.
*************************************************************************************/
void Game::endGame()
{    
    cout << "\nThis battle is finished.\n\n\nResults\n\n";
    
    int p1Score = (*player1).getScore(); // get player 1's score
    int p2Score = (*player2).getScore(); // get player 2's score
    
    if (p1Score > p2Score) // if player 1 won
    {
        cout << "Player 1 is your winner!\n\n";
    }
    else if (p2Score > p1Score) // if player 2 won
    {
        cout << "Player 2 is your winner!\n\n";
    }
    else // if it's a draw
    {
        cout << "An unlikely draw!\n\n";
    }
    
    cout << "Player 1's average is: " << p1Total / totalRounds; // print out player 1's average
    cout << "\nPlayer 2's average is: " << p2Total / totalRounds << endl; // print out player 2's average
}