/************************************************************************
** Program name: CS162 Lab 4
** Author: David Mednikov
** Date: 02/03/17
** Description: This is the implementation file for the Instructor class.
** There are 3 member variables: string name, int age, and double rating.
** There are 3 constructors, one is the default constructor and it initializes
** the variables. There are two overloaded constructors, both set the name
** and age. One also sets the rating by parameter and the other generates
** one randomly. There are also 2 functions, the do_work function which
** prints out how many hours the instructor graded papers for and and
** instructor rating accessor function called getDouble().
************************************************************************/

#include "Instructor.h" // Instructor header
#include <iostream> // for output

using std::string; // clean up code
using std::cout;

/*************************************************************************
Instructor default constructor
Initializes a Instructor object and initializes each variable.
*************************************************************************/
Instructor::Instructor()
{
    name;
    age;
    rating;
}

/*************************************************************************
Instructor overloaded constructor : derived from overloaded Person constructor
paramters: string name, int age
This constructor sets the name and the age according to the parameters
and randomly generates the instructor rating.
*************************************************************************/
Instructor::Instructor(string n, int a): Person(n, a)
{
    name = n;
    age = a;
    rating = ((rand() % 51) + 0.0) / 10.0; // randomly generate a number between 0.0 and 5.0
}

/*************************************************************************
Instructor overloaded constructor : derived from overloaded Person constructor
paramters: string name, int age
This constructor sets the name, age, and instructor rating according to
the parameres passed.
*************************************************************************/
Instructor::Instructor(string n, int a, double r): Person(n, a, r)
{
    name = n;
    age = a;
    rating = r;
}

/*************************************************************************
do_work(int hours)
parameters: int hours
Prints out how many hours the instructor graded homework for
*************************************************************************/
void Instructor::do_work(int hours)
{
    cout << "\nInstructor " << name << " graded papers for " << hours << " hours.\n";
}

/*************************************************************************
getDouble()
parameters: none
Returns the instructor's rating
*************************************************************************/
double Instructor::getDouble()
{
    return rating;
}