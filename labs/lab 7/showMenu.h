/************************************************************************
** Program name: showMenu() Utility Function
** Author: David Mednikov
** Date: 01/17/17
** Description: This is the header file for the showMenu() function.
************************************************************************/

#include <string> // for strings
#include <vector> // vectors

#ifndef SHOW_MENU_H
#define SHOW_MENU_H

int showMenu(std::vector<std::string> menuList); // prototype for showMenu() function
int showMenu(std::vector<std::string> menuList, int); // prototype for overloaded showMenu() function that doesn't include a quit option

#endif