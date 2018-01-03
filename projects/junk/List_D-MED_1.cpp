#include "List.h"
#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::fixed;
using std::setfill;

List::List()
{
    itemList = new Item[4];
    listLength = 0;
}

void List::addItem(string itemName, Units unitType, int quantity, double price)
{
    Item newItem(itemName, unitType, quantity, price);
    
    for (int item = 0; item < listLength; item++)
    {
        if (itemList[item] == newItem)
        {
            cout << "This item already exists!\n";
            return;
        }
    }
    
    if (listLength >= 4)
    {
        Item* tempList = new Item[listLength + 1];
        for (int item = 0; item < listLength; item++)
        {
            tempList[item] = itemList[item];
        }
        
        delete [] itemList;
        
        itemList = new Item[listLength + 1];
        
        for (int item = 0; item < listLength; item++)
        {
            itemList[item] = tempList[item];
        }
        
        delete [] tempList;
    }
    
    itemList[listLength] = newItem;
    listLength++;
    
    cout << "Item successfully added.\n";
}
    
void List::removeItem(string itemName)
{
    int deleteIndex;
    
    for (int item = 0; item < listLength; item++)
    {
        if (itemList[item].getName() == itemName)
        {
            deleteIndex = item;
        }
    }
    
    cout << "Found delete Index: << deleteIndex << endl;
    
    if (deleteIndex == NULL)
    {
        cout << "That item does not exist in your cart.\n";
        return;
    }
    
    for (int i = deleteIndex; i < listLength; i++)
    {
        itemList[i] = itemList[i+1];
    }
    
    if (listLength > 4)
    {
        Item* tempList = new Item[listLength - 1];
        for (int item = 0; item < listLength; item++)
        {
            tempList[item] = itemList[item];
        }
        
        delete [] itemList;
        
        itemList = new Item[listLength - 1];
        
        for (int item = 0; item < listLength - 1; item++)
        {
            itemList[item] = tempList[item];
        }
        
        delete [] tempList;
    }
    
    listLength--;
    
    cout << "Item successfully removed.\n";
}

void List::displayList()
{
    cout.precision(2);
    
    double total = 0;
    
    cout << endl << left << setw(NAME_WIDTH) << setfill(SPACE) << "Item Name";
    cout << "| ";
    cout << left << setw(UNIT_WIDTH) << setfill(SPACE) << "Unit";
    cout << "| ";
    cout << left << setw(QUANTITY_WIDTH) << setfill(SPACE) << "Quan";
    cout << "| ";
    cout << left << setw(PRICE_WIDTH) << setfill(SPACE) << "Price";
    cout << " | ";
    cout << left << setw(EXT_PRICE_WIDTH) << setfill(SPACE) << "Ext. Price";
    cout << "\n";
    
    for (int item = 0; item < listLength; item++)
    {
        cout << left << setw(NAME_WIDTH) << setfill(SPACE) << itemList[item].getName();
        cout << "| ";
        cout << left << setw(UNIT_WIDTH) << setfill(SPACE) << itemList[item].getUnitString();
        cout << "| ";
        cout << left << setw(QUANTITY_WIDTH) << setfill(SPACE) << itemList[item].getQuantity();
        cout << "| ";
        cout << "$" << left << setw(PRICE_WIDTH) << setfill(SPACE) << fixed << itemList[item].getPrice();
        cout << "| ";
        cout << "$" << left << setw(EXT_PRICE_WIDTH) << setfill(SPACE) << fixed << itemList[item].getPrice() * itemList[item].getQuantity();
        cout << "\n";
        
        total += itemList[item].getPrice() * itemList[item].getQuantity();
    }
    
    cout << "\nYour total: $" << fixed << total << endl;
    
}

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

List::~List()
{
    delete [] itemList;
}