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

class B:  private A // public A // protected A 
{
	friend void friendOfB(A& a, B& b);
public:
	void print() const
	{
		int x;
		x = publicInA;
		x = protectedInA;
		x = privateInA;		// ERROR if B inherits from A as 'public'
							// private variable of A
							// is inaccessible in the derived class B
	};
};

class C : public B 
{
	void print() const 
	{
		int x;
		x = publicInA;		// ** ERROR if B inherits from A as 'private'
		x = protectedInA;	// ** ERROR if B inherits from A as 'private'
		x = privateInA;		// ERROR if B inherits from A as 'public'
							// ! private variable of A
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
	x = a.protectedInA;		// ERROR if B inherits from A as 'public'
	x = a.privateInA;		// ERROR if B inherits from A as 'public'

	// access to the members of object of class B
	x = b.publicInA;
	x = b.protectedInA;
	x = b.privateInA;		// ERROR if B inherits from A as 'public'
}



int main()
{
	A a;
	B b; 
	C c;
	int x;

	// access to object of class A
	x = a.publicInA;		
	x = a.protectedInA;		// ERROR if B inherits from A as 'public'
	x = a.privateInA;		// ERROR if B inherits from A as 'public'

	// access to object of class B
	x = b.publicInA;		// * ERROR if B inherits from A as 'protected'
	x = b.protectedInA;		// ERROR if B inherits from A as 'public'
	x = b.privateInA;		// ERROR if B inherits from A as 'public'

	// access to object of class C
	x = c.publicInA;		// * ERROR if B inherits from A as 'protected'
	x = c.protectedInA;		// ERROR if B inherits from A as 'public'
	x = c.privateInA;		// ERROR if B inherits from A as 'public'
}


