#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <string>
#include "Shape.h"
using namespace std;

class Rectangle : public Shape
{
public:
	Rectangle(string name, int width, int height);
	void draw();

private:
	int width;
	int height;
};


#endif 
