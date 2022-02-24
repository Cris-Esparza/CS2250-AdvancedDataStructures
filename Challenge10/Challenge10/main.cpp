#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
using namespace std;

int main()
{
    Shape* shape0 = new Shape("Shape0");
    Rectangle* rectangle1 = new Rectangle("Rectangle 1", 5 ,3);
    shape0->draw();
    rectangle1->draw();


    return 0;
}


