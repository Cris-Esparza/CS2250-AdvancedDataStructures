#ifndef TROPHY_H
#define TROPHY_H

#include <iostream>
#include <string>
using namespace std;

enum class Color { BRONZE, SILVER, GOLD };

class Trophy
{
public:
	Trophy();
	Trophy(string name, int level, Color color);
	Trophy(const Trophy& trophy);
	Trophy& operator = (const Trophy& trophy);
	friend ostream& operator << (ostream& sout, const Trophy& trophy);
	bool operator < (const Trophy& trophy) const;
	bool operator > (const Trophy& trophy) const;
	bool operator == (const Trophy& trophy) const;
	bool operator != (const Trophy& trophy) const;
	bool operator <= (const Trophy& trophy) const;
	bool operator >= (const Trophy& trophy) const;
	~Trophy();
	string getName() const;
	int getLevel() const;
	Color getColor() const;
	void setName(string name);
	void setLevel(int level);
	void setColor(Color color);
	void print() const;
private:
	string* name;
	int* level;
	Color* color;
};

#endif