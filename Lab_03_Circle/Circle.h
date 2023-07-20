#pragma once
//
// Circle.h
// definition of class Circle
//
#include "Point.h"

class Circle
{
public:
	Circle(const Point& center, double radius);
	Circle(double radius);
	~Circle();
	void print() const;
	double area() const;
	double circumference() const;

	bool covers(const Point& point);
	bool covers(const Circle& circle);
	bool overlaps(const Circle& circle);

	static const double PI;
	
private:
	Point center;
	double radius;
};