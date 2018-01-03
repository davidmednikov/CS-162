/****************************************************************************
** Program name: CS162 Lab 9
** Author: David Mednikov
** Date: 03/12/17
** Description: This program implements 2 data structures: a queue and a stack.
** The queue function simulates a buffer. The user enters the probability that
** a number will be pushed to the queue and the probability that a number will be
** removed from the front of the queue. The user also selects the number of rounds.
** The program goes through the number of rounds and adds/removes numbers
** based on the percentages entered by the user. The stack function takes
** an input string and displays a palindrome based on the string to the screen.
****************************************************************************/


#include "showMenu.h" // showMenu utility
#include "getInt.h"
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h> // seed for rand()
#include <time.h> // time()

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::getline;

void generate(int percent, vector<int> &queue); // prototype for generate function

int main()
{
	srand(time(NULL)); // seed CPU time

	bool running = true; // run until user wants to quit
	vector<string> menuChoices = { "Queue", "Stack" }; // vector of menu choices
	
	while (running) // until quitting
	{
		cout << "\nLab 9\n" << endl; // title
		
		int choice = showMenu(menuChoices); // show menu options and get user's choice
		
		if (choice == 1) // queue
		{
			vector<int> queue; // create the queue
			
			int size = queue.size(); //  get the size of the queue
			double prevAverage; // create int for previous average
			double average; // create int for average
			
			cout << "\nHow many rounds: "; // ask user for number of rounds
			int rounds = getInt(1); // validate number > 1
			
			cout << "\nProbability of adding a number: "; // ask user for chance that a number gets added
			int addPercent = getInt(0, 100); // get number between 0 and 100
			
			cout << "Probability of removing a number: "; // ask user for chance that a number gets removed
			int removePercent = getInt(0, 100); // get number between 0 and 100
			
			for (int round = 1; round <= rounds; ++round) // loop through number of rounds specified by user
			{	
				prevAverage = average; // save current average as previous average
				
				cout << "\n\nRound " << round  << ":"<< endl;
				
				generate(addPercent, queue); // call generate function
				
				int random = rand() % 100 + 1; // generate number between 1 annd 100 to see if we're going to remove the first number from the queue
				
				if (random <= removePercent) // if randomly generated number is less than the remove percentage, remove the first number in
				{
					if (queue.size() > 0) // if queue is not empty
					{
						int erase = queue[0]; // get number being erased
						queue.erase(queue.begin()); // erase 1st element
						cout << erase << " has been removed from the front of the queue." << endl;
					}
					else // if queue is already empty
					{
						cout << "Could not remove a number becase the queue is empty!" << endl; // print that queue is empty
					}
				}
				else
				{
					cout << "Nothing removed" << endl;
				}
				
				size = queue.size(); // get current size of queue
				
				if (round == 1) // calculate average different during 1st round
				{
					if (size == 0) // size is 0 so average is 0
					{
						average = 0.0;
					}
					else // size is 1 so average is 1
					{
						average = 1.0;
					}
				}
				else // round is > 1, so calculate average normally
				{
					average = ((prevAverage * (round - 1) + size)) / round; // calculate the average normally
				}
				
				cout << "\nThe length of the queue is: " << size << endl;
				cout << "The average length of the queue is: " << average << endl; // print current average
			}
			
			cout << endl; // skip a line
		}
		
		else if (choice == 2) // stack
		{
			string input; // create string for input
			cout << "\nEnter a string: "; // ask user for string
			getline(cin, input); // get input
			
			int stringLength = input.length(); // calculate length of string
			
			vector<char> string; // create vector of chars
			
			for (int index = 0; index < stringLength; ++index) // copy string to vector of chars
			{
				char letter = input[index]; // get char at current index
				string.push_back(letter); // add char to vector
			}
			
			for (int index = stringLength - 1; index >= 0; --index) // loop from end of original input string to 1st character
			{
				char nextLetter = string[index]; // get character to add
				string.push_back(nextLetter); // add character to back of string
			}
			
			stringLength = string.size(); // update string size
			
			cout << "\nYour palindrome: "; // print palindrome to user
			
			for (int index = 0; index < stringLength; ++index) // loop through each index
			{
				cout << string[index]; // print out palindrome
			}
			
			cout << endl << endl; // skip a couple lines
		}
		
		else // user wants to quit
		{
			running = false; // flip bool to false to break out of loop
		}
	}
	
	return 0; // user is done, break out of loop
	
}

/*************************************************************************
generate()
input: int percentage, vector<int> queue passed by reference
returns: none
Generates a random number and, and adds it to the queue n% (percentage
passed to function) of the time.
*************************************************************************/
void generate(int percentage, vector<int> &queue)
{
	int random = rand() % 100 + 1; // generate random number between 1-100
	
	if (random <= percentage) // if the random number is less than the specified percentage
	{
		queue.push_back(rand()); // add the number to the queue
		cout << endl << queue.back() << " has been added to the back of the queue." << endl; // tell user number has been added to the queue
	}
	else // number not being added
	{
		cout << "\nNothing added" << endl; // display to user that nothing was added
	}
}
	