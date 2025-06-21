#ifndef TROPHY_H
#define TROPHY_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Color {GOLD, SILVER, BRONZE, COPPER};		

class Trophy 
{	
public:
	// constructors
	Trophy();
	Trophy(string name, int newLevel, Color newColor);

	// destructor
	~Trophy();

	// accessors
	string getName() const;
	int getLevel() const;
	Color getColor() const;

	// mutators
	void setName(string newName);
	void setLevel(int newLevel);
	void setColor(Color newColor);

	// print 
	void print() const;

private:
	string name;
	int level;
	Color color;
};	

#endif