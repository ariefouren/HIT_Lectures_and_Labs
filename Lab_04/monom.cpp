// Shay Tavor, shay.tavor@gmail.com
// Monom.cpp
// implementation of class Monom
//

#include <iostream>
#include <string>
#include <math.h>
#include "Monom.h"

using namespace std;

Monom::Monom(double coefficient, int exp) {
    setCoefficient(coefficient);
    setExp(exp);
}

double Monom::getCoefficient() {
    return coefficient;
}

void Monom::setCoefficient(double coefficient) {
    this->coefficient = coefficient;
}

int Monom::getExp() {
    return exp;
}

void Monom::setExp(int exp) {
    if (exp < 0)
        exp = 0;
    this->exp = exp;
}

std::string Monom::format() {
    string res;

    if (coefficient == 0)
        res = "0";
    else
        res = to_string(coefficient);
    if (exp != 0) {
        res += "x";
        if (exp > 1)
            res += "^" + to_string(exp);
    }
    return res;
}

Monom* Monom::derivative() {
    if (exp == 0)
        return new Monom(0.0);
    return new Monom(coefficient * exp, exp - 1);
}

double Monom::eval(double x) {
    return coefficient * pow(x, exp);
}


