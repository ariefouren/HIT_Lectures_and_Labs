//
// Test.cpp
// Testing classes Shape and Circle
//   

#include <iostream>
#include "Shape.h"
#include "Circle.h"
using namespace std;

int main()
{
	Shape s(0, 0);
	Circle c(1, 1, 10);

	Shape* shapePtr = &s;
	Circle* circlePrt = &c;

	shapePtr = &c;
	//circlePrt = &s;			// ERROR ! not each shape is circle
	circlePrt = (Circle*) &s;	// Dangerous ! May cause run-time  error 

	cout << "circlePrt->setR(10) causes run-time error  :(" << endl;
	//circlePrt->setR(10);


	// Assignments of the base and the derived classes
	s = c;  // performs Shape::operator=(Shape& ) const
			// warning: slicing
	cout << "s.toString()" << s.toString() << endl;

	c = s;	// ERROR ! no operator Circle = Shape is defined
			// since not all the members of Circle can be set 
			// using the members of Shape 





}