/************************************************************************
** Program name: CS162 Lab 4
** Author: David Mednikov
** Date: 02/03/17
** Description: This is the implementation file for the Person class.
** There are two member variables, the name and age. There are 3 constructors,
** one default and two overloaded ones that set the name and age. One
** overloaded constructor also takes a double and the other does not.
** There are 2 accessor functions to get the name and age of the person.
************************************************************************/

#include "Person.h" // Person header file

using std::string; // clean up code

/*************************************************************************
Person default constructor
Initializes a Person object and initializes each variable.
*************************************************************************/
Person::Person()
{
    name;
    age;
}

/*************************************************************************
Person overloaded constructor
parameters: string name, int age
Initializes a Person object and initializes the variables using the
values passed by the parameters. This constructor will randomly generate
the GPA/rating in the derived classes.
*************************************************************************/
Person::Person(string n, int a)
{
    name = n;
    age = a;
}

/*************************************************************************
Person overloaded constructor
parameters: string name, int age, double GPA/rating
Initializes a Person object and initializes the variables using the
values passed by the parameters. This constructor will also set the GPA/rating
*************************************************************************/
Person::Person(string n, int a, double)
{
    name = n;
    age = a;
}

/*************************************************************************
getName()
parameters: none
Returns the person's name
*************************************************************************/
string Person::getName()
{
    return name;
}

/*************************************************************************
getAge()
parameters: none
Returns the person's age
*************************************************************************/
int Person::getAge()
{
    return age;
}