// Fig. 8.4: fig08_04.cpp
// Driver for simple class Array
#include <iostream>
#include "array1.h"
#include "array2.h"


using namespace std;

int main()
{
  //  // create two <int> arrays
  //  Array<int> integers1(7), integers2;

  // // create one <double> array
  // Array<double> doubles1(5);

  // cout << "# of <int> arrays = "
  //     << Array<int>::getArrayCount() << '\n';

  // cout << "# of <double> arrays = "
  //     << Array<double>::getArrayCount() << endl<<endl;
  // 
  // int sz = integers1.getSize();
  // cout<<"integers1 has "<<sz<<" elements"<<endl<<endl;

  // // print integers1 size and contents
  // cout << "Size of array integers1 is "
  //      << integers1.getSize()
  //      << "\nArray after initialization:\n"
  //      << integers1 << '\n';

  // // print integers2 size and contents
  // cout << "Size of array integers2 is "
  //      << integers2.getSize()
  //      << "\nArray after initialization:\n"
  //      << integers2 << '\n';

  // // input and print integers1 and integers2
  // cout << "Input 17 integers:\n";
  // cin >> integers1 >> integers2;
  // cout << "After input, the arrays contain:\n"
  //      << "integers1:\n" << integers1
  //      << "integers2:\n" << integers2 << '\n';

  // // use overloaded inequality (!=) operator
  // cout << "Evaluating: integers1 != integers2\n";
  // if ( integers1 != integers2 )
  //    cout << "They are not equal\n";

  // // create array integers3 using integers1 as an
  // // initializer; print size and contents
  // Array<int> integers3( integers1 );

  // cout << "\nSize of array integers3 is "
  //      << integers3.getSize()
  //      << "\nArray after initialization:\n"
  //      << integers3 << '\n';
  //
  // // use overloaded assignment (=) operator
  // cout << "Assigning integers2 to integers1:\n";
  // integers1 = integers2;
  // cout << "integers1:\n" << integers1
  //      << "integers2:\n" << integers2 << '\n';

  // // use overloaded equality (==) operator
  // cout << "Evaluating: integers1 == integers2\n";
  // if ( integers1 == integers2 )
  //    cout << "They are equal\n\n";

  // // use overloaded subscript operator to create r-value
  // cout << "integers1[5] is " << integers1[ 5 ] << '\n';

  // // use overloaded subscript operator to create l-value
  // cout << "Assigning integers1[5] = 1000 \n";
  // integers1[ 5 ] = 1000;
  // cout << "integers1:\n" << integers1 << '\n';

  // // attempt to use out of range subscript
  // cout << "Attempt to assign integers1[15] = 1000" << endl;
  // integers1[ 15 ] = 1000;  // ERROR: out of range

  //// ERROR ! No operator matches Array<double> = Array<int>
  //// doubles1 = integers1;

   // Testing Array<char>
   Array<char> charArr1(5), charArr2(5);
   cout << "Enter 5 characters for charArr1: ";
   cin >> charArr1;

   cout << "Enter 5 characters for charArr2: ";
   cin >> charArr2;

   cout << "charArr1 = " << charArr1 << endl;
   cout << "charArr2 = " << charArr2 << endl;

   cout << "charArr1 == charArr2 returns " << (charArr1 == charArr2);

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
