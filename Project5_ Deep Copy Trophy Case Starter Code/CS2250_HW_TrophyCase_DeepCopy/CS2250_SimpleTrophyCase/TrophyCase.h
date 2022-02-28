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
	int getNbrOfTrophies();
	int getAllocatedSize();
	void addTrophy(string name, int level, Color color);
	void copyTrophy(string name);
	void deleteTrophy(string name);
	void renameTrophy(string name, string newName);
	void relevelTrophy(string name, int newLevel);
	void recolorTrophy(string name, Color newColor);
	void searchTrophies(string name);
	void sortTrophies();
private:
	TrophyCase** trophies;
	int *nbrOfTrophies;
	int *capacity;
};

#endif