#include "TrophyCase.h"

TrophyCase::TrophyCase()
{
	TrophyCase* trophies = new TrophyCase[10];
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

ostream& operator << (ostream& sout, const TrophyCase& trophies)
{
	for (int i = 0; i < *trophies.capacity; ++i)
	{
		sout << trophies.trophies[i] << endl;
	}
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
	TrophyCase** trophies = new TrophyCase * [10];
	for (int i = 0; i < 10; ++i)
	{
		trophies[i] = new TrophyCase();
	}
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