/************************************************************************
** Program name: CS162 Lab 4
** Author: David Mednikov
** Date: 02/03/17
** Description: This is the header file for the Person class.
************************************************************************/

#include <string> // strings

#ifndef PERSON_H
#define PERSON_H

class Person
{
    private:
        std::string name; // person's name
        int age; // person's age
        
    public:
        Person(); // default constructor
        virtual ~Person() {}; // virtual destructor to clear allocated memory
        Person(std::string n, int a); // overloaded constructor that randomizes gpa/rating
        Person(std::string n, int a, double); // overloaded constructor that initializes all 3 variables
        virtual void do_work(int hours) {}; // do_work virtual function
        virtual double getDouble() {}; // getDouble virtual function to access gpa/rating
        std::string getName(); // name accessor
        int getAge(); // age accessor
};

#endif