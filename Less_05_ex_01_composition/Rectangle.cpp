//
// Rectangle.cpp
// implementation of class Rectangle
//

#include <iostream>
#include "Rectangle.h"		
using namespace std;

Rectangle::Rectangle(const Point& p1, const Point& p2) :
	p1(p1), p2(p2)		// default copy constructor 
						// for class Point is used
{
	cout << "constructor for rectangle (";
	this->p1.print();		// note the use of "this" pointer to avoid 
							// naming collision
	cout << ", ";
	this->p2.print();
	cout << ")" << endl;
}


Rectangle::Rectangle()	// if the constructor for class Rectangle
						// doesn't use initialization list to
						// explicitly initialize the member variables p1, p2
						// and there is no default constructor
						// (without parameters) for class Point,  then
						// a compilation error occurs
{

}


Rectangle::~Rectangle()
{
	cout << "destructor for rectangle (";
	this->p1.print();
	cout << ", ";
	this->p2.print();
	cout << ")" << endl;
}
