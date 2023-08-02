//
// Circle.h
// definition of class Circle 
//

#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(double x = 0, double y = 0, double r = 0);
	~Circle();
	string toString() const;
	double area() const;

private:
	double r;
};