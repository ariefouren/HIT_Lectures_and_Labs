#include <iostream>
using namespace std;

template <class T> T Min ( T a, T b )
{
	if ( a < b )
	 return a ;
	else
	 return b ;
}

void main ()
{
	char	c1 = 'W', c2 = 'h' ;
	int	n1 = 23, n2 = 67 ;
	long	n3 = 10000 ;
	float	n4 = 34.23, n5 = 7.77 ;

	cout << Min ( c1, c2 ) << endl ;
	cout << Min ( n1, n2 ) << endl ;
	cout << Min ( c1, n1 ) << endl ;		// ERROR
	cout << Min ( n2, n3 ) << endl ;		// ERROR
	cout << Min ( n3, n4 ) << endl ;		// ERROR
	cout << Min ( n4, n5 ) << endl ;
}