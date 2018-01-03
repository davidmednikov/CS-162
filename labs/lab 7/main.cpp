/************************************************************************
** Program name: CS162 Lab 7
** Author: David Mednikov
** Date: 02/26/17
** Description: This program allows a user to use and manipulate a doubly
** linked list. There are 4 things that the user can do to the list: Add
** a new node, get the value of the front node, remove the front node, and
** display the entire list to the terminal.
************************************************************************/

#include "Queue.h" // Queue header
#include "getInt.h" // getInt() utility function
#include "showMenu.h" // showMenu() utility function
#include <vector> // for vector
#include <iostream> // output
#include <string> // strings

using std::cout; // clean up code
using std::string;
using std::vector;

int main()
{
	Queue queue; // create object of queue class
	
	vector<string> menuChoices = { "Enter a value to be added to the queue", "Display first node (front) value", "Remove first node (front) value", "Display the queue contents" }; // create menuChoices vector for showMenu()
	
	bool keepRunning = true; // run until user wants to quit
	
	while (keepRunning)
	{
		cout << "\nDoubly Linked Lists are fun...sort of...?\n\n"; // suuuuuure
		
		int choice = showMenu(menuChoices); // print menu and get user's choice
		
		if (choice == 1) // add a value to the queue
		{
			cout << "\nPlease enter a positive integer: "; // ask user for positive int
			int add = getInt(1); // validate that input is >= 1
			queue.addBack(add); // add value to back of queue
		}
		
		else if (choice == 2) // get the value of the front node
		{
			int front = queue.getFront(); // call getFront() function
			
			if (front == -1) // front node is -1, so queue is empty
			{
				cout << "\nThe list is empty!\n";
			}
			else // front node contains a value, queue is not empty
			{
				cout << "\nThe first node contains " << front << ".\n"; // print out front node value
			}
		}
		
		else if (choice == 3) // remove front node from queue
		{
			bool removed = queue.removeFront(); // call removeFront() function
			
			if (removed) // if node was successfully removed
			{
				cout << "\nFront removed successfully.";
			
				if (queue.getFront() == -1) // list is empty, tell user
				{
					cout << " The list is now empty.\n";
				}
				else // there is a new front node, print to user
				{
					cout << " The new front value is " << queue.getFront() << ".\n";
				}
			}
		}
		
		else if (choice == 4) // display the queue to the user
		{
			queue.displayQueue();
		}
		
		else // user wants to quit
		{
			cout << "\nThank you MTV for checking out my crib, now get the hell out!\n\n"; // lol
			keepRunning = false; // break out of while loop
		}
	}
	
	return 0; // quit
}
		