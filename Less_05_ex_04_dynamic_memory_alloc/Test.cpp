//
// Test.cpp
// Testing dynamic memory allocation
//   

#include <iostream>
#include "Point.h"		
using namespace std;

int main()
{
	Point* p1 = new Point(0, 0);
	Point* p2 = new Point(*p1); // default copy constructor
	Point* p3 = p1;

	cout << "point (*p1): ";
	p1->print();
	cout << "point (*p2): ";
	p2->print();
	cout << "point (*p3): ";
	p3->print();

	(*p3).setXY(10, 20);
	cout << "\n\nafter (*p3).setXY(10, 20) :\n";

	cout << "point (*p1): ";
	p1->print();

	cout << "point (*p2): ";
	p2->print();

	cout << "point (*p3): ";
	p3->print();

	delete p1;
	delete p2;
	// delete p3; // runtime ERROR !

}
