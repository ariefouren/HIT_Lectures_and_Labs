//
// Point.cpp
// implementation of class Point   
//

#include <iostream>
#include "Point.h"		
using namespace std;

int Point::numPointsCreated ;	// initialize static member variable

Point::Point(double x, double y):
	x(x), y(y), pointId(++numPointsCreated)
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

void Point::setXY(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Point::print() const
{
	cout << "point #" << pointId << " (" << x << ", " << y << ")";
}
