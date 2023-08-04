//
// Complex.cpp
// implementation of the class Complex that represents complex numbers
// demonstrates operators' overloading
//
#include <iostream>
#include <string>
#include "Complex.h"
using namespace std;

explicit Complex::Complex(double re, double imaginary)
    : real(re), imaginary(imaginary) {}


// explicit cast operator to convert Complex to string
explicit Complex::operator string() const
{
    string str = "(" + to_string(real);
    if (imaginary >= 0) str += " + ";
    else                str += " - ";

    str += to_string(abs(imaginary)) + "i" + ")";
    return str;
}

// Overloading + operator for Complex + Complex
const Complex Complex::operator+(const Complex& other) const {
    return Complex(this->real + other.real, this->imaginary + other.imaginary);
}

// Overloading - operator for Complex - Complex
const Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

// Overloading * operator for Complex * Complex
const Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imaginary * other.imaginary,
        real * other.imaginary + imaginary * other.real);
}

Complex& Complex::operator+=(const Complex& other)
{
    (*this) = (*this) + other;
    return (*this);
}

// Overloading == operator for Complex == Complex
bool Complex::operator==(const Complex& other) const {
    return (real == other.real) && (imaginary == other.imaginary);
}

// Overloading != operator for Complex != Complex
bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// Overloading + operator for Complex + Real
const Complex Complex::operator+(const double& realNum) const {
    return (*this) + Complex(realNum);
}

// Overloading - operator for Complex - Real
const Complex Complex::operator-(const double& realNum) const {
    return (*this) - Complex(realNum);
}

// Overloading * operator for Complex * Real
const Complex Complex::operator*(const double& realNum) const {
    return(*this) * Complex(realNum);
}

// Overloading + operator for Real + Complex
Complex operator+(const double& realNum, const Complex& complex) {
    return Complex(realNum) + complex; // Reuse the already defined operator
}

// Overloading - operator for Real - Complex
Complex operator-(const double& realNum, const Complex& complex) {
    return Complex(realNum) - complex;
}

// Overloading * operator for Real * Complex
const Complex operator*(const double& realNum, const Complex& complex) {
    return Complex(realNum) - complex; // Reuse the already defined operator
}

// Function to get the real part of the complex number
double Complex::getReal() const {
    return real;
}

// Function to get the imaginary part of the complex number
double Complex::getImaginary() const {
    return imaginary;
}

// Overloading / operator for Complex / Complex
const Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    double realPart = (real * other.real + imaginary * other.imaginary) / denominator;
    double imagPart = (imaginary * other.real - real * other.imaginary) / denominator;
    return Complex(realPart, imagPart);
}

// Overloading / operator for Complex / Real
const Complex Complex::operator/(const double& realNum) const {
    return Complex(real / realNum, imaginary / realNum);
}

// Overloading / operator for Real / Complex
Complex operator/(const double& realNum, const Complex& complex) {
    return Complex(realNum) / complex;
}

// Overloading << operator for printing complex numbers
ostream& operator<<(ostream& os, const Complex& complex) {
    os << (string)complex;
    return os;
}

istream& operator>>(std::istream& is, Complex& complex) {
    char sign;
    is >> complex.real;
    is >> sign;
    if (sign == '+') {
        is >> complex.imaginary;
    }
    else if (sign == '-') {
        is >> complex.imaginary;
        complex.imaginary = -complex.imaginary;
    }
    else {
        is.setstate(std::ios::failbit);
        return is;
    }
    if (is.peek() == 'i') // Check for 'i' at the end
        is.ignore(); // Ignore 'i' character if present
    return is;
}
