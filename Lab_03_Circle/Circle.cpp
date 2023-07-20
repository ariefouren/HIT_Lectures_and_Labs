//
// Circle.cpp
// implementation of class Point
//

#include <iostream>
#include <cmath>
#include "Point.h"		
#include "Circle.h";

using namespace std;

const double Circle::PI = 3.14; // initialize static const 

Circle::Circle(const Point& center, double radius):
	center(center), radius(radius)
{
	cout << "constructor for ";
	print();
	cout << endl;
}

Circle::Circle(double radius):
	center(Point(0,0)), radius(radius)
{
	cout << "constructor for ";
	print();
	cout << endl;
}

Circle::~Circle()
{
	cout << "destructor for ";
	print();
	cout << endl;
}

void Circle::print() const
{
	cout << " circle: center = ";
	center.print();
	cout << " radius = " << radius;
}

double Circle::area() const
{
	return PI * pow(radius, 2);
}

double Circle::circumference() const
{
	return 2 * PI * radius;
}

bool Circle::covers(const Point& point)
{
	return(this->center.distance(point) <= radius);
}

bool Circle::covers(const Circle& circle2)
{
	return(this->center.distance(circle2.center) + circle2.radius <= 
		this->radius);
}
bool Circle::overlaps(const Circle& circle2)
{
	return(this->center.distance(circle2.center) <= 
			this->radius + circle2.radius);
}