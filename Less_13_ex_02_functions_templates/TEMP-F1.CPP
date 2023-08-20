#include <iostream>
using namespace std;

template <class T> T Min (T a, T b)
{
	if (a < b)
	   return a;
	else
	   return b;
}

void main ()
{
	char	c1 = 'W', c2 = 'h';
	double   d1 = 2.5, d2 = -3;
	int	n1 = 23, n2 = 67;

	cout << Min(c1, c2) << endl;
	cout << Min (d1, d2) << endl ;
	cout << Min (n1, n2) << endl ;
}