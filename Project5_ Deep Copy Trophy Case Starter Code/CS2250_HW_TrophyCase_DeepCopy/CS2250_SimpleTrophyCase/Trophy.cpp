#include "Trophy.h"

Trophy::Trophy()
{
	name = new string("");
	level =  new int(0);
	color = new Color(Color :: BRONZE);
}

Trophy::Trophy(string name, int level, Color color)
{
	this->name = new string(name);
	this->level = new int(level);
	this->color = new Color(color);
}

Trophy::Trophy(const Trophy& trophy)
{
	name = new string(*trophy.name);
	level = new int(*trophy.level);
	color = new Color(*trophy.color);
}

Trophy& Trophy :: operator = (const Trophy& trophy)
{
	*name = *trophy.name;
	*level = *trophy.level;
	*color = *trophy.color;
	return *this;
}

Trophy& Trophy :: operator << (const Trophy& trophy)
{
	cout << &trophy << endl;
}

Trophy& Trophy :: operator < (const Trophy& trophy)
{

}

Trophy& Trophy :: operator > (const Trophy& trophy)
{

}

Trophy& Trophy :: operator == (const Trophy& trophy)
{

}

Trophy& Trophy :: operator != (const Trophy& trophy)
{

}

Trophy& Trophy :: operator <= (const Trophy& trophy)
{

}

Trophy& Trophy :: operator >= (const Trophy& trophy)
{

}

Trophy::~Trophy()
{
	delete name;
	delete level;
	delete color;
}

string Trophy::getName() const
{
	return *name;
}

int Trophy::getLevel() const
{
	return *level;
}

Color Trophy::getColor() const
{
	return *color;
}

void Trophy::setName(string name)
{
	delete this->name;
	this->name = new string(name);
}

void Trophy::setLevel(int level)
{
	delete this->level;
	this->level = new int(level);
}

void Trophy::setColor(Color color)
{
	delete this->color;
	this->color = new Color(color);
}

void Trophy::print() const
{
	string colorString = "";
	switch (*color)
	{
	case Color :: GOLD:
		colorString = "GOLD";
		break;
	case Color :: SILVER:
		colorString = "SILVER";
		break;
	case Color :: BRONZE:
		colorString = "BRONZE";
		break;
	}

	cout << "[ " << *name << " : " << *level << " : " << colorString << " ]" << endl;
}