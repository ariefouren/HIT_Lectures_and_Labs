#include <iostream>
using namespace std;

template <class T> T Min (T a, T b)
{
	if (a < b)
	 return a;
	else
	 return b;
}

class Number
{
	long		num;

public:

	Number (long n) :
		num (n)
		{ }

	long	Value ()
		{
			return num;
		}

	bool operator < (Number n2)
		{
			return num < n2.Value ();
		}
} ;

void main ()
{
	Number	nn1 = 12;
	Number	nn2 = 18;
	Number 	nn3 = Min (nn1, nn2);
	cout << nn3.Value ( ) << endl ;
}