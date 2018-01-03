/************************************************************************
** Program name: CS162 Project 1
** Author: David Mednikov
** Date: 01/17/17
** Description: This program simulates Langston's Ant. It has a menu that
** lets the user decide if they want to enter the ant's location, pick one
** randomly, or quit. The program asks the user for the number of rows and
** columns, then asks for the ant's location or picks one randomly. The
** program then shows the ant on the board and asks the user for the number of
** steps. The program shows each step of the simulation and then quits.
************************************************************************/

#include "Ant.h" // include Ant header
#include "getInt.h" // include getInt() header
#include "printBoard.h" // include printBoard() header
#include "showMenu.h" // include showMenu() header
#include <stdlib.h> // rand() and srand()
#include <time.h> // time()
#include <iostream> // user input and output
#include <unistd.h> // pause(sleep) for each turn

using std::cin; // clean up code
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    //const int BOARD_ROWS = 25;       Used for testing
    //const int BOARD_COLS = 50;
    
    // initialize integer variables
    int rows, columns, steps, antRow, antColumn;
    
    cout << "Welcome to Langston's Ant!\n\n";
    
    // create vector containing menu options
    vector<string> menuList;
    menuList.push_back("Pick a starting location"); // add options to vector
    menuList.push_back("Random starting location");
    
    // print out menu and get user's choice
    int choice = showMenu(menuList);
    
    // quit if user's choice is 3
    if (choice == 3)
    {
        return 0;
    }
    
    // Ask user for number of rows, between 1 and 50
    cout << "How many rows (from 1-50): ";
    rows = getInt(1, 50);
    // Ask user for number of columns, between 1 and 100
    cout << "How many columns (from 1-100): ";
    columns = getInt(1, 100);
    
    // dynamically allocate pointer to 2D array
    int** board = new int*[rows];
    
    // allocate pointers in the array to another array
    for (int i = 0; i < rows; i++)
    {
        board[i] = new int[columns];
    }
    
    // fill each element of the 2D array with a 0, representing a white square
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            board[row][col] = 0;
        }
    }
    
    // if user selected to enter the ant's starting location, get from user
    if (choice == 1)
    {
        cout << "Which row: ";
        antRow = getInt(1, rows) - 1;
        cout << "Which column: ";
        antColumn = getInt(1, columns) - 1;
    }
    // user selected random starting location
    else
    {
        srand(time(NULL)); // seed CPU time
        antRow = rand() % rows; // generate random row number
        cout << "Row " << antRow + 1 << ", "; // print out row to user
        antColumn = rand() % columns; // generate random column number
        cout << "Column " << antColumn + 1 << endl; // print column to user
    }
    
    // initialize Ant object at starting location
    Ant ant(antRow, antColumn);
    
    int rememberColor = board[antRow][antColumn]; // get color of ant's square
    board[antRow][antColumn] = 2; // change square's "color" to 2, meaning ant
    
    // print out board
    cout << "Here's your board:\n";
    printBoard(board, rows, columns, ant.getDirection());
    
    // change ant's square back to actual color
    board[antRow][antColumn] = rememberColor;
    
    // ask user for number of steps, user getInt() to validate input
    cout << "How many steps? I would suggest 52 or 382: ";
    steps = getInt(0);
    
    if (steps == 0)
    {
        cout << "The ant is sad. :'(";
        cout << endl;
    }
    else
    {
        
        cout << "\nStart:";
    
        // loop through once for each step
        for (int turn = 0; turn < steps; turn++)
        {
            usleep(500000); // 0.5 seconds pause
            int thisSquare = board[ant.getRow()][ant.getColumn()]; // get color of ant's square
            cout << "\nStep " << turn + 1 << ":"; // print out step number
            ant.moveAnt(board, thisSquare, rows, columns); // move ant
            int antColor = board[ant.getRow()][ant.getColumn()]; // get color of ant's new square
            board[ant.getRow()][ant.getColumn()] = 2; // change square's "color" to ant
            printBoard(board, rows, columns, ant.getDirection()); // print board
            board[ant.getRow()][ant.getColumn()] = antColor; // change ant's square back to actual color
        }
    }
    
    
/*************************************************************************
Clear allocated memory.

valgrind report:

==10489== HEAP SUMMARY:
==10489==     in use at exit: 0 bytes in 0 blocks
==10489==   total heap usage: 31 allocs, 31 frees, 10,338 bytes allocated
==10489==
==10489== All heap blocks were freed -- no leaks are possible
==10489==
==10489== For counts of detected and suppressed errors, rerun with: -v
==10489== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 1 from 1)

*************************************************************************/
    
    // loop through array, deleting array allocated at each element
    for (int row = 0; row < rows; row++)
    {
        delete[] board[row];
    }
    
    // delete the array
    delete[] board;
    
    //quit
    return 0;
    
}