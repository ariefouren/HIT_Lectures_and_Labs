#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;

template<class N, class D, class Q = N>
Q quotient(N numerator, D denominator)
{
	return (Q) numerator / denominator;
}


int main()
{
	int a = 4, b = 3;
	double x = 4.1, y = 3.2;

	cout << "--- explicit specialization of function template: ---\n";
	cout << "quotient<double, double, double>(" << x <<", " << y<< ") = " 
		<< quotient<double, double, double>(x, y) << endl; 
	cout << "quotient<double, double>(" << x <<", "<< y<<") = "
		<< quotient<double, double>(x, y) << endl;
	cout << "quotient<double, double, int>(" << x <<", " << y <<") = "
		<< quotient<double, double, int>(x, y) << endl;
	cout << "quotient<int, int, int>(" << x <<", " << y <<") = "
		<< quotient<int, int, int>(x, y) << endl;

	cout << "\n--- implicit specialization of function template: ---\n";
	cout <<  "quotient(" << a <<", "<< y <<") = "
		<< quotient(a, y) << endl;
	cout << "quotient(" << x<< ", " << b <<") = "
		<< quotient(x, b) << endl;
	cout << "quotient(" << a<<", " << b<<") = "
		<< quotient(a, b) << endl;
	cout <<"quotient(" << x <<", "<< y <<") = "
		<< quotient(x, y) << endl;
}

//
//// ==========================
//// 
//// function template with default type and default argument value
//template<class T, class U = double>
//T Exp(T power, U base = M_E )
//{
//	return pow(base, power);
//}
//
//// class template with default type 
//template<class T = double>
//class Complex
//{
//private:
//	T re, im;
//};
//
//int main()
//{
//	//cout << "sum<double, int>(y, n) = " << sum<double, int>(y, n) << endl;
//	//cout << "sum(y, n) = " << sum(y, n) << endl;
//
//	//cout << "sum<int, double>(n, y) = " << sum<int, double>(n, y) << endl;
//	//// if template specialization and a function 
//	//// equally match, the function is preferred
//	//cout << "sum(n, y) = " << sum(n, y) << endl;
//
//	cout << "Exp(1.0) = " << Exp(1.0, 1) << endl;
//	cout << "Exp(1.0) = " << Exp(1.0) << endl;
//	cout << "Exp(1, M_PI) = " << Exp(1, M_PI) << endl;
//
//	Complex<int> intComplex;
//	Complex<> doubleComplex;
//}