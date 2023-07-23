#pragma once
#include <iostream>
using namespace std;

class Complex {
public:
   Complex(double re = 0.0, double imaginary = 0.0);

    // Overloading + operator for Complex + Complex
    Complex operator+(const Complex& other) const;
    
    // Overloading - operator for Complex - Complex
    Complex operator-(const Complex& other) const;

    // Overloading * operator for Complex * Complex
    Complex operator*(const Complex& other) const;
    
    // Overloading == operator for Complex == Complex
    bool operator==(const Complex& other) const;
    
    // Overloading != operator for Complex != Complex
    bool operator!=(const Complex& other) const;
    
    // Overloading + operator for Complex + Real
    Complex operator+(const double& realNum) const;
    
    // Overloading - operator for Complex - Real
    Complex operator-(const double& realNum) const;
    
    // Overloading * operator for Complex * Real
    Complex operator*(const double& realNum) const;
    
    // Overloading + operator for Real + Complex
    friend Complex operator+(const double& realNum, const Complex& complex);
    
    // Overloading - operator for Real - Complex
    friend Complex operator-(const double& realNum, const Complex& complex);
    
    // Overloading * operator for Real * Complex
    friend Complex operator*(const double& realNum, const Complex& complex);

    // Overloading / operator for Complex / Complex
    Complex operator/(const Complex& other) const;

    // Overloading / operator for Complex / Real
    Complex operator/(const double& realNum) const;

    // Overloading / operator for Real / Complex
    friend Complex operator/(const double& realNum, const Complex& complex);

    // Postfix ++ operator affecting the real part only
    Complex operator++(int);

    // Prefix ++ operator affecting the real part only
    Complex& operator++();

    // Postfix -- operator affecting the real part only
    friend Complex operator--(Complex& complex, int);

    // Prefix -- operator affecting the real part only (friend function)
    friend Complex& operator--(Complex& complex);

    // Overloading >> operator
    friend std::istream& operator>>(std::istream& is, Complex& complex);
            
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
