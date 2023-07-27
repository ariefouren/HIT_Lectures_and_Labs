// Shay Tavor, shay.tavor@gmail.com
// PolynomialTest.cpp
// Testing the class Polynomial
//

#include "Monom.h"
#include "Polynomial.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{
    // Monom m1;
    // Monom m2(3);
    // Monom m3(4, 3);
    // Monom m4(-7.3, 1);

    // std::cout<<m1.format()<<std::endl;
    // std::cout<<m2.format()<<std::endl;
    // std::cout<<m3.format()<<std::endl;
    // std::cout<<m4.format()<<std::endl;

    // Monom* d1 = m1.derivative();
    // Monom* d2 = m2.derivative();
    // Monom* d3 = m3.derivative();
    // Monom* d4 = m4.derivative();

    // std::cout<<std::endl;

    // std::cout<<d1->format()<<std::endl;
    // std::cout<<d2->format()<<std::endl;
    // std::cout<<d3->format()<<std::endl;
    // std::cout<<d4->format()<<std::endl;

    // std::cout<<std::endl;

    // std::cout<<m1.eval(2)<<std::endl;
    // std::cout<<m2.eval(2)<<std::endl;
    // std::cout<<m3.eval(2)<<std::endl;
    // std::cout<<m4.eval(2)<<std::endl;

    // delete d1;
    // delete d2;
    // delete d3;
    // delete d4;

    Polynomial* p1 = new Polynomial();
    Monom* m1 = new Monom(3, 2);
    p1->addMonom(*m1);
    m1 = new Monom(-2, 5);
    p1->addMonom(*m1);
    m1 = new Monom(2, 3);
    p1->addMonom(*m1);
    m1 = new Monom(3, 1);
    p1->addMonom(*m1);

    std::cout << p1->format() << std::endl;
    std::cout << std::endl;

    Polynomial* p2 = p1->derivative();
    std::cout << p2->format() << std::endl;
    std::cout << std::endl;

    std::cout << p1->eval(2) << std::endl;

    delete p1;
    delete p2;
    return 0;
}
