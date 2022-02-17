// TODO: Guard the header
#ifndef TROPHY_H
#define TROPHY_H
// TODO: include the libraries this class will need
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Color {GOLD, SILVER, BRONZE};		// TODO: create the color values

// TODO: complete the Trophy class
class Trophy 
{	
public:
	// constructors
	Trophy();
	Trophy(string name, int newLevel, Color newColor);

	// destructor
	~Trophy();

	// accessors
	string GetName() const;
	int GetLevel() const;
	Color GetColor() const;

	// mutators
	void SetName(string newName);
	void SetLevel(int newLevel);
	void SetColor(Color newColor);

	// print 
	void Print();

private:
	string name;
	int* level;
	Color* trophyColor;
};	

// TODO: end the guard
#endif