//
// TestABC.cpp
// demonstrating friend classes
//
#include "A.h"
#include "B.h"

#include <iostream>
using namespace std;

int main()
{
	A a;
	B b;
	
	a.print();
	b.resetCount(a);
	a.print();

	b.setCount(a, 100);
	a.print();

}