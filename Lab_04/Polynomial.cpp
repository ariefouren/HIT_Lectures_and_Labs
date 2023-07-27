// Shay Tavor, shay.tavor@gmail.com
// Polynomial.cpp
// implementation of class Polynomial
//

#include "Polynomial.h"

Polynomial::Polynomial() {
    numOfMonoms = 0;
    memset(monoms, 0, N * sizeof(Monom));
}

void Polynomial::addMonom(Monom& m) {
    if (numOfMonoms < N) {
        int i;
        bool added = false;
        for (i = 0; i < numOfMonoms && !added; i++) {
            if (monoms[i].getExp() == m.getExp()) {
                monoms[i].setCoefficient(monoms[i].getCoefficient() + m.getCoefficient());
                added = true;
            }
            else if (monoms[i].getExp() > m.getExp() || monoms[i].getExp() == 0)
                break;
        }

        if (!added) {
            for (int j = numOfMonoms; j > i; j--)
                monoms[j] = monoms[j - 1];
            monoms[i].setCoefficient(m.getCoefficient());
            monoms[i].setExp(m.getExp());

            numOfMonoms++;
        }
    }
}

Polynomial* Polynomial::derivative() {
    Polynomial* res = new Polynomial();

    for (int i = 0; i < numOfMonoms; i++) {
        Monom* d = monoms[i].derivative();
        res->addMonom(*d);
        delete d; d = nullptr;
    }

    return res;
}

double Polynomial::eval(double x) {
    double res = 0;
    for (int i = 0; i < numOfMonoms; i++)
        res += monoms[i].eval(x);
    return res;
}

std::string Polynomial::format() {
    std::string res = "";
    for (int i = 0; i < numOfMonoms - 1; i++) {
        res += monoms[i].format();
        if (monoms[i + 1].getCoefficient() >= 0)
            res += "+";
    }

    if (numOfMonoms != 0)
        res += monoms[numOfMonoms - 1].format();
    return res;
}

Polynomial::~Polynomial() {
}