// Fig. 8.4: fig08_04.cpp
// Driver for simple class Array
#include <iostream>
#include "array1.cpp"

using namespace std;

// Overloaded input operator for class Array;
// inputs values for entire array.
template <class T>
istream& operator>>(istream& input, Array<T>& a)
{
    for (int i = 0; i < a.size; i++)
        input >> a.ptr[i];

    return input;   // enables cin >> x >> y;
}

// Overloaded output operator for class Array 
template <class T>
ostream& operator<<(ostream& output, const Array<T>& a)
{
    int i;

    for (i = 0; i < a.size; i++) {
        output << setw(6) << a.ptr[i];

        if ((i + 1) % 8 == 0) // 8 numbers per row of output
            output << endl;
    }

    if (i % 8 != 0)
        output << endl;

    return output;   // enables cout << x << y;
}


int main()
{
    // create two <int> arrays
    Array<int> integers1(7), integers2;

   // create one <double> array
   Array<double> doubles1(5);

   cout << "# of <int> arrays = "
       << Array<int>::getArrayCount() << '\n';

   cout << "# of <double> arrays = "
       << Array<double>::getArrayCount() << endl<<endl;

   int sz=integers1;
   cout<<"integers1 has "<<sz<<" elements"<<endl<<endl;

   // print integers1 size and contents
   cout << "Size of array integers1 is "
        << integers1.getSize()
        << "\nArray after initialization:\n"
        << integers1 << '\n';

   // print integers2 size and contents
   cout << "Size of array integers2 is "
        << integers2.getSize()
        << "\nArray after initialization:\n"
        << integers2 << '\n';

   // input and print integers1 and integers2
   cout << "Input 17 integers:\n";
   cin >> integers1 >> integers2;
   cout << "After input, the arrays contain:\n"
        << "integers1:\n" << integers1
        << "integers2:\n" << integers2 << '\n';

   // use overloaded inequality (!=) operator
   cout << "Evaluating: integers1 != integers2\n";
   if ( integers1 != integers2 )
      cout << "They are not equal\n";

   // create array integers3 using integers1 as an
   // initializer; print size and contents
   Array<int> integers3( integers1 );

   cout << "\nSize of array integers3 is "
        << integers3.getSize()
        << "\nArray after initialization:\n"
        << integers3 << '\n';
   

   // use overloaded assignment (=) operator
   cout << "Assigning integers2 to integers1:\n";
   integers1 = integers2;
   cout << "integers1:\n" << integers1
        << "integers2:\n" << integers2 << '\n';

   // use overloaded equality (==) operator
   cout << "Evaluating: integers1 == integers2\n";
   if ( integers1 == integers2 )
      cout << "They are equal\n\n";

   // use overloaded subscript operator to create rvalue
   cout << "integers1[5] is " << integers1[ 5 ] << '\n';

   // use overloaded subscript operator to create lvalue
   cout << "Assigning 1000 to integers1[5]\n";
   integers1[ 5 ] = 1000;
   cout << "integers1:\n" << integers1 << '\n';

   // attempt to use out of range subscript
   cout << "Attempt to assign 1000 to integers1[15]" << endl;
   integers1[ 15 ] = 1000;  // ERROR: out of range

  // ERROR ! No operator matches Array<double> = Array<int>
  // doubles1 = integers1;

   return 0;
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
