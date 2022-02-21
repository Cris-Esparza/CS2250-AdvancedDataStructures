#include "Trophy.h"

Trophy::Trophy()
{
	name = "";
	level = 1;
	color = BRONZE;
}

Trophy::Trophy(string name, int level, Color color)
{
	this->name = name;
	this->level = level;
	this->color = color;
}

Trophy::~Trophy()
{
}

string Trophy::getName() const
{
	return name;
}

int Trophy::getLevel() const
{
	return level;
}

Color Trophy::getColor() const
{
	return color;
}

void Trophy::setName(string name)
{
	this->name = name;
}

void Trophy::setLevel(int level)
{
	this->level = level;
}

void Trophy::setColor(Color color)
{
	this->color = color;
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