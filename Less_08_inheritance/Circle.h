#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(double x = 0, double y = 0, double r = 0);
	~Circle();
	string tostring() const;
	double area() const;

private:
	double r;
};