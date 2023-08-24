// 
// Array<T> specialization for char
// 
#ifndef ARRAY2_H
#define ARRAY2_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>   // for isalpha() and tolower()
#include <cassert>
#include "Array1.h"

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

// Initialize static data member at file scope
int Array<char>::arrayCount = 0;   // no objects yet

// Default constructor for class Array<char> (default size 100)
Array<char>::Array(int arraySize)
{
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new char[size]; // create space for array
    assert(ptr != 0);    // terminate if memory not allocated
    ++arrayCount;          // count one more object

    for (int i = 0; i < size; i++)
        ptr[i] = '#';          // initialize array
}

// Copy constructor for class Array<char>
// must receive a reference to prevent infinite recursion 
// [Q] why the problem arises and why passing the parameter by 
//     reference solves it ?
Array<char>::Array(const Array& initArr) : size(initArr.size)
{
    ptr = new char[size];     // create space for array
    assert(ptr != 0);      // terminate if memory not allocated
    ++arrayCount;            // count one more object

    for (int i = 0; i < size; i++)
        ptr[i] = initArr.ptr[i];  // copy initArr into object
}

// Destructor for class Array<char>
Array<char>::~Array()
{
    delete[] ptr;            // reclaim space for array
    --arrayCount;             // one fewer objects
}

// Get the size of the array
int Array<char>::getSize() const { return size; }

// Overloaded assignment operator
// const return avoids: ( a1 = a2 ) = a3
// but allows a1 = a2 = a3 (which is equal to a1 = (a2 = a3) ) 
const Array<char>& Array<char>::operator=(const Array& right)
{
    if (&right != this) {  // check for self-assignment

       // for arrays of different sizes, deallocate original
       // left side array, then allocate new left side array.
        if (size != right.size) {
            delete[] ptr;         // reclaim space
            size = right.size;     // resize this object
            ptr = new char[size];   // create space for array copy
            assert(ptr != 0);    // terminate if not allocated
        }

        for (int i = 0; i < size; i++)
            ptr[i] = right.ptr[i];  // copy array into object
    }

    return *this;   // enables a1 = a2 = a3;
}

// Determine if two char arrays are equal
// Ignore case of letters
bool Array<char>::operator==(const Array& right) const
{
    if (size != right.size)
        return false;    // arrays of different sizes

    // compare the characters, ignore the case 
    for (int i = 0; i < size; i++)
        if (tolower(ptr[i]) != tolower(right.ptr[i]))
            return false; // arrays are not equal

    return true;        // arrays are equal
}

// Overloaded subscript operator for non-const Arrays
// Reference return creates an l-value
char& Array<char>::operator[](int subscript)
{
    // check for subscript out of range error
    assert(0 <= subscript && subscript < size);

    return ptr[subscript]; // reference return
}

// Overloaded subscript operator for const Arrays
// const reference return creates an r-value
const char& Array<char>::operator[](int subscript) const
{
    // check for subscript out of range error
    assert(0 <= subscript && subscript < size);

    return ptr[subscript]; // const reference return
}

// Return the number of Array objects instantiated.
// Static functions cannot be const 
// [Q] Why ?
int Array<char>::getArrayCount() {
    return arrayCount;
}

// Overloaded input operator for class Array;
// inputs values for entire array.
istream& operator>>(istream& input, Array<char>& a)
{
    for (int i = 0; i < a.size; i++)
        input >> a.ptr[i];

    return input;   // enables cin >> x >> y;
}

// Overloaded output operator for class Array 
ostream& operator<<(ostream& output, const Array<char>& a)
{
    for (int i = 0; i < a.size; i++) {
        output << setw(2) << a.ptr[i];

        if ((i + 1) % 40 == 0) // 40 characters per row of output
            output << endl;
    }
    output << endl;

    return output;   // enables cout << x << y;
}


#endif



