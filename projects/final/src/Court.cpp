/************************************************************************
** Program name: CS162 Final Project
** Author: David Mednikov
** Date: 03/16/17
** Description: This is the source file for the Court class. This class
** has 1 member variable and 3 functions. The member variable is a 2D array
** of pointers to Square objects. It is defined as a 3D pointer. The functions
** are a constructor, a destructor, and an accessor function for the array.
************************************************************************/

#include "Court.h" // Court header
#include "_2Ptr.h" // 2 point squares
#include "_3Ptr.h" // 3 point squares
#include "OutOfBounds.h" // out of bounds squares

/*************************************************************************
Court default constructor
This constructor creates a 2D array of Square* pointers (essentially a 3D
pointer) and initializes each element as a pointer to an object derived
from the Square* class. The court array must be built row-by-row, one
square at a time.
*************************************************************************/
Court::Court()
{
	court = new Square**[32]; // initialize court as a 2D array of pointers with 32 arrays as rows

	for (int row = 0; row < 32; ++row) // loop through each "row"
	{
		court[row] = new Square*[63]; // initialize each 2nd-D array with 64 elements (columns)
	}
	
	// The following code will build the court class, one square at a time. it is tedious to comment and read, so I've just labeled each section and will summarize how it works below.
	// Each section utlizes a for loop to step through each column. Some sections use for loops to step through each row. A Square* is created in each element to represent the 
	// spaces on a real life basketball court. Each Square is initialized as a derived object, with its row and column for keeping track of
	// location on the court and a character for printing. Using the for loops and if statements for each individual square, I initialize each Square* with 
	// its row, column, and character as arguments.

	// row 1 and 2 (every square in these rows is an out of bounds)

	for (int row = 0; row < 2; ++row) // step through rows
	{
		for (int col = 0; col < 63; ++col) // step through columns
		{
			Square* slash = new OutOfBounds(row, col, '/'); // create an OutOfBounds pointer and pass the row, column, and character
			court[row][col] = slash; // place this pointer in the array
		}
	}

	// rinse and repeat with different squares and characters

	// row 3

	for (int col = 0; col < 63; ++col)
	{
		if (col < 4 || col > 58)
		{
			Square* slash = new OutOfBounds(2, col, '/');
			court[2][col] = slash;
		}
		else
		{
			Square* star = new OutOfBounds(2, col, '*');
			court[2][col] = star;
		}
	}

	// row 4

	for (int col = 0; col < 63; ++col)
	{
		if (col < 4 || col > 58)
		{
			Square* slash = new OutOfBounds(3, col, '/');
			court[3][col] = slash;
		}
		else if (col == 4 || col == 58)
		{
			Square* star = new OutOfBounds(3, col, '*');
			court[3][col] = star;
		}
		else if (col == 12 || col == 24 || col == 38 || col == 50)
		{
			Square* line = new _2Ptr(3, col, '|');
			court[3][col] = line;
		}
		else if (col > 26 && col < 36)
		{
			Square* dash = new _2Ptr(3, col, '_');
			court[3][col] = dash;
		}
		else if (col < 12 || col > 50)
		{
			Square* space = new _3Ptr(3, col);
			court[3][col] = space;
		}
		else
		{
			Square* space = new _2Ptr(3, col, ' ');
			court[3][col] = space;
		}
	}

	// row 5

	for (int col = 0; col < 63; ++col)
	{
		if (col < 4 || col > 58)
		{
			Square* slash = new OutOfBounds(4, col, '/');
			court[4][col] = slash;
		}
		else if (col == 4 || col == 58)
		{
			Square* star = new OutOfBounds(4, col, '*');
			court[4][col] = star;
		}
		else if (col == 12 || col == 24 || col == 38 || col == 50)
		{
			Square* line = new _2Ptr(4, col, '|');
			court[4][col] = line;
		}
		else if (col == 31)
		{
			Square* basket = new _2Ptr(4, col, 'O');
			court[4][col] = basket;
		}
		else if (col < 12 || col > 50)
		{
			Square* space = new _3Ptr(4, col);
			court[4][col] = space;
		}
		else
		{
			Square* space = new _2Ptr(4, col, ' ');
			court[4][col] = space;
		}
	}

	// row 6 - 10

	for (int row = 5; row < 10; ++row)
	{
		for (int col = 0; col < 63; ++col)
		{
			if (col < 4 || col > 58)
			{
				Square* slash = new OutOfBounds(row, col, '/');
				court[row][col] = slash;
			}
			else if (col == 4 || col == 58)
			{
				Square* star = new OutOfBounds(row, col, '*');
				court[row][col] = star;
			}
			else if (col == 12 || col == 24 || col == 38 || col == 50)
			{
				Square* line = new _2Ptr(row, col, '|');
				court[row][col] = line;
			}
			else if (col < 12 || col > 50)
			{
				Square* space = new _3Ptr(row, col);
				court[row][col] = space;
			}
			else
			{
				Square* space = new _2Ptr(row, col, ' ');
				court[row][col] = space;
			}
		}
	}

	// row 11

	for (int col = 0; col < 63; ++col)
	{
		if (col < 4 || col > 58)
		{
			Square* slash = new OutOfBounds(10, col, '/');
			court[10][col] = slash;
		}
		else if (col == 4 || col == 58)
		{
			Square* star = new OutOfBounds(10, col, '*');
			court[10][col] = star;
		}
		else if (col == 12 || col == 24 || col == 38 || col == 50)
		{
			Square* line = new _2Ptr(10, col, '|');
			court[10][col] = line;
		}
		else if (col > 24 && col < 38)
		{
			Square* dash = new _2Ptr(10, col, '_');
			court[10][col] = dash;
		}
		else if (col < 12 || col > 50)
		{
			Square* space = new _3Ptr(10, col);
			court[10][col] = space;
		}
		else
		{
			Square* space = new _2Ptr(10, col, ' ');
			court[10][col] = space;
		}
	}

	// row 12-18

	int leftSlash = 13;
	int rightSlash = 49;

	for (int row = 11; row < 18; ++row)
	{
		for (int col = 0; col < 63; ++col)
		{
			if (col < 4 || col > 58)
			{
				Square* slash = new OutOfBounds(row, col, '/');
				court[row][col] = slash;
			}
			else if (col == 4 || col == 58)
			{
				Square* star = new OutOfBounds(row, col, '*');
				court[row][col] = star;
			}
			else if (col == leftSlash)
			{
				Square* left = new _2Ptr(row, col, '\\');
				court[row][col] = left;
			}
			else if (col == rightSlash)
			{
				Square* right = new _2Ptr(row, col, '/');
				court[row][col] = right;
			}
			else if (col < leftSlash || col > rightSlash)
			{
				Square* space = new _3Ptr(row, col);
				court[row][col] = space;
			}
			else
			{
				Square* space = new _2Ptr(row, col, ' ');
				court[row][col] = space;
			}
		}

		++leftSlash;
		--rightSlash;
	}

	// row 19

	for (int col = 0; col < 63; ++col)
	{
		if (col < 4 || col > 58)
		{
			Square* slash = new OutOfBounds(18, col, '/');
			court[18][col] = slash;
		}
		else if (col == 4 || col == 58)
		{
			Square* star = new OutOfBounds(18, col, '*');
			court[18][col] = star;
		}
		else if (col == 20)
		{
			Square* left = new _2Ptr(18, col, '\\');
			court[18][col] = left;
		}
		else if (col == 42)
		{
			Square* right = new _2Ptr(18, col, '/');
			court[18][col] = right;
		}
		else if (col > 20 && col < 42)
		{
			Square* dash = new _2Ptr(18, col, '_');
			court[18][col] = dash;
		}
		else if (col < 20 || col > 42)
		{
			Square* space = new _3Ptr(18, col);
			court[18][col] = space;
		}
		else
		{
			Square* space = new _2Ptr(18, col, ' ');
			court[18][col] = space;
		}
	}

	// row 20 - 29

	for (int row = 19; row < 29; ++row)
	{
		for (int col = 0; col < 63; ++col)
		{
			if (col < 4 || col > 58)
			{
				Square* slash = new OutOfBounds(row, col, '/');
				court[row][col] = slash;
			}
			else if (col == 4 || col == 58)
			{
				Square* star = new OutOfBounds(row, col, '*');
				court[row][col] = star;
			}
			else
			{
				Square* space = new _3Ptr(row, col);
				court[row][col] = space;
			}
		}
	}

	// row 30

	for (int col = 0; col < 63; ++col)
	{
		if (col < 4 || col > 58)
		{
			Square* slash = new OutOfBounds(29, col, '/');
			court[29][col] = slash;
		}
		else
		{
			Square* star = new OutOfBounds(29, col, '*');
			court[29][col] = star;
		}
	}
	
	// row 31 and 32

	for (int row = 30; row < 32; ++row)
	{
		for (int col = 0; col < 63; ++col)
		{
			Square* slash = new OutOfBounds(row, col, '/');
			court[row][col] = slash;
		}
	}

	for (int row = 0; row < 32; ++row)
	{
		for (int col = 0; col < 63; ++col)
		{
			if (row == 0)
			{
				court[row][col]->up = nullptr;
			}
			else
			{
				court[row][col]->up = court[row - 1][col];
			}
			
			if (row == 31)
			{
				court[row][col]->down = nullptr;
			}
			else
			{
				court[row][col]->down = court[row + 1][col];
			}

			if (col == 0)
			{
				court[row][col]->left = nullptr;
			}
			else
			{
				court[row][col]->left = court[row][col - 1];
			}

			if (col == 62)
			{
				court[row][col]->right = nullptr;
			}
			else
			{
				court[row][col]->right = court[row][col + 1];
			}
		}
	}
}

/*************************************************************************
Court destructor
Deallocate the court array from memory

==18300== HEAP SUMMARY:
==18300==     in use at exit: 0 bytes in 0 blocks
==18300==   total heap usage: 16,395 allocs, 16,395 frees, 994,051 bytes allocated
==18300==
==18300== All heap blocks were freed -- no leaks are possible
==18300==
==18300== For counts of detected and suppressed errors, rerun with: -v
==18300== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*************************************************************************/
Court::~Court()
{
	for (int row = 0; row < 32; ++row) // step through each row
	{
		for (int col = 0; col < 63; ++col) // step through each column
		{
			delete court[row][col]; // delete the pointer at the current spot
		}

		delete[] court[row]; // delete the row arrays of 63 columns
	}

	delete[] court; // delete the court array of 31 elements
}

/*************************************************************************
getCourt()
returns: Square***
params: none
Accessor for the Court 3D array
*************************************************************************/
Square*** Court::getCourt()
{
	return court;
}