/************************************************************************
** Program name: CS162 Lab 4
** Author: David Mednikov
** Date: 02/03/17
** Description: This is the header file for the Student class, which is
** derived from the Person class
************************************************************************/

#include "Person.h" // Person header

#ifndef STUDENT_H
#define STUDENT_H

class Student: public Person // derived from Person class
{
    private:
        std::string name; // student's name
        int age; // student's age
        double GPA; // student's GPA
        
    public:
        Student(); // default constructor
        Student(std::string n, int a); // overloaded constructor that randomly generates a GPA
        Student(std::string n, int a, double g); // overloaded constructor that sets all 3 variables
        ~Student() {}; // destructor for memory deallocation
        void do_work(int hours); // student do_work function
        double getDouble(); // return GPA
};

#endif