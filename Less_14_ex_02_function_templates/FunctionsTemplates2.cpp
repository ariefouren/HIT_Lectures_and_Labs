#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>


using namespace std;

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
	cout << "Exp(1.0) = " << Exp(1.0, 1) << endl;
	cout << "Exp(1.0) = " << Exp(1.0) << endl;
	cout << "Exp(1, M_PI) = " << Exp(1, M_PI) << endl;

	Complex<int> intComplex;
	Complex<> doubleComplex;
}