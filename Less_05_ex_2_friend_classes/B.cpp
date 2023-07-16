#pragma once
//
// B.cpp
// demonstrating friend classes
//
#include <iostream>
#include "A.h"
#include "B.h"

void B::resetCount(A& objectA)
{
	objectA.count = 0;	// friend class B has an access to private 
						// members of class A
}

void B::setCount(A& objectA, int value)
{
	objectA.count = value;	// friend class B has an access to private 
							// members of class A
}
