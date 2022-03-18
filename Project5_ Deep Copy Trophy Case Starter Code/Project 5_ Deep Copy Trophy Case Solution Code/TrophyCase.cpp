#include "TrophyCase.h"

// Create a TrophyCase with initial capacity of 10
TrophyCase::TrophyCase()
{
	nbrOfTrophies = 0;
	capacity = 10;
	trophies = new Trophy*[capacity];
}

TrophyCase::TrophyCase(const TrophyCase & trophyCase)
{
	nbrOfTrophies = trophyCase.nbrOfTrophies;
	capacity = trophyCase.capacity;
	trophies = new Trophy*[capacity];

	// Copy over each trophy from the case
	for (int i = 0; i < nbrOfTrophies; ++i)
	{
		trophies[i] = new Trophy(*trophyCase.trophies[i]);
	}
}

TrophyCase::~TrophyCase()
{
	//for (int i = 0; i < nbrOfTrophies; ++i)
	//{
	//	delete trophies[i];
	//}
	//delete[] trophies;
}

int TrophyCase::getNbrOfTrophies() const
{
	return nbrOfTrophies;
}

int TrophyCase::getAllocatedSize() const
{
	return capacity;
}

void TrophyCase::addTrophy(const string & name, int level, Color color)
{
	// If we will exceed the size of our trophycase, expand it
	if (nbrOfTrophies == capacity)
	{
		capacity = int(capacity * 1.1);
		Trophy** newTrophies = new Trophy*[capacity];

		for (int i = 0; i < nbrOfTrophies; ++i)
		{
			newTrophies[i] = trophies[i];
		}

		delete[] trophies;
		trophies = newTrophies;
	}

	// Add the new trophy
	trophies[nbrOfTrophies++] = new Trophy(name, level, color);
	sortTrophies();
}

bool TrophyCase::copyTrophy(const string & name)
{
	// Find the trophy, if it exists
	int index = searchTrophies(name);
	if (index == -1)
		return false;

	// Copy the trophy
	addTrophy(trophies[index]->getName(), 
		trophies[index]->getLevel(), 
		trophies[index]->getColor());

	return true;
}

bool TrophyCase::deleteTrophy(const string & name)
{
	// Find the trophy, if it exists
	int index = searchTrophies(name);
	if (index == -1)
		return false;

	// Copy the trophy
	delete trophies[index];

	// Move down all the trophies after this trophy
	for (int i = index; i < nbrOfTrophies; ++i)
	{
		trophies[i] = trophies[i + 1];
	}

	// Set the last position to null
	nbrOfTrophies--;
	trophies[nbrOfTrophies] = nullptr;

	return true;
}

bool TrophyCase::renameTrophy(const string & name, const string & newName)
{
	// Find the trophy, if it exists
	int index = searchTrophies(name);
	if (index == -1)
		return false;

	trophies[index]->setName(newName);
	sortTrophies();

	return true;
}

bool TrophyCase::relevelTrophy(const string & name, int newLevel)
{
	// Find the trophy, if it exists
	int index = searchTrophies(name);
	if (index == -1)
		return false;

	trophies[index]->setLevel(newLevel);
	sortTrophies();

	return true;
}

bool TrophyCase::recolorTrophy(const string & name, Color newColor)
{
	// Find the trophy, if it exists
	int index = searchTrophies(name);
	if (index == -1)
		return false;

	trophies[index]->setColor(newColor);
	sortTrophies();

	return true;
}

TrophyCase & TrophyCase::operator=(const TrophyCase & trophyCase)
{
	if (this != &trophyCase)
	{
		// Delete the existing memory
		for (int i = 0; i < nbrOfTrophies; ++i)
		{
			delete trophies[i];
		}
		delete [] trophies;

		// Allocate space for the new trophies
		nbrOfTrophies = trophyCase.nbrOfTrophies;
		capacity = trophyCase.capacity;
		trophies = new Trophy*[capacity];

		// Copy over each trophy from the trophyCase
		for (int i = 0; i < nbrOfTrophies; ++i)
		{
			trophies[i] = new Trophy(*trophyCase.trophies[i]);
		}
	}

	return *this;
}

int TrophyCase::searchTrophies(const string & name) const
{
	// Iterate through trophies to find one with the same name
	for (int i = 0; i < nbrOfTrophies; ++i)
	{
		if (trophies[i]->getName() == name)
		{
			return i;
		}
	}

	return -1;
}

void TrophyCase::sortTrophies()
{
	// Sort the list
	for (int i = 1; i < nbrOfTrophies; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			// If the trophies are out of order, swap them
			if (*trophies[j] < *trophies[j - 1])
			{
				Trophy* temp = trophies[j - 1];
				trophies[j - 1] = trophies[j];
				trophies[j] = temp;
			}
		}
	}
}

ostream & operator<<(ostream & sout, const TrophyCase & trophyCase)
{
	for (int i = 0; i < trophyCase.nbrOfTrophies; ++i)
	{
		sout << *trophyCase.trophies[i] << endl;
	}
	return sout;
}