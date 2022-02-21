#include <iostream>
#include <string>
#include <vector>
#include "Trophy.h"
using namespace std;

// Reusable strings
const string PROMPT_FOR_NAME = "Please enter the name of the Trophy";
const string PROMPT_FOR_LEVEL = "Please enter the level of your Trophy (between 1 and 10)";
const string PROMPT_FOR_COLOR = "Please enter the color of your Trophy (GOLD, SILVER, or BRONZE)";

char printMenu();

// Menu choice handlers
void addTrophy(vector<Trophy*>& trophies);
void copyTrophy(vector<Trophy*>& trophies);
void deleteTrophy(vector<Trophy*>& trophies);
void renameTrophy(vector<Trophy*>& trophies);
void relevelTrophy(vector<Trophy*>& trophies);
void recolorTrophy(vector<Trophy*>& trophies);
void printTrophies(vector<Trophy*>& trophies);

// Input handlers
Trophy promptForTrophy();
string promptForString(const string& message);
int promptForInt(const string& message, int minimum, int maximum);
Color promptForColor(const string& message);

// Useful helper methods
string stringToUpper(string value);
int searchForTrophy(vector<Trophy*>& trophies, const string& name);

// This application allows for the management of a trophy collection
int main()
{
	vector<Trophy*> trophies;

	cout << "***********************************************" << endl
		<< "Welcome to the Trophy editor!" << endl
		<< "With this application, you can manage your trophy" << endl
		<< "collection - add, modify, or remove trophies by" << endl
		<< "using this simple menu!" << endl
		<< "***********************************************" << endl;

	// Loop the menu, allowing the user to select an action each time
	int input;
	do
	{
		input = printMenu();
		switch (input)
		{
		case 1:		// Add a new Trophy
			addTrophy(trophies);
			break;
		case 2:		// Copy an existing Trophy
			copyTrophy(trophies);
			break;
		case 3:		// Delete an existing Trophy
			deleteTrophy(trophies);
			break;
		case 4:		// Rename a Trophy
			renameTrophy(trophies);
			break;
		case 5:		// Change the level of a Trophy
			relevelTrophy(trophies);
			break;
		//case 6:		// Change the color of a Trophy
		//	recolorTrophy(trophies);
		//	break;
		case 7:		// print all Trophies
			printTrophies(trophies);
			break;
		case 8:		// Exit
			cout << "You have chosen to exit the application, good-bye!" << endl;
			break;
		default:
			cout << "That is not a recognized menu selection, choose again." << endl;
			break;
		}

	} while (input != 8);

	return 0;
}

// print the menu to the user and accept their menu choice
char printMenu()
{
	string input;
	cout << "-----------------------------------------" << endl
		<< "Please select an option :" << endl
		<< "1 - Add a new Trophy" << endl
		<< "2 - Copy a Trophy" << endl
		<< "3 - Delete a Trophy" << endl
		<< "4 - Rename a Trophy" << endl
		<< "5 - Change the level of a Trophy" << endl
		<< "6 - Change the color of a Trophy" << endl
		<< "7 - Print All the Trophies" << endl
		<< "8 - Exit the program" << endl
		<< "-----------------------------------------" << endl;
	getline(cin, input);
	return stoi(input);
}

// Add a new Trophy to the collection
void addTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to add a trophy." << endl;
	trophies.push_back(new Trophy(promptForTrophy()));
}

// Delete an existing Trophy from the collection
void deleteTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to delete an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	int index = searchForTrophy(trophies, name);
	if (index >= 0)
	{
		trophies.erase(trophies.begin() + index);
	}
}

// Copy an existing Trophy in the collection
void copyTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to copy an existing trophy." << endl;

	string name = promptForString(PROMPT_FOR_NAME);
	int index = searchForTrophy(trophies, name);
	if (index >= 0)
	{
		trophies.push_back(new Trophy(*trophies[index]));
	}
}

// Rename an existing Trophy (change the name)
void renameTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to rename an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	int index = searchForTrophy(trophies, name);
	if (index >= 0)
	{
		trophies[index]->setName(promptForString("Please enter the new name of the Trophy"));
	}
}

// Relevel an existing Trophy (change the level)
void relevelTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to change the level of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	int index = searchForTrophy(trophies, name);
	if (index >= 0)
	{
		trophies[index]->setLevel(promptForInt(PROMPT_FOR_LEVEL, 1, 10));
	}
}

//// Recolor an existing Trophy (change the color)
//void recolorTrophy(vector<Trophy*>& trophies)
//{
//	cout << "You have chosen to change the color of an existing trophy." << endl;
//	string name = promptForString(PROMPT_FOR_NAME);
//	int index = searchForTrophy(trophies, name);
//	if (index >= 0)
//	{
//		trophies[index].setColor(promptForColor(PROMPT_FOR_COLOR));
//	}
//}

// print all of the Trophies in the collection
void printTrophies(vector<Trophy*>& trophies)
{
	cout << "You have chosen to print all of the trophies." << endl;
	for (int i = 0; i < trophies.size(); ++i)
	{
		trophies[i]->print();
	}
}

// Ask the user for a Trophy, validate their responses
// Return the Trophy
Trophy promptForTrophy()
{
	string name = promptForString(PROMPT_FOR_NAME);
	int level = promptForInt(PROMPT_FOR_LEVEL, 1, 10);
	Color color = promptForColor(PROMPT_FOR_COLOR);

	Trophy *trophy = new Trophy(name, level, color);
	
	return *trophy;
}

// Ask the user for a string, validate their response
// Return the string
string promptForString(const string& message)
{
	string value = "";
	cout << message << endl;
	getline(cin, value);
	while (value == "")
	{
		cout << "That is not a valid name.  Try again.";
		getline(cin, value);
	}
	return value;
}

// Ask the user for an int, validate their response by
// checking that it is between minimum and maximum values
// Return the int
int promptForInt(const string& message, int minimum, int maximum)
{
	string value;
	cout << message << endl;
	getline(cin, value);
	stoi(value);
	while (stoi(value) < minimum || stoi(value) > maximum)
	{
		cout << "That value is outside the acceptable range.  Try again." << endl;
		getline(cin, value);
		stoi(value);
	}
	
	return stoi(value);
}

// Convert a string to all uppercase (so that we can compare the
// user's entered color to the official color)
string stringToUpper(string value)
{
	for (int i = 0; i < value.length(); ++i)
	{
		value[i] = toupper(value[i]);
	}
	return value;
}

// Ask the user for a color, validate the response
// Return the color
Color promptForColor(const string& message)
{
	Color color;
	string value;
	bool goodColor = false;
	cout << message << endl;

	while (goodColor == false)
	{
		getline(cin, value);
		string upperValue = stringToUpper(value);

		if (upperValue == "GOLD")
		{
			color = GOLD;
			goodColor = true;
		}
		else if (upperValue == "SILVER")
		{
			color = SILVER;
			goodColor = true;
		}
		else if (upperValue == "BRONZE")
		{
			color = BRONZE;
			goodColor = true;
		}
		else
		{
			cout << "That is not an acceptable color.  Try again." << endl;
		}
	}
	
	return color;
}

// Search for a trophy in the collection by name
int searchForTrophy(vector<Trophy*>& trophies, const string& name)
{
	for (int i = 0; i < trophies.size(); ++i)
	{
		if (name == trophies[i]->getName())
		{
			return i;
		}
	}
	cout << "ERROR: The Trophy was not found" << endl;
	return -1;
}