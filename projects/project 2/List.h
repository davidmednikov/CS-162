/************************************************************************
** Program name: CS162 Project 2
** Author: David Mednikov
** Date: 01/22/17
** Description: This is the header file for the List class.
************************************************************************/

#include "Item.h" // Item header

#ifndef LIST_H
#define LIST_H

// constant ints for printing out the list
const int NAME_WIDTH = 18;
const int UNIT_WIDTH = 7;
const int QUANTITY_WIDTH = 5;
const int PRICE_WIDTH = 7;
const int EXT_PRICE_WIDTH = 10;
const char SPACE = ' ';

class List
{
    private:
        Item* itemList; // pointer to Item to be used as an array of Items
        int listLength; // current length of list
    
    public:
        List(); // default constructor
        ~List(); // destructor
        void addItem(std::string itemName, Units unitType, int quantity, double price); // item to add method, 4 params
        void removeItem(std::string itemName); // remove item, takes item name as parameter
        void displayList(); // display list
        // void testList();        used for testing
};

#endif