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
	cout << "c1.area() = " << c1.area() << endl;
}