/************************************************************************
** Program name: CS162 Lab 8
** Author: David Mednikov
** Date: 03/05/17
** Description: This program searches and sorts a list of integers stored
** in 4 different text files. The user has 3 options: sequential search,
** sort, and binary search. The sort used by the program is a bubble sort.
** There are 4 text files, each with the digits 1-9 in random order. One
** has a 0 at the beginning of the list, ne has a 0 in the middle of the list,
** and one has a 0 at the end of the list.
************************************************************************/

#include "showMenu.h" // menu utility function
#include <string> // strings
#include <iostream> // user input/output
#include <fstream> // filestream
#include <vector> // vector

using std::string; // clean up code
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;

int search(vector<int> numbers); // prototype for sequential search function
void sort(vector<int> &numbers);// prototype for bubble sort function
int binarySearch(vector<int> numbers);// prototype for binary search function

int main()
{	
	vector<string> menuChoices = { "Non-Binary Search", "Sort a set of Values", "Binary Search" }; // main menu options
	vector<string> files = { "Original", "Early Zero", "Middle Zero", "Late Zero" }; // file options

	ifstream originalFile; // original file input stream
	originalFile.open("original.txt"); // open file to read
	int num; // for each line
	
	vector<int> original; // create vector for ints in text file
	
	while (originalFile >> num) // read through ints in the file
	{
		original.push_back(num); // add the ints to the original vector
	}
	
	originalFile.close(); // close input stream
	
	
	ifstream earlyFile; // early zero file input stream
	earlyFile.open("early.txt"); // open file to read
	
	vector<int> early; // create vector for ints in text file
	while (earlyFile >> num) // read through ints in the file
	{
		early.push_back(num); // add the ints to the early vector
	}
	
	earlyFile.close(); // close input stream
	
	
	ifstream middleFile; // middle zero file input stream
	middleFile.open("middle.txt"); // open file to read
	
	vector<int> middle; // create vector for ints in text file
	while (middleFile >> num) // read through ints in the file
	{
		middle.push_back(num); // add the ints to the middle vector
	}
	
	middleFile.close(); // close input stream
	
	
	ifstream lateFile; // late zero file input stream
	lateFile.open("late.txt"); // open file to read
	
	vector<int> late; // create vector for ints in text file
	while (lateFile >> num) // read through ints in the file
	{
		late.push_back(num); // add the ints to the middle vector
	}
	
	lateFile.close(); // close input stream
	
	bool keepRunning = true; // run until user wants to quit
	bool oSorted = false; // original zero list not sorted
	bool eSorted = false; // early zero list not sorted
	bool mSorted = false; // middle zero list not sorted
	bool lSorted = false; // late zero list not sorted
	
	while(keepRunning) // until user wants to quit
	{
		cout << "\nAl Gore Rhythms\n" << endl; // ba-dum tiss
		
		int choice = showMenu(menuChoices); // get user's menu choice
		
		if (choice == 1) // sequential search
		{
			cout << "\nWhich file do you want to search?" << endl << endl; // ask user which file they want to search
			int file = showMenu(files, 0); // show file choices and get user choice
			
			if (file == 1) // original file
			{
				int position = search(original); // pass to search function and get position
				
				if (position != -1) // target was found
				{
					cout << "\nThe target value (0) was found at position: " << position << endl << endl;
				}
				else // target not found
				{
					cout << "\nThe target value (0) was not found." << endl << endl;
				}
			}
			
			else if (file == 2) // early file
			{
				int position = search(early); // pass to search function and get position
				
				if (position != -1) // target was found
				{
					cout << "\nThe target value (0) was found at position: " << position << endl << endl;
				}
				else // target not found
				{
					cout << "\nThe target value (0) was not found." << endl << endl;
				}
			}
			
			else if (file == 3) // middle file
			{
				int position = search(middle); // pass to search function and get position
				
				if (position != -1) // target was found
				{
					cout << "\nThe target value (0) was found at position: " << position << endl << endl;
				}
				else // target not found
				{
					cout << "\nThe target value (0) was not found." << endl << endl;
				}
			}
			
			else // late file
			{
				int position = search(late); // pass to search function and get position
				
				if (position != -1) // target was found
				{
					cout << "\nThe target value (0) was found at position: " << position << endl << endl;
				}
				else // target not found
				{
					cout << "\nThe target value (0) was not found." << endl << endl;
				}
			}
		}
		
		else if (choice == 2) // bubble sort
		{
			cout << "\nWhich file do you want to sort?" << endl << endl; // ask user which file they want to sort
			int file = showMenu(files, 0); // get user's file choice
			
			if (file == 1) // original
			{
				ofstream originalSorted; // create output stream
				
				cout << "\nWhat do you want to name the output file: "; // get name for output text file
				string fileName; // string for file name
				getline(cin, fileName); // get name from user and add to fileName
				fileName += ".txt"; // append extension to file
				
				originalSorted.open(fileName.c_str()); // create file
				
				sort(original); // sort array
				
				for (int index = 0; index < original.size(); ++index) // step through array
				{
					originalSorted << original.at(index); // write each line to file
					
					if (index != original.size() - 1) // if not last line
					{
						originalSorted << endl; // create a new line
					}
				}
				
				cout << endl << fileName << " has been created.\n"; // tell user that file has been created
				cout << "\nYour sorted array is: "; // print sorted array
				
				for (int index = 0; index < original.size(); ++index) // loop through array
				{
					cout << original.at(index) << " "; // separate ints
					
					if (index == original.size() - 1) // if last int create print new lines
					{
						cout << endl << endl;
					}
				}
				
				originalSorted.close(); // close output
				oSorted = true; // original sorted is true
			}
			
			else if (file == 2) // early
			{
				ofstream earlySorted; // create output stream
				
				cout << "\nWhat do you want to name the output file: "; // get name for output text file
				string fileName; // string for file name
				getline(cin, fileName); // get name from user and add to fileName
				fileName += ".txt"; // append extension to file
				
				earlySorted.open(fileName.c_str()); // create file
				
				sort(early); // sort array
				
				for (int index = 0; index < early.size(); ++index) // step through array
				{
					earlySorted << early.at(index); // write each line to file
					
					if (index != early.size() - 1) // if not last line
					{
						earlySorted << endl; // create a new line
					}
				}
				
				cout << endl << fileName << " has been created.\n"; // tell user that file has been created
				cout << "\nYour sorted array is: "; // print sorted array
				
				for (int index = 0; index < early.size(); ++index) // loop through array
				{
					cout << early.at(index) << " "; // separate ints
					
					if (index == early.size() - 1) // if last int create print new lines
					{
						cout << endl << endl;
					}
				}
				
				earlySorted.close(); // close output stream
				eSorted = true; // earlyl sorted is true
			}
			
			// see comments for 1 and 2, process is exactly the same
			else if (file == 3) // middle
			{
				ofstream middleSorted;
				
				cout << "\nWhat do you want to name the output file: ";
				string fileName;
				getline(cin, fileName);
				fileName += ".txt";
				
				middleSorted.open(fileName.c_str());
				
				sort(middle);
				
				for (int index = 0; index < middle.size(); ++index)
				{
					middleSorted << middle.at(index);
					
					if (index != middle.size() - 1)
					{
						middleSorted << endl;
					}
				}
				
				cout << endl << fileName << " has been created.\n";
				cout << "\nYour sorted array is: ";
				
				for (int index = 0; index < middle.size(); ++index)
				{
					cout << middle.at(index) << " ";
					
					if (index == middle.size() - 1)
					{
						cout << endl << endl;
					}
				}
				
				middleSorted.close();
				mSorted = true;
			}
			
			// see comments for 1 and 2, process is exactly the same
			else // late
			{
				ofstream lateSorted;
				
				cout << "\nWhat do you want to name the output file: ";
				string fileName;
				getline(cin, fileName);
				fileName += ".txt";
				
				lateSorted.open(fileName.c_str());
				
				sort(late);
				
				for (int index = 0; index < late.size(); ++index)
				{
					lateSorted << late.at(index);
					
					if (index != late.size() - 1)
					{
						lateSorted << endl;
					}
				}
				
				cout << endl << fileName << " has been created.\n";
				cout << "\nYour sorted array is: ";
				
				for (int index = 0; index < late.size(); ++index)
				{
					cout << late.at(index) << " ";
					
					if (index == late.size() - 1)
					{
						cout << endl << endl;
					}
				}
				
				lateSorted.close();
				lSorted = true;
			}
			
		}
		
		else if (choice == 3) // binary search
		{
			cout << "\nWhich file do you want to search?" << endl << endl; // ask user which file they want to search
			int file = showMenu(files, 0); // show file choices
			
			if (file == 1) // original file
			{
				if (!oSorted) // original file not sorted
				{
					cout << "\nThe original file has not been sorted yet." << endl << endl;
				}
				else // original file is sorted
				{
					int position = binarySearch(original); // get position of 0
					
					if (position == -1) // 0 not found
					{
						cout << "\nThe target value (0) was not found." << endl << endl;
					}
					else // return position of 0
					{
						cout << "\nThe target value (0) was found at position: " << position << endl << endl;
					}
				}
			}
			
			else if (file == 2) // early file
			{
				if (!eSorted) // early file not sorted
				{
					cout << "\nThe early zero file has not been sorted yet." << endl << endl;
				}
				else // early file is sorted
				{
					int position = binarySearch(early); // get position of 0
					
					if (position == -1) // 0 not found
					{
						cout << "\nThe target value (0) was not found." << endl << endl;
					}
					else // return position of 0
					{
						cout << "\nThe target value (0) was found at position: " << position << endl << endl;
					}
				}
			}
			
			else if (file ==3) // middle file
			{
				if (!mSorted) // middle file not sorted
				{
					cout << "\nThe middle zero file has not been sorted yet." << endl << endl;
				}
				else // middle file is sorted
				{
					int position = binarySearch(middle); // get position of 0
					
					if (position == -1) // 0 not found
					{
						cout << "\nThe target value (0) was not found." << endl << endl;
					}
					else // return position of 0
					{
						cout << "\nThe target value (0) was found at position: " << position << endl << endl;
					}
				}
			}
			
			else // late file
			{
				if (!lSorted) // late file not sorted
				{
					cout << "\nThe late zero file has not been sorted yet." << endl << endl;
				}
				else // late file is sorted
				{
					int position = binarySearch(late); // get position of 0
					
					if (position == -1) // 0 not found
					{
						cout << "\nThe target value (0) was not found." << endl << endl;
					}
					else // return position of 0
					{
						cout << "\nThe target value (0) was found at position: " << position << endl << endl;
					}
				}
			}
		}
		
		else
		{
			keepRunning = false;
			cout << "\nk.\n" << endl;
		}		
	}
				
	return 0;
	
}


