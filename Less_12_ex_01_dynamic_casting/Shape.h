//
// Shape.h
// definition of class Shape
//
#pragma once
#include <string>
using namespace std;

class Shape
{
public:
	Shape(double x = 0, double y = 0);
	~Shape();				// not-virtual destructor 
	// virtual ~Shape();	// virtual destructor 
	// virtual ~Shape() = 0; // pure virtual destructor 

	virtual string toString() const;
	virtual double area() const = 0 ;
	
protected:
	double x;
	double y;
};