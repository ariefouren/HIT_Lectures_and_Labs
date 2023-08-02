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

	virtual string toString() const;
	
protected:
	double x;
	double y;
};