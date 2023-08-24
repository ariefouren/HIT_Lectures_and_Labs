// 
// Member function definitions for class Array<char>
#include <iostream>
#include <iomanip>

#include <cstdlib>
#include <cctype>   // for isalpha() and tolower()
#include <cassert>
#include "Array1.h"
#include "CharArray.h"

using namespace std;

// Initialize static data member at file scope
int CharArray::arrayCount = 0;   // no objects yet

// Determine if two char arrays are equal
// Ignore case of letters
bool CharArray::operator==(const CharArray& right) const
{
    if (size != right.size)
        return false;    // arrays of different sizes

    // compare the characters, ignore the case 
    for (int i = 0; i < size; i++)
        if (tolower(ptr[i]) != tolower(right.ptr[i]))
            return false; // arrays are not equal

    return true;        // arrays are equal
}

