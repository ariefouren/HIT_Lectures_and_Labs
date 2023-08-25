// Fig. 8.4: array1.h
// Simple class Array (for integers)
#ifndef ARRAY1_H
#define ARRAY1_H

#include <iostream>
using namespace std;

template <class T>
// Alternative form:
// template <typename T>
class Array {
   template <class T>
        friend ostream &operator<<( ostream &, const Array<T> & );
   template <class T>
        friend istream &operator>>( istream &, Array<T> & );
public:
   Array( int = 5 );                   // default constructor
   Array( const Array & );              // copy constructor
   virtual ~Array();                            // destructor
   const Array &operator=( const Array & ); // assign arrays
   
   bool operator==( const Array & ) const;  // compare equal

   int getSize() const;                 // return size
   // Determine if two arrays are not equal (uses operator==).
   bool operator!=( const Array &right ) const  
      { return ! ( *this == right ); }
   
   T &operator[]( int );    // subscript operator - returns l-value
   const T &operator[]( int ) const; // subscript operator - returns r-value
 
   static int getArrayCount();          // Return count of 
                                        // arrays instantiated.
protected:
   int size; // size of the array
   T *ptr; // pointer to first element of array
   static int arrayCount;  // # of Arrays instantiated
};

#endif



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