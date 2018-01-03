#include "getInt.h"
#include <iostream>

using std::cin;
using std::cout;

int getInt()
{
    int input;
    bool valid = true;
    while (valid)
    {
        cin >> input;
    
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "You did not enter an integer. Please Try again: ";
        }

        else
        {
            return input;
        }
    }
}

int getInt(int lowerBound)
{
    int input;
    bool valid = true;
    while (valid)
    {
        cin >> input;
    
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "You did not enter an integer. Please Try again: ";
        }
        else if (input < lowerBound )
        {
            cout << "You did not enter a number in the specified range. Please try again: ";
        }
        else
        {
            return input;
        }
    }
}

int getInt(int lowerBound, int higherBound)
{
    int input;
    bool valid = true;
    while (valid)
    {
        cin >> input;
    
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "You did not enter an integer. Please Try again: ";
        }
        else if (input < lowerBound || input > higherBound)
        {
            cout << "You did not enter a number in the specified range. Please try again: ";
        }
        else
        {
            return input;
        }
    }
}