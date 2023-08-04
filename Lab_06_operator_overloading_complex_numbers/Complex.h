//
// Complex.h
// definition of the class Complex that represents complex numbers
// demonstrates operators' overloading
//
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Complex {
    // Overloading >> operator
    friend std::istream& operator>>(std::istream& is, Complex& complex);

    // Overloading + operator for Real + Complex
    friend Complex operator+(double realNum, const Complex& complex);

    // Overloading - operator for Real - Complex
    friend Complex operator-(double realNum, const Complex& complex);

    // Overloading * operator for Real * Complex
    friend Complex operator*(double realNum, const Complex& complex);

    // Overloading / operator for Real / Complex
    friend Complex operator/(double realNum, const Complex& complex);

public:
    // the constructor is defined as explicit
    // to prevent implicit cast
    explicit Complex(double re = 0.0, double imaginary = 0.0);

    // Overloading + operator for Complex + Complex
    const Complex operator+(const Complex& other) const;

    // Overloading - operator for Complex - Complex
    const Complex operator-(const Complex& other) const;

    // Overloading * operator for Complex * Complex
    const Complex operator*(const Complex& other) const;

    // Overloading += operator for Complex += Complex
    Complex& operator+=(const Complex& other);    //  returns reference Complex&
                                            //  to allow chaining:
                                            // c1 += c2 += c3

    // Overloading == operator for Complex == Complex
    bool operator==(const Complex& other) const;

    // Overloading != operator for Complex != Complex
    bool operator!=(const Complex& other) const;

    // Overloading + operator for Complex + Real
    const Complex operator+(const double& realNum) const;

    // Overloading - operator for Complex - Real
    const Complex operator-(const double& realNum) const;

    // Overloading * operator for Complex * Real
    const Complex operator*(const double& realNum) const;

    // Overloading / operator for Complex / Complex
    const Complex operator/(const Complex& other) const;

    // Overloading / operator for Complex / Real
    const Complex operator/(const double& realNum) const;
    
    // Cast operator to convert Complex to string
    explicit operator string() const;

    // Function to get the real part of the complex number
    double getReal() const;

    // Function to get the imaginary part of the complex number
    double getImaginary() const;

private:
    double real;
    double imaginary;
};

// Overloading << operator for printing complex numbers
ostream& operator<<(std::ostream& os, const Complex& complex);
