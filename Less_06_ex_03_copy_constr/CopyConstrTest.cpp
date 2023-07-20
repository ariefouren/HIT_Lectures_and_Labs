//
// CopyConstrTest.cpp
// demonstrating copy constructor
//
#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass(int val = 0):
		val(val)
	{
		cout << "constructor for  ";
		this->print();
	}

	MyClass(const MyClass& obj) :
		val(obj.getVal())
	{
		cout << "COPY constructor for ";
		this->print();		
	}

	int getVal() const
	{
		return this->val;
	}

	void print()
	{
		cout << "object " << this << " val = " << this->val << endl;
	}

private:
	int val;
};

MyClass f(MyClass obj)
{
	cout << "function f with parameter ";
	obj.print();
	return obj;
}

int main()
{
	MyClass obj1(1);		// constructor call
	MyClass obj2 = obj1;	// COPY constructor call
	
	f(obj1).print();	// COPY contractor call twice: for the parameter and
						// for the returned value
	cout << "------------------------------\n\n";

	MyClass obj3 = obj1; // COPY constructor 

	MyClass obj4;		// default constructor is used for obj4
	obj4 = obj1;		// copy assignment operator
	obj4.print();
}