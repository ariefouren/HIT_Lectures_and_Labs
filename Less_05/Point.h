#pragma once
//
// Point.h
// definition of class Point
//
class Point
{
public:
	Point(double x, double y);
	~Point();
	void print() const;

private:
	double x;
	double y;
};
