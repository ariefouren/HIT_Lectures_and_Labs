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
	Circle c1(1, 1, 10);
	// call to function toString() of the derives class:
	cout << "c1.toString() = " << c1.toString() << endl;
	
	// call to function toString() of the base class:
	cout << "c1.Shape::toString() = " << c1.Shape::toString() << endl;


}