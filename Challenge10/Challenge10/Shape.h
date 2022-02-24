#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
using namespace std;

class Shape
{
public:
	Shape(string name);
	virtual void draw();
private:
	string name;
};

#endif 
