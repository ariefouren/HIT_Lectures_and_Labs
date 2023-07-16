//
// Test.cpp
// Testing dynamic memory allocation
//   

#include <iostream>
#include "Point.h"		
using namespace std;

int main()
{
	Point* pointArr[3];			// array of pointers
	for (int i = 0; i < 3; i++)
	{
		pointArr[i] = new Point(i, i);
		pointArr[i] -> print();
	}
	
	cout << "\n\ndelete pointArr[]: \n";
	for (int i = 0; i < 3; i++)
	{
		delete pointArr[i];
	}
}