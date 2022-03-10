#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "BagOfHolding.h"

using namespace std;

void printWelcome();
int promptWithMenu();
int promptForInteger(string message, string error, int min, int max);
string promptForString(string message, string error);
void handleAddToTop(BagOfHolding& bag);
void handleAddToBottom(BagOfHolding& bag);
void handleRemoveFromTop(BagOfHolding& bag);
void handleRemoveFromBottom(BagOfHolding& bag);
void handleRemoveItem(BagOfHolding& bag);
void handleSearch(BagOfHolding& bag);
void handleSize(BagOfHolding& bag);
void handleListItems(BagOfHolding& bag);

int main()
{
	{
		int input;
		BagOfHolding bag;

		do
		{
			input = promptWithMenu();

			switch (input)
			{
			case 1:
				handleAddToTop(bag);
				break;
			case 2:
				handleAddToBottom(bag);
				break;
			case 3:
				handleRemoveFromTop(bag);
				break;
			case 4:
				handleRemoveFromBottom(bag);
				break;
			case 5:
				handleRemoveItem(bag);
				break;
			case 6:
				handleSearch(bag);
				break;
			case 7:
				handleSize(bag);
				break;
			case 8:
				handleListItems(bag);
				break;
			case 9:
				cout << "Thank you for the business! Goodbye!" << endl;
			}
		} while (input != 9);
	}
	
	if (BagOfHoldingItem::getNbrNodes() != 0)
	{
		cout << "ERROR: there is a memory leak and " << BagOfHoldingItem::getNbrNodes()
			<< " undeleted items." << endl;
	}
	else
	{
		cout << "Congratulations, there were no recognized memory leaks!" << endl;
	}

	cout << "Press ENTER to exit" << endl;
	cin.get();

	return 0;
}

void printWelcome()
{
	cout << "Welcome, weary traveler, to my shoppe of magical items!" << endl
		<< "I hear you are interested in a Bag of Holding. That is" << endl
		<< "an excellent choice! I'm happy to provide you with one," << endl
		<< "for a small fee. Allow me to show you how to use this" << endl
		<< "Bag of Holding. You can easily add, remove, or even" << endl
		<< "search through your Bag of Holding. This magical item" << endl
		<< "can hold as many items as you need, and you will not" << endl
		<< "feel the weight." << endl;
}

int promptWithMenu()
{
	cout << "*****************************************" << endl
		<< "Traveler, I can show you how to do the following:" << endl
		<< "1 - Add item to the top of the Bag of Holding" << endl
		<< "2 - Add item to the bottom of the Bag of Holding" << endl
		<< "3 - Remove the item at the top of the Bag of Holding" << endl
		<< "4 - Remove the item at the bottom of the Bag of Holding" << endl
		<< "5 - Remove a specific item from the Bag of Holding" << endl
		<< "6 - Search the Bag of Holding" << endl
		<< "7 - Count the number of items in the Bag of Holding" << endl
		<< "8 - List all items in the Bag of Holding" << endl
		<< "9 - Leave the shoppe" << endl
		<< "*****************************************" << endl;

	return promptForInteger("What would you like to do?",
		"I don't know what that means, please try again.", 1, 9);
}

int promptForInteger(string message, string error, int min, int max)
{
	int input;
	cout << message << endl;
	cin >> input;
	cin.ignore();

	while (input < min || max < input)
	{
		cout << error << endl;
		cout << message << endl;
		cin >> input;
		cin.ignore();
	}

	return input;
}

string promptForString(string message, string error)
{
	string input;
	cout << message << endl;
	getline(cin, input);

	while (input == "")
	{
		cout << error << endl;
		cout << message << endl;
		getline(cin, input);
	}

	return input;
}

void handleAddToTop(BagOfHolding& bag)
{
	cout << "Let me show you how to add an item to the top of your Bag of Holding." << endl;

	string item = promptForString("What item would you like to add?",
		"You need to add something. Try again.");

	bag.addTop(item);

	cout << "You've added " << item << " to the Bag of Holding." << endl;
}

void handleAddToBottom(BagOfHolding& bag)
{
	cout << "Let me show you how to add an item to the bottom of your Bag of Holding." << endl;

	string item = promptForString("What item would you like to add?",
		"You need to add something. Try again.");

	bag.addBottom(item);

	cout << "You've added " << item << " to the Bag of Holding." << endl;
}

void handleRemoveFromTop(BagOfHolding& bag)
{
	cout << "Let me show you how to remove an item from the top of your Bag of Holding." << endl;

	cout << "You've removed " << bag.removeTop() << " from the Bag of Holding." << endl;
}

void handleRemoveFromBottom(BagOfHolding& bag)
{
	cout << "Let me show you how to remove an item from the bottom of your Bag of Holding." << endl;

	cout << "You've removed " << bag.removeBottom() << " from the Bag of Holding." << endl;
}

void handleRemoveItem(BagOfHolding& bag)
{
	cout << "Let me show you how to remove an item from your Bag of Holding." << endl;

	string item = promptForString("What item would you like to remove?",
		"You need to add something. Try again.");

	if (bag.removeItem(item))
	{
		cout << "You've removed " << item << " from the Bag of Holding." << endl;
	}
	else
	{
		cout << "You could not remove " << item << " from the Bag of Holding." << endl;
	}
}

void handleSearch(BagOfHolding& bag)
{
	cout << "Let me show you how to search for an item in your Bag of Holding." << endl;

	string item = promptForString("What item would you like to find?",
		"You need to add something. Try again.");

	bool result = bag.search(item);

	if (result)
	{
		cout << "Found the " << item << endl;
	}
	else
	{
		cout << "Did not find the " << item << endl;
	}
}

void handleSize(BagOfHolding& bag)
{
	cout << "Let me show you how to count the items in your Bag of Holding." << endl;

	cout << "There are " << bag.size() << " items in your Bag of Holding" << endl;
}

void handleListItems(BagOfHolding& bag)
{
	cout << "Let me show you how to list all the items in your Bag of Holding." << endl;

	cout << "Here are the items in your Bag of Holding:" << endl;

	cout << bag;
}
