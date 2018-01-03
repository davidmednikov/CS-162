/************************************************************************
** Program name: CS162 Project 2
** Author: David Mednikov
** Date: 01/22/17
** Description: This program simulates a shopping list. It uses the List
** object, which contains an array to hold a list of Item objects, to
** manipulate the shopping list. This program allows the user to add
** an item, remove an item, and print out the list.
************************************************************************/

#include "List.h" // List header
#include "Item.h" // Item header
#include "showMenu.h" // showMenu() utility function
#include "getInt.h" // getInt() utility function
#include "getDouble.h" // getDouble() utility function
#include <iostream> // for user input and output
#include <algorithm> // convert string to lowercase

using std::string; // clean up code
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    List list; // initialize List object
    
    bool listInitialized = false; // initialize listInitialized bool to false

    vector<string> menuChoices = { "Add Item to List", "Remove Item from List", "Display List" }; // create vector containing menu choices
    
    while (true) // loop until user wants to quit program
    {
        cout << "\nShopping List Program\n\n";
        int choice = showMenu(menuChoices); // print out menu and get user's choice
        
        // add item to list
        if (choice == 1)
        {
            string name; // intialize name string
            string unit; // initialize unit string
            int quantity; // initialize quantity int
            double price; // initialize price double
            Units unitType; // initialize unit type enum variable
            bool validUnit = false; // for input validation
            bool validName = false;
            
            while (!validName)
            {
                // ask user for item name
                cout << "\nProduct name: ";
                getline(cin, name);
                cin.clear(); // clear trailing characters from input stream
                if (cin.gcount() > 1) 
                {
                    cout << "You entered some f'd up characters. Please Try again: ";
                }
                else
                {
                    validName = true;
                }
            }
            
            // validate user's input for unit type
            while (!validUnit)
            {
                // ask user to input unit type
                cout << "Unit type (Can, Box, Pound, Ounce): ";
                getline(cin, unit);
                
                // convert unit input to lowercase to validate input
                std::transform(unit.begin(), unit.end(), unit.begin(), ::tolower); //https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/

                if (unit == "can") // if user entered can
                {
                    unitType = CAN; // set unitType variable
                    validUnit = true;// change valid unit bool to true to break out of loop
                }                    
                else if (unit ==  "box")
                {
                    unitType = BOX;
                    validUnit = true;
                }
                else if (unit == "pound")
                {
                    unitType = POUND;
                    validUnit = true;
                }
                else if (unit == "ounce")
                {
                    unitType = OUNCE;
                    validUnit = true;
                }
                else // if the input is none of those 4
                {
                         cout << "You did not enter a valid unit type.\n";
                }
                
            }
            
            cout << "How many: "; // ask user for quantity of item
            quantity = getInt(1); // validate input greater >= 1
            cout << "How much (¿Cuanto Cuesta?): "; // ask user for price
            price = getDouble(0.00); // validate price >= $0.00
            
            cout << endl; // go to next line
            
            list.addItem(name, unitType, quantity, price); // call addItem function to add item to list
            
            listInitialized = true; // set initialized bool to true
        }
        
        if (choice == 2) // remove item from list
        {
            if (listInitialized == false) // if no items have been added to list
            {
                cout << "\nYou haven't added any items yet!\n";
            }
            else // items have been added
            {
                string name; // initialize name variable
                
                cout << "\nName of product you want to delete: "; // ask user for name of item to delete
                getline(cin, name);
                cin.clear(); // clear trailing characters from input stream
            
                list.removeItem(name); // pass input too removeItem function
            }
        }
        
        if (choice == 3) // print list
        {
            if (listInitialized == false) // if no items have been added to list
            {
                cout << "\nYou haven't added any items yet!\n";
            }
            else
            {
                list.displayList(); // call displayList() function to print list
            }
        }
        
        /*                              Code used for testing list functions
        if (choice == 4)
        {
            if (listInitialized == true)
            {
                cout << "\nYou've already initialized the list!\n";
            }
            else
            {
                list.testList();
                listInitialized = true;
            }
        }
        */
        
        if (choice == 4) // user wants to quit
        {
            cout << "\nThanks for stopping by! See you next time!\n\n";
            return 0;
            
/*************************************************************************     
                            VALGRIND REPORT
                            
                            
            
            
        }
        
    }
    
    return 0;
}