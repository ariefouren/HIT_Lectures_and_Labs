//
// Rectangle.h
// definition of class Rectangle
//

#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(double x = 0, double y = 0, double length = 0, double height = 0);
	~Rectangle();
	string toString() const;
	double area() const;

private:
	double length = 0;
	double height = 0;
};