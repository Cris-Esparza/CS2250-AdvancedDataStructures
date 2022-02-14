#include <iostream>
#include <stdlib.h>
using namespace std;

/// <summary>
/// Prints main menu text
/// </summary>
/// <returns></returns>
void mainMenu()
{
	cout << "********************************************************************************" << endl;
	cout << "* Please select a menu option(1 - 6) :" << endl;
	cout << "* 1 - Square" << endl;
	cout << "* 2 - Right Triangle" << endl;
	cout << "* 3 - Isosceles Triangle" << endl;
	cout << "* 4 - Hourglass" << endl;
	cout << "* 5 - Diamond" << endl;
	cout << "* 6 - Quit(exit the application)" << endl;
	cout << "********************************************************************************" << endl;
	cout << "Please select a menu option(1-6)" << endl;
}

/// <summary>
/// Draws a square
/// </summary>
/// <param name="size"></param>
void Square(int size)
{
	for (int i = 1; i <= size; i++)
	{
		for (int i = 1; i < size; i++)
		{
			cout << "*";
		}
		cout << "*" << endl;
	}
}

/// <summary>
/// Draws a right triangle
/// </summary>
/// <param name="size"></param>
void RightTriangle(int size)
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j < i; j++)
		{
			cout << "*";
		}
		cout << "*" << endl;
	}
}

/// <summary>
/// Draws an isosceles triangle
/// </summary>
void IsoscelesTriangle(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < 1 + (2 * i); k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

/// <summary>
/// Draws a hourglass shape
/// </summary>
void Hourglass(int size)
{
	for (int i = size - 1; i > 0; i--)
		{
			for (int j = 0; j < size - i; j++)
			{
				cout << " ";
			}
			for (int k = 0; k < 1 + (2 * i); k++)
			{
				cout << "*";
			}
			cout << endl;
		}
	for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - i; j++)
			{
				cout << " ";
			}
			for (int k = 0; k < 1 + (2 * i); k++)
			{
				cout << "*";
			}
			cout << endl;
		}
}

/// <summary>
/// Draws a diamond shape
/// </summary>
void Diamond(int size)
{
	int space = size - 1;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= space; j++)
		{
			cout << " ";
		}
		space--;
		for (int j = 1; j <= (2 * i - 1); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	space = 1;
	for (int i = 1; i <= (size - 1); i++)
	{
		for (int j = 1; j <= space; j++)
		{
			cout << " ";
		}
		space++;
		for (int j = 1; j <= (2 * (size - i) - 1); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

/// <summary>
/// Exits the application
/// </summary>
void Quit()
{
	cout << "Thank you for using our application!  Good-bye!" << endl;
}

void InvalidEntry()
{
	cout << "You have not selected a valid menu option, " <<
		"please try again." << endl;
	cout << "Please select a menu option(1-6)" << endl;
}

void InvalidSize()
{
	cout << "You have not selected an appropriate size, please try again." << endl;
}

/// <summary>
/// Main funtion of the cpp file
/// </summary>
/// <returns></returns>
int main()
{
	int size;
	int menuOpt;
	cout << "Welcome to the shape renderer!" << endl;
	cout << "You can draw a few different shapes at a variety of sizes!" << endl;
	mainMenu();
	do {
		cin >> menuOpt;
		switch (menuOpt)
		{
		case 1:
			do 
			{
				cout << "You have selected a square!  What size should your square be (1-20)?" << endl;
				cin >> size;
				if (size > 0 && size < 21)
				{
					Square(size);
				}
				else
				{
					InvalidSize();
				}
			} while (size < 1 || size > 20);
			break;
		case 2:
			do {
				cout << "You have selected a right triangle!  What size should your right triangle be (1-20)?" << endl;
				cin >> size;
				if (size > 0 && size < 21)
				{
					RightTriangle(size);
				}
				else
				{
					InvalidSize();
				}
			} while (size < 1 || size > 20);
			break;
		case 3:
			do {
				cout << "You have selected a isosceles triangle!  What size should your isosceles triangle be (1-20)?" << endl;
				cin >> size;
				if (size > 0 && size < 21)
				{
					IsoscelesTriangle(size);
				}
				else
				{
					InvalidSize();
				}
			} while (size < 1 || size > 20);
			break;
		case 4:
			do {
				cout << "You have selected an hourglass!  What size should your hourglass be (1-20)?" << endl;
				cin >> size;
				if (size > 0 && size < 21)
				{
					Hourglass(size);
				}
				else
				{
					InvalidSize();
				}
			} while (size < 1 || size > 20);
			break;
		case 5:
			do {
				cout << "You have selected an diamond!  What size should your diamond be (1-20)?" << endl;
				cin >> size;
				if (size > 0 && size < 21)
				{
					Diamond(size);
				}
				else
				{
					InvalidSize();
				}
			} while (size < 1 || size > 20);
			break;
		case 6:
			Quit();
			return 1;
			break;
		default:
			if (menuOpt < 1 || menuOpt > 6)
			{
				InvalidEntry();
			}
		}
		if (menuOpt != 6 && menuOpt > 0 && menuOpt < 7)
		{
			mainMenu();
		}
	} while (menuOpt > 0 || menuOpt < 6);
	
	return 0;
}