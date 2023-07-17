//
// Counter.cpp
// friend functions
//

#include <iostream>
using namespace std;

class Counter
{
	friend void setCounter(Counter& counter, int value);
	friend int main();

public:
	void print() const;

private:
	int c; 
};

void setCounter(Counter& counter, int value)
{
	counter.c = value;	// setCounter is a friend function for 
						// class Counter, and therefore it can access
						// the private members of the class
}

void Counter::print() const
{
	cout << "counter c = " << c;
}

int main()
{
	Counter count1;
	setCounter(count1, 100);
	count1.print();

	count1.c = 0;		// ERROR ! variable count.c is private, 
						// and therefore is inaccessible from main()
}