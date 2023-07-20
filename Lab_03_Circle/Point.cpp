//
// Point.cpp
// implementation of class Point
//

#include <iostream>
#include <cmath>
#include "Point.h"		
using namespace std;

Point::Point(double x, double y):
	x(x), y(y)
{
	cout << "constructor for ";
	print();
	cout << endl;
}

Point::~Point()
{
	cout << "destructor for ";
	print();
	cout << endl;
}

void Point::setX(double x)
{
	this->x = x;	
}

void Point::setY(double y)
{
	this->y = y;
}

void Point::print() const	
{
	cout << "point (" << x << ", " << y << ")";
}

double Point::distance(const Point& point)
{
	return sqrt(pow((this->x - point.x), 2) +
		pow((this->y - point.y), 2));
}
