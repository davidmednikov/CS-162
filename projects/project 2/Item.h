/************************************************************************
** Program name: CS162 Project 2
** Author: David Mednikov
** Date: 01/22/17
** Description: This is the header file for the Item class.
************************************************************************/

#include <string>

#ifndef ITEM_H
#define ITEM_H

enum Units { CAN, BOX, POUND, OUNCE }; // define 4 enums for the unit

class Item // Item class declaration
{
    private:
        std::string itemName; // name of item
        Units unitType; // Units enum containing type of unit
        int quantity; // quanity to buy
        double price; // price of item
        
    public:
        Item(); // default constructor
        Item(std::string name, Units unit, int quant, double cost); // constructor
        int getQuantity(); // quantity accessor function
        double getPrice(); // price accessor function
        std::string getName(); // name accessor function
        std::string getUnitString(); // unit type in string format (for output)
        friend bool operator==(Item item1, Item item2); // overloaded equality operator
};

#endif 