/***********************************************************************
int search(vector<int>)
parameters: vector<int>
returns: int
Performs a sequential search through a vector of ints and returns the
position of the first zero it encounters. If a zero is not recountered
the function returns -1.
Searching Lecture, slide 6
https://oregonstate.instructure.com/courses/1616222/files/65660335?module_item_id=17070758
***********************************************************************/
int search(vector<int> numbers)
{	
	for (int index = 0; index < numbers.size(); ++index) // step through vector
	{
		if (numbers.at(index) == 0) // if current index contains 0
		{
			return index + 1; // return position
		}
	}
	
	return -1; // target not found, return -1
}

/***********************************************************************
void sort(&vector<int>)
parameters: vector<int> by reference
returns: none
Performs a bubble sort of a vector of integers.
https://oregonstate.instructure.com/courses/1616222/files/65660334?module_item_id=17070759, slide #5
***********************************************************************/
void sort(vector<int> &numbers)
{
	int elements = numbers.size(); // number of elements left to sort
	
	while (elements > 0) // while elements still need to be sorted
	{
		for (int index = 0; index < numbers.size() - 1; ++index) // step through array
		{
			if (numbers.at(index) > numbers.at(index + 1)) // if current number is greater than next number
			{
				int temp = numbers.at(index); // store current index in temporary int
				numbers.at(index) = numbers.at(index + 1); // place next index into current index
				numbers.at(index + 1) = temp; // write temp int to next index
			}
		}
		
		--elements; // decerement number of elements to be sorted
	}
}

/***********************************************************************
int binarySearch(vector<int>)
parameters: vector<int>
returns: int
Performs a binary search through a vector of ints and returns the
position of 0. If a zero is not recountered the function returns -1.
Searching Lecture, slide 11
https://oregonstate.instructure.com/courses/1616222/files/65660335?module_item_id=17070758
***********************************************************************/
int binarySearch(vector<int> numbers)
{
	int low = 0; // low is 1st element
	int high = numbers.size() - 1; // high us last element
	
	while (low < high) // while pivoting
	{
		int pivot = (low + high) / 2; // get pivot index
		
		if (numbers.at(pivot) == 0) // if target is at pivot
		{
			return pivot + 1; // return position of target
		}
		else if (numbers.at(pivot) > 0) // pivot is greater than target
		{
			high = pivot - 1; // new high to left of pivot
		}
		else // pivot is less than target
		{
			low = pivot + 1; // new low to right of pivot
		}
	}
	
	if (numbers.at(low) == 0) // if last pivot is 0
	{
		return low +1; // return position
	}
	else // 0 not found
	{
		return -1; // return -1
	}
}