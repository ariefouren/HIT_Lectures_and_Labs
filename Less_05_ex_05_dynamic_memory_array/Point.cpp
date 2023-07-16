//
// Point.cpp
// implementation of class Point   
//

#include <iostream>
#include "Point.h"		
using namespace std;

Point::Point(double x, double y):
	x(x), y(y)
{
	cout << "constructor for point ";
	print();
	cout << endl;
}

Point::~Point()
{
	cout << "destructor for point ";
	print();
	cout << endl;
}

void Point::setXY(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Point::print() const
{
	cout << this << " (" << x << ", " << y << ")" << endl;
}


