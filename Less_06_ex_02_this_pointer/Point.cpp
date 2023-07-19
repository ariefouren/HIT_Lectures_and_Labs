//
// Point.cpp
// implementation of cascaded functions calls using this pointer
//

#include <iostream>
#include "Point.h"		
using namespace std;

int Point::numPointsCreated ;	// initialize static member variable

Point::Point(double x, double y):
	x(x), y(y), pointId(++numPointsCreated)
{
}

Point::~Point()
{
}

Point& Point::setX(double x)
{
	this->x = x;	// using this pointer to resolve naming collisions
					// this->x  refers to the member variable
					// x		refers to the function's parameter

	return  *this;	// returns reference to the object to enable cascaded
					// functions calls
}

Point& Point::setY(double y)
{
	(*this).y = y;
	return  *this;	// returns reference to the object to enable cascaded
					// functions calls
}

const Point& Point::print() const	// const function should return 
									// a const reference
{
	cout << "point #" << pointId << " (" << x << ", " << y << ")";
	return  *this;	// returns reference to the object to enable cascaded
					// functions calls
}
