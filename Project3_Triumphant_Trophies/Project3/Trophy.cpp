#include "Trophy.h"

Trophy :: Trophy()
{
	name = "";
	level = 1;
	color = BRONZE;
}

Trophy::Trophy(string name, int newLevel, Color newColor)
{
	this->name = name;
	this->level = newLevel;
	this->color = newColor;
}

Trophy :: ~Trophy()
{
}

string Trophy::getName() const
{
	return name;
}

int Trophy :: getLevel() const
{
	return level;
}

Color Trophy :: getColor() const
{
	return color;
}

void Trophy :: setName(string newName)
{
	name = newName;
}

void Trophy :: setLevel(int newLevel)
{
	level = newLevel;
}

void Trophy :: setColor(Color newColor)
{
	color = newColor;
}

void Trophy::print() const
{
	string colorString = "";
	switch (color)
	{
	case GOLD:
		colorString = "GOLD";
		break;
	case SILVER:
		colorString = "SILVER";
		break;
	case BRONZE:
		colorString = "BRONZE";
		break;
	}

	cout << "[ " << name << " : " << level << " : " << colorString << " ]" << endl;
}