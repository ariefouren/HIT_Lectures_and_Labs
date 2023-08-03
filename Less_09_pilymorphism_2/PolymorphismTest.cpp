//
// PolymorphismTest.cpp
// Testing classes Shape and Circle
//   

#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

int main()
{
	// Pointers and inheritance 
	// with static binding, the type of the function invoked 
	// depends on the type of the pointer, not on the type of the object  
	Shape s(0, 0);
	Circle c(1, 1, 10);

	Shape* shapePtr = &s;
	cout << "shapePtr->toString() = " << shapePtr->toString() << endl;

	Circle* circlePrt = &c;
	cout << "circlePrt->toString() = " << circlePrt->toString() << endl;

	shapePtr = &c;	// Allowed since each circle is a shape
	cout << "shapePtr->toString() = " << shapePtr->toString() << endl;

	// circlePrt = &s;			// ERROR ! not each shape is circle
	circlePrt = (Circle*)&s;	// Dangerous ! May cause run-time  error 

	cout << "circlePrt->setR(10) causes run-time error  :(" << endl;
	// circlePrt->setR(10);


	// Assignments of the base and the derived classes
	s = c;  // performs Shape::operator=(Shape& ) const
			// warning: slicing
	cout << "s.toString()" << s.toString() << endl;

	// c = s;	// ERROR ! no operator Circle = Shape is defined
			// since not all the members of Circle can be set 
			// using the members of Shape 
	
	cout << endl << endl;
	int numOfShapes = 3;
	Shape* *shapesArr = new Shape*[numOfShapes]; // array of pointers to Shape
	shapesArr[0] = new Shape(0, 0);
	shapesArr[1] = new Circle(1, 1, 1);
	shapesArr[2] = new Rectangle(2, 2, 2, 2);

	for (int i = 0; i < numOfShapes; i++)
	{
		cout << "shapesArr[" << i << "]->toString() = " << shapesArr[i]->toString() << endl;
		
		Shape& shapeRef = *shapesArr[i];
		cout << "shapeRef.toString() = " << shapeRef.toString() << endl << endl;
	}

}
