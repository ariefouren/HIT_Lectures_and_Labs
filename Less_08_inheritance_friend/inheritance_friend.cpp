//
// inheritance_friend.cpp
// Testing inheritance with friend functions
//   
#include <iostream>
using namespace std;

class B;
class A
{
	friend void friendOfA(A& a, B& b);
public:
	int publicInA; 
protected:
	int protectedInA;
private:
	int privateInA;
};

class B: public A //private A // protected A 
{
	friend void friendOfB(A& a, B& b);
public:
	void print() const
	{
		int x;
		x = publicInA;
		x = protectedInA;
		x = privateInA;		// ERROR ! private variable of A
							// is inaccessible in the derived class B
	};
};

class C : public B 
{
	void print() const 
	{
		int x;
		x = publicInA;
		x = protectedInA;
		x = privateInA;		// ERROR ! private variable of A
							// is inaccessible in the derived class B
	};
};

void friendOfA(A& a, B& b)
{
	int x;
	// friend function of class A has exactly to the same access 
	// to the members of A as the member functions of A
	
	// access to object of class A
	x = a.publicInA;
	x = a.protectedInA;
	x = a.privateInA;	

	// access to object of class B
	x = b.publicInA;
	x = b.protectedInA;
	x = b.privateInA;
}

void friendOfB(A& a, B& b)
{
	int x;
	// friend function of class A has exactly to the same access 
	// to the members of A as the member functions of A

	// access to the members of object of class A
	x = a.publicInA;
	x = a.protectedInA;
	x = a.privateInA;

	// access to the members of object of class B
	x = b.publicInA;
	x = b.protectedInA;
	x = b.privateInA;
}



int main()
{
	A a;
	B b; 
	C c;
	int x;

	// access to object of class A
	x = a.publicInA;
	x = a.protectedInA;
	x = a.privateInA;

	// access to object of class B
	x = b.publicInA;
	x = b.protectedInA;
	x = b.privateInA;

	// access to object of class C
	x = c.publicInA;
	x = c.protectedInA;
	x = c.privateInA;
}


