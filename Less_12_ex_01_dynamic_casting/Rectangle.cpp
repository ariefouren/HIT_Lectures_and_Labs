//
// Rectangle.cpp
// implementation of class Rectangle
//

#include <iostream>
#include "Rectangle.h"		
using namespace std;

Rectangle::Rectangle(double x, double y, double length, double height):
	Shape(x, y), length(length), height(height)
{
	// cout << "constructor for : " << toString() << endl;
}

Rectangle::~Rectangle()
{
	cout << "destructor for : " << toString() << endl;
}

string Rectangle::toString() const
{
	string str = "Rectangle [x = " + to_string(x) +
		" , y = " + to_string(y) +
		", length = " + to_string(length) +
		", height = " + to_string(height) + "]";
	return str;
}

double Rectangle::area() const
{
	return length * height;
}
