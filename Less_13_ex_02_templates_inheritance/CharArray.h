#pragma once
//
// CharArray
// Demonstrates inheritance from template  
//
#include "Array1.h"

class CharArray : public Array<char>
{
public:
	CharArray(int size = 10): Array<char>(size) {};
	~CharArray() {};

	bool operator==(const CharArray&) const;  // compare equal
};