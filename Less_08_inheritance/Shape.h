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

	string tostring() const;
	double area() const;

	double getX() const;
	double getY() const;
	
private:
	double x;
	double y;
};