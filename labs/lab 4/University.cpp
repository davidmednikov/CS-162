/************************************************************************
** Program name: CS162 Lab 4
** Author: David Mednikov
** Date: 02/03/17
** Description: This is the implementation file for the University class.
** There are 3 variables: a string containing the name of the university,
** a vector of pointers to Building objects, and a vector of pointers to
** Person objects. Those 2 vectors contain all people and buildings of
** the university. There is a default constructor, which sets the name
** and initializes the two vectors. The getName() function returns the
** name of the University, the addBuilding() and addPerson() functions
** add a building and person to the university's vectors, and the
** printBuildings() and printPeople() print out the buildings and people
** to the terminal window. The work() function calls each person's do_work
** function and allows the user to decide whether they want to input a 
** number of hours or generate one randomly. The destructor loops through
** each vector and deletes the memory occupied by the Building and
** Person objects.
************************************************************************/

#include "University.h" // University header
#include "Student.h" // Student header
#include "Person.h" // Person header
#include "getInt.h" // getInt() header
#include "showMenu.h" // showMenu() header
#include <iostream> // input and output
#include <stdlib.h> // rand() and srand()

using std::string; // clean up code
using std::vector;
using std::cout;
using std::endl;
using std::fixed; // format output of GPA and teacher rating to one decimal place

/*************************************************************************
University default constructor
parameters: string name
Initializes a University object and initializes each variable.
*************************************************************************/
University::University(string n)
{
    name = n;
    people;
    buildings;
}

/*************************************************************************
getName()
parameters: none
returns: string
Returns the name of the university
*************************************************************************/
string University::getName()
{
    return name;
}

/*************************************************************************
addBuilding(Building* building)
parameters: pointer to building to be added
Add building to the buildings vector
*************************************************************************/
void University::addBuilding(Building* building)
{
    buildings.push_back(building);
}

/*************************************************************************
addPerson(Person* person)
parameters: pointer to person to be added
add person to the people vector
*************************************************************************/
void University::addPerson(Person* person)
{
    people.push_back(person);
}

/*************************************************************************
printBuildings()
parameters: none
prints out each building to the window
*************************************************************************/
void University::printBuildings()
{
    for (int i = 0; i < buildings.size(); i++) // loop through vector of buildings
    {
        Building* building = buildings[i]; // create pointer to building at the current index
        
        cout << "Building name: " << (*building).getName() << endl; // print building name
        cout << "Address:\n" << (*building).getAddress() << endl; // print address
        cout << "Square footage: " << (*building).getSqft() << endl << endl; // print square footage
    }
}

/*************************************************************************
printPeople()
parameters: none
prints out each person to the window
*************************************************************************/
void University::printPeople()
{
    cout.precision(1); // format output of doubles to one decimal place
    
    for (int i = 0; i < people.size(); i++) // loop through vector of people
    {
        Person* person = people[i]; // create pointer to person at current index
        bool isStudent = false; // initialize isStudent bool to false
        
        if (dynamic_cast<Student*>(person)) // if Person pointer can be cast to a Student pointer (if person is a student)
        {
            isStudent = true; // change isStudent bool to true
        }
        
        cout << "Name: " << (*person).getName() << endl; // print out name of person
        
        if (isStudent) // if isStudent is true, print out GPA
        {
            cout << (*person).getName() << " is a student.\n"; // print out that they are a student
            cout << "Age: " << (*person).getAge() << " years old.\n"; // print age
            cout << "GPA: " << fixed << (*person).getDouble() << endl << endl; // print GPA
        }
        else // person is an instructor
        {
            cout << (*person).getName() << " is an instructor.\n"; // print out that they are an instructor
            cout << "Age: " << (*person).getAge() << " years old.\n"; // print out age
            cout << "Instructor Rating: " << fixed << (*person).getDouble() << endl << endl; // print instructor rating
        }
    }
}

/*************************************************************************
work()
parameters: none
Calls the person's do_work function. The user decides which person should
do work and decides if they want to enter the number of hours or generate
one randomly.
*************************************************************************/
void University::work()
{
    cout << "\nWho do you want to do work?\n\n"; // Pick the person to do work
    
    for (int i = 0; i < people.size(); i++) // Loop through people vector
    {
        cout << i+1 << ". " << (*people[i]).getName() << endl; // print out each person as a menu choice
    }
    
    cout << "\nChoose one person by menu number: "; // ask user to pick a menu number
    int person = getInt(1, people.size()) - 1; // validate input and set choice to person int
        
    cout << "\nHow do you want to decide the number of hours?\n"; // ask user how to set number of hours, either by input or random generation
    
    vector<string> menuChoices = { "Generate number of hours randomly", "Enter number of hours to work" }; // menu choices vector
    int choice = showMenu(menuChoices, 1); // print out menu choices, overload to leave out quit option, and validate user's choice
    
    int hours; // initialize hours variable
     
    if (choice == 2) // if user wants to enter number of hours to work
    {
        cout << "\nHow many hours of work do you want " << (*people[person]).getName() << " to do: "; // ask user for number of hours
        hours = getInt(0); // get number of hours >= 0
    }
    else // user wants to generate number randomly
    {
        hours = rand() % 169; // generate random number between 0 and 168 (number of hours in a week)
    }
    
    (*people[person]).do_work(hours); // call person's do work function
   
    cout << endl; // go to new line
}

/*************************************************************************
~University destructor
Loops through people and buildings vectors and deallocates memory allocated
by each pointer.
*************************************************************************/
University::~University()
{
    for (int i = 0; i < buildings.size(); i++) // loop through buildings vector
    {
        delete buildings[i]; // deallocate memory at current index
    }
    
    for (int i = 0; i < people.size(); i++) // loop through people vector
    {
        delete people[i]; // deallocate memory at current index
    }
}