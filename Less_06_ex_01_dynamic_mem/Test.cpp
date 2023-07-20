//
// Test.cpp
// Testing dynamic memory allocation
//   

#include <iostream>
#include "Point.h"		
using namespace std;

int main()
{
	cout << "number of points created: " << Point::getNumPointsCreated() << endl;
	cout << "statically allocated array: Point array1[2]\n";
	Point array1[2];	// a default constructor Point()
						// is called for each element of array1[]
	
	cout << "\ndynamically allocated array: Point* array2 = new Point[3]\n";
	Point* array2 = new Point[3];	// a default constructor Point()
									// is called for each element of 
									// dynamically allocated array2[]
	cout << "\nrelease dynamically allocated array:  delete[] array2:\n";
	delete[] array2;	// release memory of dynamically allocated aray2[]
						// the destructor is automatically called for 
						// each element of array2[]

	
	cout << 
		"\ndynamically allocate array of pointers: Point** array3 = new Point*[3]\n";
	Point** array3 = new Point*[3];		// array of pointers 
										// to objects of class Point
	cout << "\ndynamically allocate Point object for each pointer in  array3[]\n";
	for (int i = 0; i < 3; i++)
	{
		array3[i] = new Point(i, i);
	}

	cout << "\ndelete dynamically allocated Point object for each pointer in  array3[]\n";
	for (int i = 0; i < 3; i++)
	{
		delete array3[i];
	}
	
	cout << "\nrelease dynamically allocated array of pointers:  delete[] array3:\n";
	delete[] array3;

	cout << "number of points created: " << Point::getNumPointsCreated() << endl;
	cout << "\nend of main()\n";
}