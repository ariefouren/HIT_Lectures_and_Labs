#include <iostream>

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

int main()
{
	int n = 10;
	double y = 3.14;

	cout << "sum<double, int>(y, n) = " << sum<double, int>(y, n) << endl;
	cout << "sum(y, n) = " << sum(y, n) << endl;

	cout << "sum<int, double>(n, y) = " << sum<int, double>(n, y) << endl;
	// if template specialization and a function 
	// equally match, the function is preferred
	cout << "sum(n, y) = " << sum(n, y) << endl;



}