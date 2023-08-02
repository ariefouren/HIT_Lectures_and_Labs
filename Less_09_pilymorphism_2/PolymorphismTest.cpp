//
// PolymorphismTest.cpp
// Testing classes Shape and Circle
//   

#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

string toString(const Shape& s);
int main()
{
	int numOfShapes = 3;
	Shape* *shapesArr = new Shape*[numOfShapes]; // array of pointers to Shape
	shapesArr[0] = new Shape(0, 0);
	shapesArr[1] = new Circle(1, 1, 1);
	shapesArr[2] = new Rectangle(2, 2, 2, 2);

	for (int i = 0; i < numOfShapes; i++)
	{
		cout << "shapesArr[" << i << "]->toString() = " << shapesArr[i]->toString() << endl;
		cout << "toString(*shapesArr[" << i <<"]) = " << toString(*shapesArr[i]) << endl;
	}

}

string toString(const Shape& s)
{
	return s.toString();
}
