/************************************************************************
** Program name: CS162 Lab 7
** Author: David Mednikov
** Date: 02/26/17
** Description: This is the specification file for the Queue class. This
** file also contains a definition for the QueueNode struct. The Queue
** class has 2 member variables, the pointers to the front and back of the
** queue, as well as 6 member functions: default constructor, destructor,
** add node to back, get value of front node, remove front node, and
** display the queue to the user.
************************************************************************/

#include <cstdlib> // for NULL - no pointers in this program are actually null though!

#ifndef QUEUE
#define QUEUE

struct QueueNode // QueueNode struct definition
{
	
	int num; // node value
	QueueNode* previousNode; // pointer to previous node
	QueueNode* nextNode; // pointer to next node
	
	QueueNode(int n) // constructor with just 1 parameter, only used when creating first node
	{
		num = n; // assign value to node
		previousNode = NULL; // make pointer null TEMPORARILY, when making front pointer in queue constructor
		nextNode = NULL; // make pointer null TEMPORARILY, when making front pointer in queue constructor
	}
	
	QueueNode(int n, QueueNode* left, QueueNode* right) // constructor with value and 2 pointers as parameters
	{
		num = n; // assign value
		previousNode = left; // assign left node to previousNode
		nextNode = right; // assign right node to nextNode
	}
};

class Queue // Queue class definition
{
	private:
		QueueNode* front; // pointer to front node
		QueueNode* back; // pointer to back node
	public:
		Queue(); // default constructor
		~Queue(); // destructor
		void addBack(int n); // add node with inputted value to the end of the list
		int getFront(); // get the value in the front node
		bool removeFront(); // remove the front node (make it's value -1)
		void displayQueue(); // print out the queue
};

#endif