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
	cout << "constructor for point " << this <<" ";
	print();
	cout << endl;
}

Point::~Point()
{
	cout << "destructor for point " << this << " ";
	print();
	cout << endl;
}

void Point::print() const
{
	cout << "(" << x << ", " << y << ")";
}


