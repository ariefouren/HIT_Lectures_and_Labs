//
// Test.cpp
// Testing dynamic memory allocation
//   

#include <iostream>
#include "Point.h"		
using namespace std;

int main()
{
	Point arr[3];

	Point* arr2 = new Point[2];
	delete[] arr2;
	/*
	In C++, when you allocate an array of objects dynamically
	using the new operator, the destructor is called
	for each individual object in the array when you explicitly
	delete the array using the delete[] operator.
	*/

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