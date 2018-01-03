/****************************************************************************
** Program name: CS162 Lab 6
** Author: David Mednikov
** Date: 02/19/17
** Description: This program uses and manipulates linked lists. The program
** uses a menu to let the user create a linked list and manipulate it. If the
** list is empty, the user will not be able to manipulate it. The user can
** create the list by entering as many integers as they want. Once the list
** is created, the user can get the head value and the tail value, as well as 
** delete the head value and tail value. The user can also clear the list and
** start over. This program uses the getInt and showMenu utility functions for
** displaying the menu and input validation.
****************************************************************************/

#include "getInt.h" // getInt() header
#include "showMenu.h" // showMenu() header
#include <vector> // for showMenu
#include <iostream> // for input/output
#include <string>// for showMenu

using std::cout; // clean up code
using std::cin;
using std::endl;
using std::vector;
using std::string;

struct Node // Node struct definition
{
    int num; // number held by node
    Node* nextNode; // pointer to next item in linked list
    
    Node(int n, Node* node = NULL) // Node constructor that sets number and pointer to NULL
    {
        num = n;
        nextNode = node;
    }
};

int main()
{
    Node* head = NULL; // initialise head pointer to NULL
    Node* tail = NULL; // initialize tail pointer to NULL
    
    // for showMenu
    vector<string> menuChoices = { "Create Linked List", "Get Head Node Value", "Get Tail Node Value", "Delete Head Node", "Delete Tail Node", "Start Over" };
    
    while (true) // run until user wants to quit
    {
        cout << "\nLinked Lists Are Fun!\n\n"; // they sure are
        
        int choice = showMenu(menuChoices); // get user's menu choice
        
        if (choice == 1) // create list
        {
            if (head != NULL) // list already exists
            {
                cout << "\nYou have already created the list.\n"; // return to main menu
            }
            else // list does not exist
            {
                cout << "\nEnter a number: "; // ask user for integer
                int firstNum = getInt(); // validate input
                
                head = new Node(firstNum); // create new Node that head points to
                tail = head; // tail points to same Node
                
                bool another = true; // keep track of if user wants to add another
                
                while(another) // loop until user is done
                {
                    string again; // for user input
                    cout << "Do you want to enter another number? (y or n): ";
                    cin >> again; // assign input
                    
                    bool validInput = false; // for validating input
                
                    while(!validInput) // loop until valid input
                    {
                        if (again == "y" || again == "Y") // add another number
                        {
                            cout << "\nEnter a number: "; // ask user for next number
                            int nextNum = getInt(); // validate input
                            
                            Node* next = new Node(nextNum); // create new node with next number
                            tail->nextNode = next; // add Node to linked list
                            tail = next; // change tail to point to new tail
                            validInput = true; // break out of valid input loop
                        }
                        
                        else if (again == "n" || again == "N") // done adding numbers
                        {
                            another = false; // no more numbers pls
                            validInput = true; // break out of valid input loop
                        }
                        else // input was not y or n
                        {
                            cout << "You did not enter y or n. Please enter y or n: ";
                            cin.clear(); // clear input stream
                            cin >> again; // try getting input again
                        }
                    }
                }
                
                cout << "\nYour linked list is: "; // print out linked list
                cout << head->num; // print 1st element
                
                Node* temp = head->nextNode; // create temp pointer for transversing linked list
                
                while (temp != NULL) // loop until reaching end of list
                {
                    cout << " " << temp->num; // print space and current number in list
                    temp = temp->nextNode; // move to next Node in list
                }
                
                cout << endl; // skip a line
            }
        }

         else if (choice == 2) // get head value
         {
             if (head == NULL) // list is empty
             {
                 cout << "\nThe list is empty!\n";
             }
             else // list is not empty
             {
                 cout << "\nHead value: " << head->num << endl; // print head value
             }
         }
         
         else if (choice == 3) // get tail value
         {
             if (head == NULL) // list is empty
             {
                 cout << "\nThe list is empty!\n";
             }
             else // list is not empty
             {
                 cout << "\nTail value: " << tail->num << endl; // print tail value
             }
         }
         
         else if (choice == 4) // delete head of list
         {
             if (head == NULL) // list is empty
             {
                 cout << "\nThe list is empty!\n";
             }
             else // list is not empty
             {
                 Node* newHead = head->nextNode; // create pointer to new head Node, one after current head
                 delete head; // delete Node at head
                 head = newHead; // assign new head to head
                 
                 if (head == NULL) // if list is now empty
                 {
                     cout << "\nThe list is now empty.\n";
                     tail = NULL; // set tail pointer to null
                 }
                 else // print new head value
                 {
                      cout << "\nThe new head value is: " << head->num << endl;
                 }
             }
         }
         
         else if (choice == 5) // delete tail of list
         {
             if (head == NULL) // list is empty
             {
                 cout << "\nThe list is empty!\n";
             }
             else // list is not empty
             {
                 Node* tempNode = head; // create temp pointer to head Node
                 
                 if (head != tail) // if there is more than one Node
                 {
                     while (tempNode->nextNode != tail) // transverse through list until second-to-last Node
                     {
                         tempNode = tempNode->nextNode;
                     }
                     
                     tail = tempNode; // make second-to-last Node the new tail node
                     
                     delete tail->nextNode; // delete old tail node
                                      
                     cout << "\nThe new tail value is: " << tail->num << endl; // print new tail to user
                 }
                 
                 else // just one node
                 {
                     delete head; // delete Node
                     head = NULL; // set head pointer to null
                     tail = NULL; // set tail pointer to null
                     cout << "\nThe list is now empty.\n"; // tell user list is empty
                 }
             
             }  
         }
         
         else if (choice == 6) // clear list and start over
         {
             if (head == NULL) // list is already empty
             {
                 cout << "\nThe list is empty!\n";
             }
             
             else // list exists
             {
                 while (head->nextNode != NULL) // while next Node exists
                 {
                     Node* newHead = head->nextNode; // move head to next node
                     delete head; // delete Node at current head
                     head = newHead; // assign head pointer to new head
                 }
                 
                 delete head; // just one Node left, delete from history
                 head = NULL; // make head point to null when list is empty
                 tail = NULL; // make tail point to null
                 
                 cout << "\nLinked list cleared.\n"; // tell user list is cleared
             }
         }
         
         else if (choice == 7) // quit
         {
             if (head == NULL) // list is already empty, quit
             {
                 return 0;
             }
             else // Nodes need to be deleted from memory
             {
                 while (head->nextNode != NULL) // transverse while the next node exists
                 {
                     Node* newHead = head->nextNode; // create pointer to next Node (new head)
                     delete head; // delete old head
                     head = newHead; // assign head to new spot
                 }
                 
                 delete head; // delete Node when just one item left in list
                 
                /************************************************************************
                VALGRIND Report

                ==8173==
                ==8173== HEAP SUMMARY:
                ==8173==     in use at exit: 0 bytes in 0 blocks
                ==8173==   total heap usage: 86 allocs, 86 frees, 3,116 bytes allocated
                ==8173==
                ==8173== All heap blocks were freed -- no leaks are possible
                ==8173==
                ==8173== For counts of detected and suppressed errors, rerun with: -v
                ==8173== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 1 from 1)
                ************************************************************************/
                     
                 return 0; // quit 
             }
         }
                
    }
}