#pragma once
//
// C.h
// demonstrating friend classes
//
#include "A.h"

class C
{
public:
	void tryToAccessA(A& objectA);
};
