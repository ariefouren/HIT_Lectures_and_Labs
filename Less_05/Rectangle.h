#pragma once
//
// Rectangle.h
// definition of class Rectangle
//
#include "Point.h"

class Rectangle
{
public:
	Rectangle(const Point& p1, const Point& p2);
	Rectangle();
	~Rectangle();

private:
	Point p1;
	Point p2;
};