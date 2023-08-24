// 
// Member function definitions for class Array<char>
#include <iostream>
#include <iomanip>

#include <cstdlib>
#include <cctype>   // for isalpha() and tolower()
#include <cassert>
#include "Array1.h"
#include "Array2.h"

using namespace std;

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

/**************************************************************************
 * (C) Copyright 2000 by Deitel & Associates, Inc. and Prentice Hall.     *
 * All Rights Reserved.                                                   *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
