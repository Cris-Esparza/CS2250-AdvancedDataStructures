#ifndef TROPHYCASE_H
#define TROPHYCASE_H
#include "Trophy.h"
#include <iostream>
#include <string>
using namespace std;

class TrophyCase
{
public:
	TrophyCase();
	TrophyCase(const TrophyCase& trophyCase);
	~TrophyCase();
	TrophyCase& operator = (const TrophyCase& trophyCase);
	friend ostream& operator << (ostream& sout, const TrophyCase& trophies);
	int getNbrOfTrophies();
	int getAllocatedSize();
	bool addTrophy(string name, int level, Color color);
	bool copyTrophy(string name);
	bool deleteTrophy(string name);
	bool renameTrophy(string name, string newName);
	bool relevelTrophy(string name, int newLevel);
	bool recolorTrophy(string name, Color newColor);
	void searchTrophies(string name);
	void sortTrophies();
private:
	TrophyCase** trophies;
	int *nbrOfTrophies;
	int *capacity;
};

#endif