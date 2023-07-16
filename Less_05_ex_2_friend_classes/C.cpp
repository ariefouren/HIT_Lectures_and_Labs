//
// C.cpp
// demonstrating friend classes
//
#include "C.h"
#include "A.h"

void C::tryToAccessA(A& objectA)
{
	// objectA.count;	// ERROR ! 
							// class C is a friend of B but not of A
							// the relation "friend of" is not transitive
}