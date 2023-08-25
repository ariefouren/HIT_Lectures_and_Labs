#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>


using namespace std;
template<class T, class U>
T sum(T x, U y)
{
	return x + y;
}

int sum(int a, double y)
{
	cout << "sum(int, double) is called \n";
	return a + y;
}


// function template with default type and default argument value
template<class T, class U = double>
T Exp(T power, U base = M_E )
{
	return pow(base, power);
}

// class template with default type 
template<class T = double>
class Complex
{
private:
	T re, im;
};

int main()
{
	//cout << "sum<double, int>(y, n) = " << sum<double, int>(y, n) << endl;
	//cout << "sum(y, n) = " << sum(y, n) << endl;

	//cout << "sum<int, double>(n, y) = " << sum<int, double>(n, y) << endl;
	//// if template specialization and a function 
	//// equally match, the function is preferred
	//cout << "sum(n, y) = " << sum(n, y) << endl;

	cout << "Exp(1.0) = " << Exp(1.0, 1) << endl;
	cout << "Exp(1.0) = " << Exp(1.0) << endl;
	cout << "Exp(1, M_PI) = " << Exp(1, M_PI) << endl;

	Complex<int> intComplex;
	Complex<> doubleComplex;
}