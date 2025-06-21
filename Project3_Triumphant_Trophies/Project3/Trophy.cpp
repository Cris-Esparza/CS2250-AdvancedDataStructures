// TODO: implement the Trophy class
#include "Trophy.h"

Trophy :: Trophy()
{
	
}

Trophy::Trophy(string name, int newLevel, Color newColor)
{
	this->name = name;
	level = new int(newLevel);
	trophyColor = new Color(Color :: BRONZE);
}

Trophy :: ~Trophy()
{
	delete level;
	delete trophyColor;
}

string Trophy::getName() const
{
	return name;
}

int Trophy :: getLevel() const
{
	return *level;
}

Color Trophy :: getColor() const
{
	return *trophyColor;
}

void Trophy :: setName(string newName)
{
	name = newName;
}

void Trophy :: setLevel(int newLevel)
{
	*level = newLevel;
}

void Trophy :: setColor(Color newColor)
{
	*trophyColor = newColor;
}

void Trophy::print() 
{
	cout << "[ " << getName() << " : " << getLevel() << " : " << getColor() << " ]" << endl;
}