#include <iostream>
#include <string>

using namespace std;

void printLine(int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "----";
	}
	cout << "-" << endl;
}

void printBoard(char** board, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		printLine(size);
		for (size_t j = 0; j < size; j++)
		{
			// TODO: replace the 'X' with the board's (i, j) cell
			cout << "| " << board[i][j]  << " ";
		}
		cout << "|" << endl;
	}
	printLine(size);
}

int main()
{
	int size;
	do
	{
		cout << "How large should the board be?" << endl;
		cin >> size;
	} while (size < 1 || size > 20);

	// TODO: Create a board of size x size number of cells
	char** board = new char* [size];
	for (int i = 0; i < size; ++i)
	{
		board[i] = new char[size];
	}
	// TODO: Print the empty board
	printBoard(board, size);

	for (size_t i = 0; i < size; i++)
	{
		int x;
		int y;
		do
		{
			cout << "Where would you like to put a ship?" << endl;
			cin >> x >> y;

			// TODO: Update this while loop to also check that the
			// board's x, y cell is empty
		} while (x < 0 || x >= size || y < 0 || y >= size);

		// TODO: Place 'S' in the appropriate board cell

		// TODO: Print the current board
	}

	return 0;
}