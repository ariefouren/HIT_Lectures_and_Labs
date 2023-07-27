// Shay Tavor, shay.tavor@gmail.com
// Polynomial.h
// definition of class Polynomial
//

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "Monom.h"

class Polynomial {
private:
    static const int N = 10;
    Monom monoms[N];
    int numOfMonoms;

public:
    Polynomial();
    void addMonom(Monom& m);
    Polynomial* derivative();
    double eval(double);
    std::string format();
    ~Polynomial();
};

#endif