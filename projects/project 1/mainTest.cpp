#include "Ant.h"
#include "getInt.h"
#include "printBoard.h"
#include <iostream>
#include <unistd.h>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    const int BOARD_ROWS = 25;
    const int BOARD_COLS = 50;
    
    // dynamically allocate pointer to 2D array
    int** board = new int*[BOARD_ROWS];
    
    // allocate pointers in the array to another array
    for (int i = 0; i < BOARD_ROWS; i++)
    {
        board[i] = new int[BOARD_COLS];
    }
    
    for (int row = 0; row < BOARD_ROWS; row++)
    {
        for (int col = 0; col < BOARD_COLS; col++)
        {
            board[row][col] = 0;
        }
    }
    
    Ant ant;
    int steps;
    
    cout << "Enter number of steps. I would suggest 52 or 382: ";
    steps = getInt(0);
    
    cout << "\nStart:";
    
    for (int turn = 0; turn < steps; turn++)
    {
        usleep(500000);
        int thisSquare = board[ant.getRow()][ant.getColumn()];
        board[ant.getRow()][ant.getColumn()] = 2;        
        printBoard(board, BOARD_ROWS, BOARD_COLS);
        cout << "\nStep " << turn + 1 << ":";
        ant.moveAnt(board, thisSquare);
    }
    
    board[ant.getRow()][ant.getColumn()] = 2;
    printBoard(board, BOARD_ROWS, BOARD_COLS);
    
    delete[] board;
    
    return 0;
    
}