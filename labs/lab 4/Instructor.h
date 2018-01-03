/************************************************************************
** Program name: CS162 Lab 4
** Author: David Mednikov
** Date: 02/03/17
** Description: This is the header file for the Instructor class, which is
** derived from the People class
************************************************************************/

#include "Person.h" // Person header
#include <stdlib.h> // rand() and srand()

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

class Instructor: public Person // Derived from Person class
{
    private:
        std::string name; // instructor's name
        int age; // instructor's age
        double rating; // instructor's rating
        
    public:
        Instructor(); // default constructor
        Instructor(std::string n, int a); // overloaded constructor that sets name and age and randomizes rating
        Instructor(std::string n, int a, double r) ;// overloaded contsructor that sets all 3 variables
        ~Instructor() {}; // destructor for memory deallocation
        void do_work(int hours); // instructor do_work function
        double getDouble(); // instructor rating accessor
};

#endif