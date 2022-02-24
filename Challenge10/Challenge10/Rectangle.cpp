#include "Rectangle.h"

Rectangle::Rectangle(string name, int width, int height) : Shape(name)
{
	cout << "Rectangle Constructor" << endl;
	this->width = width;
	this->height = height;
}

void Rectangle::draw()
{
	Shape::draw();
	cout << "Rectangle Draw" << endl;
	{
		for (int i = 1; i <= height; i++)
		{
			for (int i = 1; i < width; i++)
			{
				cout << "*";
			}
			cout << "*" << endl;
		}
	}
}