//
// Test.cpp
// Testing cascaded functions calls
//   

#include <iostream>
#include "Point.h"		
using namespace std;

int main()
{
	Point p;
	p.setX(-1).setY(-2).print();	// cascaded functions calls
}