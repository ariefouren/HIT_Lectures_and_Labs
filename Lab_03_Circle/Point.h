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
	void setX(double x);
	void setY(double y);
	void print() const;
	double distance(const Point& point);

private:
	double x;
	double y;
};
