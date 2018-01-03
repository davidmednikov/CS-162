/************************************************************************
** Program name: CS162 Project 2
** Author: David Mednikov
** Date: 01/22/17
** Description: This is the implementation file for the List class. This
** class has two member variables: a pointer to an array of Items, and an
** integer containing the number of items in the list. There are 5 member
** functions: a default constructor, destructor, addItem() which adds an
** item to the list, removeItem() which removes an item from the list, and
** displayList() which prints out the list in table format.
************************************************************************/

#include "List.h" // List header
#include <iostream> // for output
#include <iomanip> // to manipulate output and print out in table form

using std::string; // strings
using std::cout; // print out to window
using std::endl; // end line
using std::left; // align left
using std::right; // align right
using std::setw; // set width of area to print
using std::fixed; // to print out doubles with only 2 digits after decimal point
using std::setfill; // to fill the print area with blank spaces to maintain table format

/*************************************************************************
List default constructor
Initializes a List object, creates an array of Items with 4 elements, and
initializes the list length counter to 0
*************************************************************************/
List::List()
{
    itemList = new Item[4]; // initialize Item array of length 4
    listLength = 0; // initialize list length int to 0
}

/*************************************************************************
addItem()
parameters: string itemName, Units unitType, int quantity, double price
Adds an item to the list. Using the parameters, intialize an object of the
Item class and set the values. Make sure that the item doesn't already
exist using an overloaded operator. If the list length is greater then 4,
create a new array that is one element bigger than the existing one to hold
the additional item. Then add the item to the list and increase the list
length by 1. If the list has less than 4 elements, it just adds the item
and increase the list length counter by 1.
*************************************************************************/
void List::addItem(string itemName, Units unitType, int quantity, double price)
{
    Item newItem(itemName, unitType, quantity, price); // create a new Item object from passed parameters
    
    for (int item = 0; item < listLength; item++) // loop through list to make sure item doesn't already exist
    {
        if (itemList[item] == newItem) // test for two items having the same name using overloaded operator
        {
            cout << "This item already exists!\n"; // tell user item already exists, return to main menu
            return;
        }
    }
    
    if (listLength >= 4) // if list length is 4 or greater, the size of the array needs to be increased by 1
    {
        Item* tempList = new Item[listLength]; // dynamically allocate a new pointer to a temporary Item array
        
        for (int item = 0; item < listLength; item++) // copy list to temporary list
        {
            tempList[item] = itemList[item];
        }
        
        delete [] itemList; // delete existing itemList
        
        itemList = new Item[listLength + 1]; // dynamically allocate a new itemList, with the length increased by 1
        
        for (int item = 0; item < listLength; item++) // copy temp list to new itemList
        {
            itemList[item] = tempList[item];
        }
        
        delete [] tempList; // delete dynamically allocated temp list
    }
    
    itemList[listLength] = newItem; // add the item to the list
    listLength++; // increase list length counter by 1
    
    cout << "Item successfully added.\n";
}

