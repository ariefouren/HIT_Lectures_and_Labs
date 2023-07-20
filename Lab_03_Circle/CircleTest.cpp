//
// CircleTest.cpp
// Testing class Circle
//   

#include <iostream>
#include "Point.h"		
#include "Circle.h"
using namespace std;

int main()
{
	Point p1(0, 0);
	Circle circ1(p1, 10);

	Point p2(20, 0);
	Circle circ2(p2, 10);
	
	cout << "circ2 covers p1 ? " << circ2.covers(p1) << endl;
	cout << "circ2 covers circ1 ? " << circ2.covers(circ1) << endl;
	cout << "circ2 overlaps with circ1 ? " << circ2.overlaps(circ1) << endl;
}