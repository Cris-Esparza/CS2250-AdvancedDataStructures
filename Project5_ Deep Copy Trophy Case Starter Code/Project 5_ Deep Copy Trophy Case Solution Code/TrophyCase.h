#ifndef TROPHY_CASE
#define TROPHY_CASE

#include <iostream>
#include <string>

#include "Trophy.h"

using namespace std;

class TrophyCase
{
public:
	TrophyCase();
	TrophyCase(const TrophyCase& trophyCase);
	~TrophyCase();

	int getNbrOfTrophies() const;
	int getAllocatedSize() const;

	void addTrophy(const string& name, int level, Color color);
	bool copyTrophy(const string& name);
	bool deleteTrophy(const string& name);
	bool renameTrophy(const string& name, const string& newName);
	bool relevelTrophy(const string& name, int newLevel);
	bool recolorTrophy(const string& name, Color newColor);

	TrophyCase& operator=(const TrophyCase& trophyCase);

	friend ostream& operator<<(ostream& sout, const TrophyCase& trophyCase);

private:
	int searchTrophies(const string& name) const;
	void sortTrophies();

	Trophy** trophies;		// Collection of pointers to trophies
	int nbrOfTrophies;		// Number of trophies in the collection
	int capacity;			// Size of array storing trophies
};

#endif