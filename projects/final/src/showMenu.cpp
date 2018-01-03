/*****************************************************************************
** Program name: showMenu() Utility Function
** Author: David Mednikov
** Date: 01/17/17
** Description: This function shows a program menu. It takes a string vector
** as a parameter, then prints out each option and includes an option to quit.
** The user's menu choice is returned to the function that called it.
******************************************************************************/

#include "showMenu.h" // include showMenu() header file
#include "getInt.h" // include getInt() header file
#include <iostream>

using std::string; // clean up code
using std::vector;
using std::cout;
using std::endl;

/**************************************************************************
This function takes a vector of menu option strings and prints out each string with
a number next to it. It also gives the user the option to quit. The function
then gets the menu choice from the user. The getInt method is called to validate the user's input.
***************************************************************************/
int showMenu(vector<string> menuList)
{
	// loop through each element in the vector
	for (int i = 0; i < menuList.size(); i++)
	{
		// print out the menu number and string
		cout << i + 1 << ". " << menuList[i] << endl;
	}

	// print out the option to quit
	cout << menuList.size() + 1 << ". Quit\n" << endl; 

	// get menu choice from user and return to function that called it
	return getInt(1, menuList.size() + 1);
}

/**************************************************************************
This function takes a vector of menu option strings and an int and prints
out each string with a number next to it. It then gets the menu choice from
the user. The getInt method is called to validate the user's input.
***************************************************************************/
int showMenu(vector<string> menuList, int)
{
	// loop through each element in the vector
	for (int i = 0; i < menuList.size(); i++)
	{
		// print out the menu number and string
		cout << i + 1 << ". " << menuList[i] << endl;
	}

	cout << endl;

	// get menu choice from user and return to function that called it
	return getInt(1, menuList.size());
}