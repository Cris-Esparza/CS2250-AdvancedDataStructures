#ifndef TROPHY_H
#define TROPHY_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum class Color { BRONZE, SILVER, GOLD };

const int TROPHY_NAME_MAX_LENGTH = 30;

class Trophy
{
public:
	Trophy();
	Trophy(const string& name, int level, Color color);
	Trophy(const Trophy& trophy);
	~Trophy();
	string getName() const;
	int getLevel() const;
	Color getColor() const;
	void setName(const string& name);
	void setLevel(int level);
	void setColor(Color color);

	bool operator<(const Trophy& other) const;
	bool operator>(const Trophy& other) const;
	bool operator==(const Trophy& other) const;
	bool operator!=(const Trophy& other) const;
	bool operator<=(const Trophy& other) const;
	bool operator>=(const Trophy& other) const;

	Trophy& operator=(const Trophy& other);
	friend ostream& operator<<(ostream& sout, const Trophy& trophy);
private:
	int compare(const Trophy& other) const;
	string* name;
	int* level;
	Color* color;
};

#endif