/****************************************************************************************
** Program name: CS162 Lab 3
** Author: David Mednikov
** Date: 01/28/17
** Description: Player class specification file. This class has 2 member variables. a 
** pointer to a Die object, and the player's current score. There are 6 member functions:
** the constructor which creates the Die object and sets the number of sides, an overloaded
** constructor that creates a LoadedDie objet and sets the number of sides, A destructor
** which deletes the Die pointer, the turn() method which simulates a roll of the die
** and returns the number rolled, winRound() which adds 1 to the player's score, and
** getScore() which is an accessor to the score variable.
****************************************************************************************/

#include "Player.h" // Player header
#include "Die.h" // Die header
#include "LoadedDie.h" // LoadedDie header

/*************************************************************************************
Player class constructor
Parameters: sides
This constructor creates the player and the Die member object. It sets the number of
sides that the die has and initializes the player's score to 0.
*************************************************************************************/
Player::Player(int sides)
{
    die = new Die(sides); // dynamically allocate new Die object and set number of sides
    score = 0; // initialize score to 0
}

/*************************************************************************************
Player class overloaded constructor
Parameters: sides, int loaded
This overloaded constructor creates the player and the LoadedDie member object. It sets 
the number of sides that the loaded die has and initializes the player's score to 0.
*************************************************************************************/
Player::Player(int sides, int loaded)
{
    die = new LoadedDie(sides); // dynamically allocate new LoadedDie object and set number of sides
    score = 0; // initialize score to 0
}

/*************************************************************************************
Player class destructor
This destructor deletes the pointer to a Die object
*************************************************************************************/
Player::~Player()
{
    delete die; // delete dynamically allocated pointer to Die
}

/*************************************************************************************
turn()
This function simulates rolling the die and returns the number rolled by the die
*************************************************************************************/
int Player::turn()
{
     return (*die).roll(); // call roll() function of die object and return value
}

/*************************************************************************************
winRound()
This function increments the player's score by 1
*************************************************************************************/
void Player::winRound()
{
    score++; // increment score variable by 1
}

/*************************************************************************************
getScore()
This function is an accessor to the score variable
*************************************************************************************/
int Player::getScore()
{
    return score; // return player's score
}