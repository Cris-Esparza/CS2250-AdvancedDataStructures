#include "Triangle.h"

Triangle::Triangle(string name, int height) : Shape(name)
{
	this->height = height;
	cout << "Triangle Constructor" << endl;
}

void Triangle::draw()
{
	Shape::draw();
	cout << "Triangle Draw" << endl;
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j < i; j++)
		{
			cout << "*";
		}
		cout << "*" << endl;
	}
}