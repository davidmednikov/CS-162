/************************************************************************
** Program name: CS162 Lab 4
** Author: David Mednikov
** Date: 02/03/17
** Description: This program simulates Oregon State's IT infrastructure
** system. It creates a University object, which has a vector of campus
** buildings and a vector of people from the university. This program
** allows the user to add students, teachers, and buildings to the
** university, print out the people and buildings of the university,
** and make a person of the university do work.
************************************************************************/

#include "Student.h" // Student header
#include "Instructor.h" // Instructor header
#include "Building.h" // Building header
#include "University.h" // University header
#include "getInt.h" // getInt() header
#include "getDouble.h" // getDouble() header
#include "showMenu.h" // showMenu() header
#include <iostream> // output and input
#include <string> // strings
#include <stdlib.h> // seed for rand()

using std::cout; // clean up code
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{    
    srand(time(0)); // seed CPU time
    
    University OSU("Oregon State University"); // create university object
    
    // Create students, instructors, and buildings to add to the university
    Person* student1 = new Student("David Mednikov", 24);
    Person* student2 = new Student("Johnny Beaver", 21);
    Person* instructor1 = new Instructor("Aristotle", 81);
    Person* instructor2 = new Instructor("Neil DeGrasse Tyson", 58);
    Building* building1 = new Building("Kelley Engineering Center", "2500 NW Monroe Ave\nCorvallis, OR 97331", 152166);
    Building* building2 = new Building("Kerr Administration Building", "500 SW Jefferson Way\nCorvallis, OR 97331", 141231);
    Building* building3 = new Building("Milam Hall", "2520 SW Campus Way\nCorvallis, OR 97331", 110283);
    
    // add the newly created objects to the university
    OSU.addPerson(student1);
    OSU.addPerson(instructor1);
    OSU.addPerson(student2);
    OSU.addPerson(instructor2);
    OSU.addBuilding(building1);
    OSU.addBuilding(building2);
    OSU.addBuilding(building3);
       
    vector<string> menuChoices = { "Add Student", "Add Instructor", "Add Building", "Show People", "Show Buildings", "Do Work" }; // create vector containing menu choices
    
    cout << endl; // skip line
    
    while (true)
    {
        cout << OSU.getName() << endl << endl; // print out university's name
        int choice = showMenu(menuChoices); // show menu choices and get user's input
        
        if (choice == 1) // add student
        {
            string name; // initialize name variable
            
            cout << "\nName: "; // ask user for name
            getline(cin, name); // get entire line
            cin.clear(); // clear trailing characters from input stream
            
            cout << "Age: "; // ask user for age
            int age = getInt(1); // validate input is an int >= 1
            
            cout << "GPA:\n1. Enter manually\n2. Generate randomly\n"; // ask user how they want to generate GPA
            int gpaChoice = getInt(1,2); // validate that user inputs 1 or 2
            double gpa; // initialize gpa variable
            
            Person* newStudent; // initialize Person pointer for new student
            
            if (gpaChoice == 1) // input GPA manually
            {
               cout << "\nEnter a decimal number between 0.0 and 4.0: "; // ask user for number between 0.0 and 4.0
               gpa = getDouble(0.0, 4.0); // validate input in range
               newStudent = new Student(name, age, gpa); // create new Student object using inputted name, age, and GPA
            }
            else // randomly generate GPA
            {
               newStudent = new Student(name, age); // create new Student object using inputted name and age; generate GPA randomly
            }
            
            OSU.addPerson(newStudent); // add new Student to university
            
            cout << "\nStudent added successfully.\n\n"; // success message
        }
        
        if (choice == 2) // add instructor
        {
            string name; // initialize name variable
            
            cout << "\nName: "; // ask user for name
            getline(cin, name); // get entire line
            cin.clear(); // clear trailing characters from input stream
            
            cout << "Age: "; // ask user for age
            int age = getInt(1); // validate input is an int >= 1
            
            cout << "Instructor Rating:\n1. Enter manually\n2. Generate randomly\n"; // ask user how they want to generate instructor rating
            int ratingChoice = getInt(1,2);// validate that user inputs 1 or 2
            double rating; // initialize instructor rating variable
            
            Person* newInstructor; //  initialize Person pointer for new instructor
            
            if (ratingChoice == 1) // enter instructor rating manually
            {
               cout << "\nEnter a decimal number between 0.0 and 5.0: "; // ask user for number between 0.0 and 5.0
               rating = getDouble(0.0, 5.0); // validate double input in range
               newInstructor = new Instructor(name, age, rating); // create new Instructor object at initialized pointer, set all 3 variables
            }
            else // generate instructor rating randomly
            {
                newInstructor = new Instructor(name, age); // create new Instructor; set name and age but randomly generate instructor rating
            }

            OSU.addPerson(newInstructor); // add new Instructor to university
            
            cout << "\nInstructor added successfully.\n\n"; // success message
        }
        
        if (choice == 3) // add building
        {
            string name; // initialize name string
            string address; // initialize address string
            
            cout << "\nName: "; // get name from user
            getline(cin, name); // get entire line
            cin.clear(); // clear trailing characters from input stream
            
            cout << "Street Address: "; // ask user for address
            getline(cin, address); // get entire line
            cin.clear(); // clear trailing characters from input stream
            
            string fullAddress = address + "\nCorvallis, OR 97331"; // append city, state, and zip to street address
            
            cout << "Square Footage: "; // ask user for square footage
            int sqft = getInt(1); // validate that input is >= 1
            
            Building* newBuilding = new Building(name, fullAddress, sqft); // create new Building object
            
            OSU.addBuilding(newBuilding); // add building to vector
            
            cout << "\nBuilding added successfully.\n\n"; // success message
        }
        
        if (choice == 4) // print out people
        {
            cout << endl; // skip line
            OSU.printPeople(); // call university's printPeople() method
        }
        
        if (choice == 5) // print out buildings
        {
            cout << endl; // skip line
            OSU.printBuildings(); // call university's printBuildings() method
        }
        
        if (choice == 6) // have someone do work
        {
            OSU.work();
        }
        
        if (choice == 7) // quit
        {
            return 0;
        }
        
    }
}