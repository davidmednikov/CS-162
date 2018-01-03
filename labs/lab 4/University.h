/************************************************************************
** Program name: CS162 Lab 4
** Author: David Mednikov
** Date: 02/03/17
** Description: This is the header file for the University class.
************************************************************************/

#include <string> // strings
#include <vector> // vectors
#include "Person.h" // Person header
#include "Building.h" // Building header

using std::vector; // clean up code

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

class University
{
    private:
        std::string name; // name of the university
        vector<Person*> people; // vector containing people of the university
        vector<Building*> buildings; // vector containing buildings of the university
        
    public:
        University(std::string name); // default constructor
        ~University(); // destructor
        void addBuilding(Building* building); // add building to vector
        void addPerson(Person* person); // add person to vector
        void printPeople(); // print out all people of the university
        void printBuildings(); // print out all buildings of the university
        void work(); // get students and instructors to do some work
        std::string getName(); // name accessor function
};

#endif