/*************************************************************************
removeItem()
parameters: string itemName
Remove an item from the list by comparing the string passed to the function
with the item name of items already in the list. If no match is found, return
to the main menu. When a match is found, remove that item by replacing it
with the item one index higher in the list, and repeat all the way to the
2nd to last element. Then, if the list length of 5 or greater, intialize
a new array with one less element and copy the items to it. After moving
the items around, decrease the list length counter by 1.
*************************************************************************/
void List::removeItem(string itemName)
{
    int deleteIndex = -1; // initialize delete index to -1 (if there is a match the index will never be -1)
    
    for (int item = 0; item < listLength; item++) // loop through list to find item that matches name to be deleted
    {
        if (itemList[item].getName() == itemName) // if the name is a match
        {
            deleteIndex = item; // assign the index to deleteIndex
        }
    }
    
    if (deleteIndex == -1) // a matching item was not found so deleteIndex stayed unchanged
    {
        cout << "\nThat item does not exist on your list.\n"; // let user know and return to main menu
        return;
    }
    
    // if item to be deleted is in any index but the last, remove it and move each element after the deleted item forward one spot.
    if (deleteIndex < listLength - 1)
    {
        for (int i = deleteIndex; i < listLength - 1; i++) // loop through each item beginning with the deleted item and move them up one spot
        {
            itemList[i] = itemList[i+1]; // replace current spot with element in next spot
        }
    }
    
    // if the list has greater than 4 items, make the array 1 element smaller
    if (listLength > 4)
    {
        Item* tempList = new Item[listLength]; // initialize temp list
        for (int item = 0; item < listLength; item++) // loop through item list and temp list to copy elements
        {
            tempList[item] = itemList[item]; // copy items in itemList over to temp list
        }
        
        delete [] itemList; // delete existing itemList
        
        itemList = new Item[listLength - 1]; // create new itemList that is one element smaller than the old list
        
        for (int item = 0; item < listLength - 1; item++) // loop through each element of temp list but the last and copy to the new itemList
        {
            itemList[item] = tempList[item]; // copy from temp list to itemList
        }
        
        delete [] tempList; // delete dynamically allocated temp list
    }
    
    listLength--; // decrease list length counter by 1
    
    cout << "\nItem successfully removed.\n";
}

/*************************************************************************
displayList()
parameters: none
Print out a table header and then loop through the list to print each item's
name, unit type, price, quantity, and extended price (quantity * price).
Also keep a running total and add each item's extended price to it. Print
the total at the end.
*************************************************************************/
void List::displayList()
{
    cout.precision(2); // print doubles with 2 digits after the decimal point (for money)
    
    double total = 0; // initialize total double to 0
    
    // print out header line of list, using constant ints to set width of each column
    cout << endl << left << setw(NAME_WIDTH) << setfill(SPACE) << "Item Name";
    cout << "| "; // column divider
    cout << left << setw(UNIT_WIDTH) << setfill(SPACE) << "Unit";
    cout << "| ";
    cout << left << setw(QUANTITY_WIDTH) << setfill(SPACE) << "Quan";
    cout << "| ";
    cout << left << setw(PRICE_WIDTH) << setfill(SPACE) << "Price";
    cout << " | ";
    cout << left << setw(EXT_PRICE_WIDTH) << setfill(SPACE) << "Ext. Price";
    cout << "\n";
    
    // loop through item list to print out each item
    for (int item = 0; item < listLength; item++)
    {
        double extendedPrice = itemList[item].getPrice() * itemList[item].getQuantity(); // calculate exntended price of item
        
        cout << left << setw(NAME_WIDTH) << setfill(SPACE) << itemList[item].getName(); // print out name
        cout << "| "; // column divider
        cout << left << setw(UNIT_WIDTH) << setfill(SPACE) << itemList[item].getUnitString(); // print out unit
        cout << "| ";
        cout << left << setw(QUANTITY_WIDTH) << setfill(SPACE) << itemList[item].getQuantity(); // print out quantity
        cout << "| ";
        cout << "$" << right << setw(PRICE_WIDTH) << setfill(SPACE) << fixed << itemList[item].getPrice(); // print out price
        cout << "| ";
        cout << "$" << right << setw(EXT_PRICE_WIDTH) << setfill(SPACE) << fixed << extendedPrice; // print out extended price
        cout << "\n";
        
        total += extendedPrice; // add extended price to running total
    }
    
    cout << "\nYour total: $" << fixed << total << endl; // print out total to user
    
}

/* used for testing purposes
void List::testList()
{       
    Item item1("CTC Cereal", BOX, 2, 2.99);
    Item item2("Natty Ice 6er", CAN, 1, 7.99);
    Item item3("Dankest Kush", OUNCE, 1, 2.79);
    Item item4("Prime Rib", POUND, 5, 6.49);
        
    itemList[0] = item1;
    itemList[1] = item2;
    itemList[2] = item3;
    itemList[3] = item4;
    
    listLength = 4;
    
}
*/

/*************************************************************************
List destructor
Delete the dynamically allocated itemList
*************************************************************************/
List::~List()
{
    delete [] itemList;
}