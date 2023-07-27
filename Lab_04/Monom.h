// Shay Tavor, shay.tavor@gmail.com
// Monom.h
// definition of class Monom
//

#ifndef MONOM_H
#define MONOM_H
#include <iostream>
#include <cmath>

class Monom {
private:
    double coefficient;
    int exp;

public:
    Monom(double = 1, int = 0);
    double getCoefficient();
    void setCoefficient(double);
    int getExp();
    void setExp(int);
    std::string format();
    Monom* derivative();
    double eval(double x);
};


#endif