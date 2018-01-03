/************************************************************************
** Program name: CS162 Project 2
** Author: David Mednikov
** Date: 01/22/17
** Description: This is the implementation file for the Item class. This
** class has four member variables: a string containing the item's name,
** an enum containing the item's unit type, an int containing the quanity
** of the item, and a double containing the price of the item. It has 6
** member functions: a default constructor that intializes the variables,
** a 4-parameter constructor that initializes the item with the values
** input by the user, an accessor function that returns the quantity of
** the item, an accessor function that returns the name of the item, an
** accessor function that returns the price of the item, and an accessor
** function that returns the unit type as a string. There is also a friend
** function that is an overloaded equality operator. It compares the item
** name of two item objects and returns true if they match and false if they
** don't,
************************************************************************/

#include "Item.h" // Item header

using std::string; // clean up code

/*************************************************************************
Item default constructor
Initializes an Item object and initializes each variable.
*************************************************************************/
Item::Item()
{
    itemName;
    unitType;
    quantity;
    price;
}

/*************************************************************************
Item constructor
Initializes an Item object and initializes each variable with the values
input by the user.
*************************************************************************/
Item::Item(string name, Units unit, int quant, double cost)
{
    itemName = name;
    unitType = unit;
    quantity = quant;
    price = cost;
}

/*************************************************************************
getQuantity()
quantity variable accessor method
returns int of item's quantity
*************************************************************************/
int Item::getQuantity()
{
    return quantity;
}

/*************************************************************************
getName()
item name variable accessor method
returns string of item's name
*************************************************************************/
string Item::getName()
{
    return itemName;
}

/*************************************************************************
getPrice()
item price variable accessor method
returns int of item's price
*************************************************************************/
double Item::getPrice()
{
    return price;
}

/*************************************************************************
getUnitString()
item unit accessor method
returns string of item's unit type
*************************************************************************/
string Item::getUnitString()
{
    switch(unitType)
    {
        case CAN:
            return "CAN";
        case BOX:
            return "BOX";
        case POUND:
            return "POUND";
        case OUNCE:
            return "OUNCE";
        default:
            return "OTHER";
    }
}

/*************************************************************************
overloaded equality operator (==)
compares two items and returns true if they have the same name
*************************************************************************/
bool operator==(Item item1, Item item2)
{
    return item1.getName() == item2.getName();
}