#pragma once
//
// A.h
// demonstrating friend classes
//

class A
{
friend class B;		// in order to declare B as a friend class of A
					// it is unnecessary to include file B.h in A.h
public:
	void print() const;

private:
	int count;
};