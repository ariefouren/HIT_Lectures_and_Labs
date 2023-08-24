// 
// Array<T> specialization for char
// 
#ifndef ARRAY2_H
#define ARRAY2_H

#include "Array1.h"
#include <iostream>
using namespace std;

template <>
class Array<char> {
    friend ostream& operator<<(ostream&, const Array<char>&);
    friend istream& operator>>(istream&, Array<char>&);
public:
    Array(int = 100);                   // default constructor
    Array(const Array&);              // copy constructor
    virtual ~Array();                            // destructor
    const Array& operator=(const Array&); // assign arrays

    // Determine if two char arrays are equal
    // Ignore case of letters
    bool operator==(const Array&) const;  

    int getSize() const;                 // return size
    // Determine if two arrays are not equal (uses operator==).
    bool operator!=(const Array& right) const
    {
        return !(*this == right);
    }

    char& operator[](int);    // subscript operator - returns l-value
    const char& operator[](int) const; // subscript operator - returns r-value

    static int getArrayCount();          // Return count of 
                                         // arrays instantiated.
private:
    int size; // size of the array
    char* ptr; // pointer to first element of array
    static int arrayCount;  // # of Arrays instantiated
};

#endif



