/************************************************************************
** Program name: CS162 Lab 5
** Author: David Mednikov
** Date: 02/09/17
** Description: This is the main() method for Lab 5, which tests our
** ability to use recursion and input validation. There are 4 menu options
** in this program. reverseString() takes a string as input and prints
** out the string in reverse. sumArray() takes an array of integers and
** returns the sum of all elements in the array. triangularNum() takes a
** number n and returns the triangular number. All inputs (string, array,
** and int n) are all input by the user and validated before being passed
** to the respective functions.
************************************************************************/

#include "reverseString.h" // reverseString() header
#include "showMenu.h" // showMenu() header
#include "sumArray.h" // sumArray() header
#include "triangularNum.h" // triangularNum() header
#include "getInt.h" // getInt() header
#include <iostream> // input and output
#include <string> // strings
#include <vector> // vector for menu choices

using std::cout; // clean up code
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::stoi; // convert string to int

int main()
{
    vector<string> menuChoices = { "Reverse a string", "Calculate sum of an array", "Calculate triangular number" }; // create vector of menu choices
    
    // run until user wants to quit
    while (true)
    {
        cout << "\nNobody knows recursion better than me!\n\n"; // Make Recursion Great Again
        int choice = showMenu(menuChoices); // send menu choices to showMenu() and get user's menu choice
        
        if (choice == 1) // user chooses to reverse string
        {
            cout << "\nEnter a string: "; // ask user for input
            string input; // initialize input variable
            getline(cin, input); // use getline to get all text up to newline
            cout << endl; // skip line
            reverseString(input); // pass input string and string length to reverseString()
            cout << endl; // skip line
        }
        
        else if (choice == 2) // user chose to add array
        {
            int* array = new int[1]; // initialize array of length 1
            bool keepRunning = true; // keep running until user wants to quit
            int length = 0; // initialize length to 0
            cout << endl; // skip line
            
            while (keepRunning) // while user wants to add inputs
            {
                cout << "Enter a number or s to stop: "; // ask user for array element, quit if s
                string input; // initialize input variable
                cin >> input; // store input in variable
                
                bool validInput = false; // guilty until proven innocent
                int toAdd; // initialize integer to be added
                
                if (input == "s") // if user inputs s
                {
                    keepRunning = false; // stop running while loop to ask for elements, add up array
                }
                else // user still adding elements
                {
                    try
                    {
                        std::size_t stringLength = 0; // create unsigned int, for validating using stoi()
                        std::size_t* index = &stringLength; // create pointer to unsigned int, for validating using stoi()
                        toAdd = stoi(input, index);  // convert input string to int, second paramter stores number of characters parsed to int
                        if (*index != input.length()) // if number of characters parsed does not equal length of string, there were trailing characters, not an int
                        {
                            cout << "You did not enter an integer.\n"; // tell user they did not enter an int
                        }
                        else
                        {
                            ++length; // increment length by 1
                            validInput = true; // input is valid
                        }
                    }
                    catch(...) // catch error thrown by casting string to int
                    {
                        cout << "You did not enter an integer.\n"; // tell user they did not enter an int
                    }
                }
                
                if (validInput) // if input was valid, increase length of array by 1 (using temp array) and add to new array
                {
                    if (length == 1) // if length is 1 (which it was initialized at) so no elements yet
                    {
                        array[0] = toAdd; // add int to first element
                    }
                    
                    else // more than 1 element in array
                    {
                        int* tempArray = new int[length - 1]; // initialize temp array to copy existing array
                    
                        for (int index = 0; index < length - 1; ++index) // loop through both arrays to copy elements from array to temp array
                        {
                            tempArray[index] = array[index]; // copy element from array to temp array
                        }
                        
                        delete [] array; // delete array
                    
                        array = new int[length]; // allocate new array that has 1 more element
                    
                        for (int index = 0; index < length - 1; ++index) // loop through both arrays to copy elements from temp array to array
                        {
                            array[index] = tempArray[index]; // copy element from temp to array
                        }
                    
                        delete [] tempArray; // delete allocated temp array
                    
                        array[length - 1] = toAdd; // add new int to last element
                    }
                }
            }         
            
            cout << "\nThe sum of the array is " << sumArray(array, length) << endl << endl; // call sumArray() method and print out sum

            delete [] array; // delete allocated array
        }

        else if (choice == 3) // user wants triangular number
        {
            cout << "\nEnter a positive number: "; // ask user for positive number
            int n = getInt(1); // user getInt() to validate input
            cout << "\nThe triangular number of " << n << " is " << triangularNum(n) << endl << endl; // call triangularNum() method and print out triangular number
        }
        
        else if (choice == 4) // user wants to quit
        {
            cout << endl; // skip line
            return 0; // end program
        } 
    }
}