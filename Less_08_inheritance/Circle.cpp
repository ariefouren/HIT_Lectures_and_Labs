#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

Circle::Circle(double x, double y, double r):
	Shape(x, y), 
	r(r)
{
	cout << "constructor for " << this->tostring() <<endl;
}

Circle::~Circle()
{
	cout << "destructor for " << this->tostring() << endl;
}

string Circle::tostring() const
{
	string str = "Circle[ x =" + to_string(getX()) +
		", y = " + to_string(getY()) +
		", r = " + to_string(r) + "]";
	return str;
}

double Circle::area() const
{
	return M_PI * pow(r, 2);
}