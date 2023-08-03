//
// Shape.h
// definition of class Shape
//
#pragma once
#include <string>
using namespace std;

class Shape
{
public:
	Shape(double x = 0, double y = 0);
	~Shape();

	string toString() const;
	double area() const { return 0; };
	
protected:
	double x;
	double y;
};