/************************************************************************
** Program name: CS162 Lab 4
** Author: David Mednikov
** Date: 02/03/17
** Description: This is the implementation file for the Student class.
** The student class has 3 variables: the name, age, and GPA. There are
** 3 constructors: a default that initializes the variables and two
** overloaded ones. One overloaded constructor randomly generates the GPA
** and the other assigns the gpa that the user inputted. There is a do_work
** function which makes the student do work for the number of hours that is
** input by the user or generated randomly. The getDouble method is
** an accessor that returns the GPA of the student.
************************************************************************/

#include "Student.h" // Student header
#include <iostream> // four output
#include <stdlib.h> // rand() and srand()

using std::string; // clean up code
using std::cout;
using std::endl;

/*************************************************************************
Student default constructor
Initializes a Student object and initializes each variable.
*************************************************************************/
Student::Student()
{
    name;
    age;
    GPA;
}

/*************************************************************************
Student overloaded constructor : derived from overloaded Person constructor
paramters: string name, int age
This constructor sets the name and the age according to the parameters
and randomly generates the GPA.
*************************************************************************/
Student::Student(string n, int a): Person(n, a)
{
    name = n;
    age = a;
    GPA = ((rand() % 41) + 0.0) / 10.0; // randomly generate a number between 0.0 and 4.0.
}

/*************************************************************************
Student overloaded constructor : derived from overloaded Person constructor
paramters: string name, int age, double GPA
This constructor sets the name, age, and GPA according to the input
*************************************************************************/
Student::Student(string n, int a, double g): Person(n, a, g)
{
    name = n;
    age = a;
    GPA = g;
}

/*************************************************************************
do_work(int hours)
parameters: int hours
Prints out how many hours of homework the student did
*************************************************************************/
void Student::do_work(int hours)
{
    cout << endl << name << " did " << hours << " hours of homework.\n";
}

/*************************************************************************
getDouble()
parameters: none
Returns the student's GPA
*************************************************************************/
double Student::getDouble()
{
    return GPA;
}