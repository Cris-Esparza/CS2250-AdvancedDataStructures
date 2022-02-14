// TODO: implement the Trophy class
#include "Trophy.h"

Trophy :: Trophy()
{
	
}

Trophy::Trophy(string name, int newLevel, Color newColor)
{
	this->name = name;
	level = new int(newLevel);
	trophyColor = new Color(BRONZE);
}

Trophy :: ~Trophy()
{
	delete level;
	delete trophyColor;
}

string Trophy::GetName() const
{
	return name;
}

int Trophy :: GetLevel() const
{
	return *level;
}

Color Trophy :: GetColor() const
{
	return *trophyColor;
}

void Trophy :: SetName(string newName)
{
	name = newName;
}

void Trophy :: SetLevel(int newLevel)
{
	*level = newLevel;
}

void Trophy :: SetColor(Color newColor)
{
	*trophyColor = newColor;
}

void Trophy::Print() 
{
	
}