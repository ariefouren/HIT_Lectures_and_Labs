#include <iostream>
using namespace std;

template<class T>
T quotient(T numerator, T denominator)
{
	return numerator/ denominator;
}

int main()
{
	int a = 4, b = 3;
	double x = 4.1, y = 3.2;

	cout << "quotient(" << a <<", " << b<< ") = " 
		<< quotient(a, b) << endl; // int quotient<int>(int, int) 
	cout << "quotient<int>(" << a << ", " << b << ") = "
		<< quotient<int>(a, b) << endl; // int quotient<int>(int, int)
	cout << "quotient<double>(" << a << ", " << b << ") = "
		<< quotient<double>(a, b) << endl << endl; // double quotient<double>(double, double)
	
	cout << "quotient(" << x <<", " << y << ") = "
		<< quotient(x, y) << endl; // double largest<double>(double, double)
	cout << "quotient<double>(" << x << ", " << y << ") = "
		<< quotient<double>(x, y) << endl; // double largest<double>(double, double)
	cout << "quotient<int>(" << x << ", " << y << ") = "
		<< quotient<int>(x, y) << endl; // double largest<int>(double, double)
}