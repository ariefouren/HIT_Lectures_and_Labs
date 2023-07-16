#pragma once
//
// B.h
// demonstrating friend classes
//
#include "A.h"

class B
{
	friend class C;

public:
	void resetCount(A& objectA);
	void setCount(A& objectA, int value);
};