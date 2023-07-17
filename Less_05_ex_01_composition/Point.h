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
	void print() const;

private:
	double x;
	double y;
};

