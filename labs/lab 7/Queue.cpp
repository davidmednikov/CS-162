/************************************************************************
** Program name: CS162 Lab 7
** Author: David Mednikov
** Date: 02/26/17
** Description: This is the implementation file for the Queue class.
************************************************************************/

#include "Queue.h" // include Queue header
#include <iostream> // for output

using std::cout; // clean up code
using std::endl;

/*************************************************************************
Queue default constructor
Creates a queue by creating a empty front node (value = -1) and making the
two pointers in the front node point to itself. The back pointer also points
to the front node.
*************************************************************************/
Queue::Queue() //
{
	front = new QueueNode(-1);
	front->nextNode = front;
	front->previousNode = front;
	back = front;
}

/*************************************************************************
Queue destructor
Loop through the queue and delete each node from memory
*************************************************************************/
Queue::~Queue()
{
	QueueNode* current = front->nextNode; // start at node after front
	
	while (current != front) // while current node is not the front node
	{
		QueueNode* temp = current->nextNode; // create temp pointer to next node
		delete current; // delete current node from memory
		current = temp; // make the next node the current node
	}
	
	// all nodes other than the front have now been deleted
	
	delete front; // delete the front node from memory, all memory now deallocated
	
	/*************************************************************************
	VALGRIND Summary

	==2568==
	==2568== HEAP SUMMARY:
	==2568==     in use at exit: 0 bytes in 0 blocks
	==2568==   total heap usage: 35 allocs, 35 frees, 1,171 bytes allocated
	==2568==
	==2568== All heap blocks were freed -- no leaks are possible
	==2568==
	==2568== For counts of detected and suppressed errors, rerun with: -v
	==2568== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 1 from 1)
	*************************************************************************/
}

/*************************************************************************
addBack(int n)
parameters: int n (value to be added)
returns: void
Add a new node to the back of the queue
*************************************************************************/
void Queue::addBack(int n)
{
	if (back->nextNode->num == -1) // if there is an empty (value = -1) after the back node
	{
		back->nextNode->num = n; // change value from -1 to inputted value
		back = back->nextNode; // make the next node the new back pointer
	}
	else // queue is full, a new node needs to be made
	{
		back->nextNode = new QueueNode(n, back, front); // insert a new node after back that points to back and front
		back = back->nextNode; // make back point to the new node
	}
}

/*************************************************************************
getFront()
parameters: none
returns: int
Get the value of the front node
*************************************************************************/
int Queue::getFront()
{
	return front->num;
}

/*************************************************************************
removeFront()
parameters: none
returns: bool
Try to delete the front node. Return true if successful and return false
if unsuccessful (if the queue is already empty).
*************************************************************************/
bool Queue::removeFront()
{
	if (front->num == -1) // front is -1, so queue is empty
	{
		cout << "\nThe queue is already empty.\n";
		return false; // removal failed
	}
	else // front has a value, so remove from queue
	{
		front->num = -1; // change value to sentinal (-1)
		front = front->nextNode; // make front point to next node
		return true; // removal successful
	}
}

/*************************************************************************
removeFront()
parameters: none
returns: void
Loop through the queue and display the contents of the queue to the user.
*************************************************************************/
void Queue::displayQueue()
{	
	if (front->num == -1) // if the queue is already empty
	{
		cout << "\nThe list is empty!\n";
	}
	else // there are non-sentinel values in the queue
	{
		QueueNode* current = front; // start at front queue
		
		cout << endl << "This list contains: ";
		
		while (current != back) // loop until the current node is the back node
		{
			cout << current->num << " "; // print out current node's value
			current = current->nextNode; // change current node to next node
		}
		
		cout << back->num << endl; // print back node
	}
}