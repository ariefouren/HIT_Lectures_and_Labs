#pragma once
//
// Point.h
// definition of class Point
//
class Point
{
public:
	Point(double x = 0, double y = 0);
	~Point();
	void setXY(double x, double y);
	void print() const;

private:
	double x;
	double y;
	int pointId;		// each Point object has its unique ID
	static int numPointsCreated;	// a single copy of a static class member 
									// variable is shared 
									// by all the objects of the class
};
