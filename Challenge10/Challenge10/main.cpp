#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

int main()
{
    Shape* shape0 = new Shape("Shape 0");
    Rectangle* rectangle1 = new Rectangle("Rectangle 1", 5 ,3);
    Triangle* triangle2 = new Triangle("Triangle 2", 5);
    shape0->draw();
    rectangle1->draw();
    triangle2->draw();

    Shape** shapes = new Shape*[5];
    shapes[0] = shape0;
    shapes[1] = rectangle1;
    shapes[2] = triangle2;
    shapes[3] = new Triangle("Triangle 3", 11);
    shapes[4] = new Rectangle("Rectangle 4", 8, 13);

    for (int i = 0; i < 5; ++i)
    {
        shapes[i]->draw();
    }

    for (int i = 0; i < 5; ++i)
    {
        delete shapes[i];
    }

    delete [] shapes;

    return 0;
}


