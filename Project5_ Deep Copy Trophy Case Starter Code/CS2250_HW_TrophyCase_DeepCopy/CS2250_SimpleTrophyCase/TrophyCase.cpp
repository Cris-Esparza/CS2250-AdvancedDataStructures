#include "TrophyCase.h"

TrophyCase::TrophyCase()
{
	TrophyCase* trophies = new TrophyCase[];
	nbrOfTrophies = new int(1);
	capacity = new int(10);
}

TrophyCase::TrophyCase(const TrophyCase& trophyCase)
{
	trophies = new TrophyCase(*trophyCase.trophies);
	nbrOfTrophies = new int(*trophyCase.nbrOfTrophies);
	capacity = new int(*trophyCase.capacity);
}

TrophyCase :: ~TrophyCase()
{
	delete trophies;
	delete nbrOfTrophies;
	delete capacity;
}

TrophyCase& TrophyCase :: operator = (const TrophyCase& trophyCase)
{
	*trophies = *trophyCase.trophies;
	*nbrOfTrophies = *trophyCase.nbrOfTrophies;
	*capacity = *trophyCase.capacity;
}

int TrophyCase :: getNbrOfTrophies()
{
	return *nbrOfTrophies;
}

int TrophyCase::getAllocatedSize()
{
	return *capacity;
}

void TrophyCase::addTrophy(string name, int level, Color color)
{

}

void TrophyCase::copyTrophy(string name)
{

}

void TrophyCase::deleteTrophy(string name)
{

}

void TrophyCase::renameTrophy(string name, string newName)
{

}

void TrophyCase::relevelTrophy(string name, int newLevel)
{

}

void TrophyCase::recolorTrophy(string name, Color newColor)
{

}

void TrophyCase::searchTrophies(string name)
{

}

void TrophyCase::sortTrophies()
{

}