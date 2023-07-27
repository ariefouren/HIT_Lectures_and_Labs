//
// ComplexTest.cpp
// testing the class of complex numbers
// with operators' overloading
//
#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    Complex c1; 
    cout << "Enter complex number  (for example 2 - 1i) :";
    cin >> c1;
    
    Complex c2(1.5, 2.5);

    cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
    cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
    cout << c1 << " * " << c2 << " = " << c1 * c2 << endl;
    cout << c1 << " / " << c2 << " = " << c1 / c2 << endl << endl;

    cout << "(" << c1 << " == " << c2 << ") =  " << (c1 == c2) << endl;
    cout << "(" << c1 << " != " << c2 << ") = " << (c1 != c2) << endl << endl;

    cout << "5.0 * " << c1 << " = " << 5.0 * c1 << endl;
    cout << c1 << " * 5.0" << " = " << c1 * 5.0 << endl << endl;

    
    cout << "Postfix ++ : " << "c1 = " << c1;
    cout << "   c1++ = " << c1++ << "   c1 = " << c1 << endl;

    cout << "Prefix ++ : " << "c1 = " << c1;
    cout << "   ++c1 = " << ++c1 << "   c1 = " << c1 << endl << endl;

    cout << "Postfix -- : " << "c1 = " << c1;
    cout << "   c1-- = " << c1-- << "   c1 = " << c1 << endl;

    cout << "Prefix -- : " << "c1 = " << c1;
    cout << "   --c1 = " << --c1 << "   c1 = " << c1 << endl << endl;

    return 0;
}
