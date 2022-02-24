#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <string>
#include "Shape.h"
using namespace std;

class Triangle : public Shape
{
public:
	Triangle(string name, int height);
	void draw();

private:
	int height;
	int base;
};

#endif