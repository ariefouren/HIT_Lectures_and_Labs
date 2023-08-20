// Fig 8.4: array1.cpp
// Member function definitions for class Array
#include <iostream>
#include <iomanip>

#include <cstdlib>
#include <cassert>
#include "array1.h"

// Initialize static data member at file scope
template <class T>
int Array<T>::arrayCount = 0;   // no objects yet

// Default constructor for class Array (default size 10)
template <class T>
Array<T>::Array( int arraySize )
{
   size = ( arraySize > 0 ? arraySize : 10 ); 
   ptr = new T[ size ]; // create space for array
   assert( ptr != 0 );    // terminate if memory not allocated
   ++arrayCount;          // count one more object

   for ( int i = 0; i < size; i++ )
      ptr[ i ] = 0;          // initialize array
}

// Copy constructor for class Array
// must receive a reference to prevent infinite recursion
template <class T>
Array<T>::Array( const Array &init ) : size( init.size )
{
   ptr = new T[ size ]; // create space for array
   assert( ptr != 0 );    // terminate if memory not allocated
   ++arrayCount;          // count one more object

   for ( int i = 0; i < size; i++ )
      ptr[ i ] = init.ptr[ i ];  // copy init into object
}

// Destructor for class Array
template <class T>
Array<T>::~Array()
{
   delete [] ptr;            // reclaim space for array
   --arrayCount;             // one fewer objects
}

// Get the size of the array
template <class T>
int Array<T>::getSize() const { return size; }

// Overloaded assignment operator
// const return avoids: ( a1 = a2 ) = a3
// but allows a1 = a2 = a3
template <class T>
const Array<T>& Array<T>::operator=( const Array &right )
{
   if ( &right != this ) {  // check for self-assignment
      
      // for arrays of different sizes, deallocate original
      // left side array, then allocate new left side array.
      if ( size != right.size ) {
         delete [] ptr;         // reclaim space
         size = right.size;     // resize this object
         ptr = new T[ size ]; // create space for array copy
         assert( ptr != 0 );    // terminate if not allocated
      }

      for ( int i = 0; i < size; i++ )
         ptr[ i ] = right.ptr[ i ];  // copy array into object
   }

   return *this;   // enables a1 = a2 = a3;
}

// Determine if two arrays are equal and
// return true, otherwise return false.
template <class T>
bool Array<T>::operator==( const Array &right ) const
{
   if ( size != right.size )
      return false;    // arrays of different sizes

   for ( int i = 0; i < size; i++ )
      if ( ptr[ i ] != right.ptr[ i ] )
         return false; // arrays are not equal

   return true;        // arrays are equal
}

// Overloaded subscript operator for non-const Arrays
// reference return creates an lvalue
template <class T>
T &Array<T>::operator[]( int subscript )
{
   // check for subscript out of range error
   assert( 0 <= subscript && subscript < size );

   return ptr[ subscript ]; // reference return
}

// Overloaded subscript operator for const Arrays
// const reference return creates an rvalue
template <class T>
const T &Array<T>::operator[]( int subscript ) const
{
   // check for subscript out of range error
   assert( 0 <= subscript && subscript < size );

   return ptr[ subscript ]; // const reference return
}

// Return the number of Array objects instantiated
// static functions cannot be const 
template <class T>
int Array<T>::getArrayCount() { 
	return arrayCount; 
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
