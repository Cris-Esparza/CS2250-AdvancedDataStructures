#include "Shape.h"

Shape::Shape(string name)
{
	this->name = name;
	cout << "Shape Constructor" << endl;
}

void Shape::draw()
{
	cout << "Shape Draw" << endl;
	cout << "Name: " << name << endl;
}