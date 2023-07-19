#pragma once
//
// Point.h
// definition of class Point – to demonstrate cascaded functions calls
//

class Point
{
public:
	Point(double x = 0, double y = 0);
	~Point();
	Point& setX(double x);
	Point& setY(double y);
	const Point& print() const;

private:
	double x;
	double y;
	int pointId;		// each Point object has its unique ID
	static int numPointsCreated;	// a single copy of a static class member 
									// variable is shared 
									// by all the objects of the class
};
