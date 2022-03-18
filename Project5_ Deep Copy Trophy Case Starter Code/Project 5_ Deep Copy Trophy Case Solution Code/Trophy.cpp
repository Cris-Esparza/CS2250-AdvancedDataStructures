#include "Trophy.h"

Trophy::Trophy()
{
	name = new string("");
	level = new int(1);
	color = new Color(Color::BRONZE);
}

Trophy::Trophy(const string& name, int level, Color color)
{
	this->name = new string(name);
	this->level = new int(level);
	this->color = new Color(color);
}

Trophy::Trophy(const Trophy & trophy)
{
	this->name = new string(*trophy.name);
	this->level = new int(*trophy.level);
	this->color = new Color(*trophy.color);
}

Trophy::~Trophy()
{
	//delete name;
	//name = NULL;
	//delete level;
	//level = NULL;
	//delete color;
	//color = NULL;
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

void Trophy::setName(const string& newName)
{
	*this->name = newName;
}

void Trophy::setLevel(int newLevel)
{
	*this->level = newLevel;
}

void Trophy::setColor(Color newColor)
{
	*this->color = newColor;
}

bool Trophy::operator<(const Trophy & other) const
{
	return compare(other) < 0;
}

bool Trophy::operator>(const Trophy & other) const
{
	return compare(other) > 0;
}

bool Trophy::operator==(const Trophy & other) const
{
	return compare(other) == 0;
}

bool Trophy::operator!=(const Trophy & other) const
{
	return compare(other) != 0;
}

bool Trophy::operator<=(const Trophy & other) const
{
	return compare(other) <= 0;
}

bool Trophy::operator>=(const Trophy & other) const
{
	return compare(other) >= 0;
}

Trophy & Trophy::operator=(const Trophy & other)
{
	*name = *other.name;
	*level = *other.level;
	*color = *other.color;
	return *this;
}

int Trophy::compare(const Trophy & other) const
{
	if (*level < *other.level)
	{
		return -1;
	}
	else if (*level > *other.level)
	{
		return 1;
	}
	else // if (*level == *other.level)
	{
		if (*color < *other.color)
		{
			return -1;
		}
		else if(*color > *other.color)
		{
			return 1;
		}
		else // if (*level == *other.level)
		{
			return name->compare(*other.name);
		}
	}
}

ostream & operator<<(ostream & sout, const Trophy & trophy)
{
	string* colorString = new string("");
	switch (*trophy.color)
	{
	case Color::GOLD:
		*colorString = "GOLD";
		break;
	case Color::SILVER:
		*colorString = "SILVER";
		break;
	case Color::BRONZE:
		*colorString = "BRONZE";
		break;
	}

	sout << "[ " << left << setw(TROPHY_NAME_MAX_LENGTH) << *trophy.name 
		<< " : " << right << setw(2) << *trophy.level 
		<< " : " << left << setw(6) << *colorString << " ]";
	delete colorString;
	return sout;
}
