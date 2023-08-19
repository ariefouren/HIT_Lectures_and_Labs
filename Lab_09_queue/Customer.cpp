/*
 * Customer.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: cmshalom
 */

#include <iostream>
#include "Customer.h"

using namespace std;

int Customer::nextAccountNumber = 1;

Customer::Customer(const string name) {
	this->name = name;
	accountNumber = nextAccountNumber++;
	balance = 0;
}

void Customer::deposit(double amount) {
	balance += amount;
}

bool Customer::withdraw(double amount) {
	if (amount > balance) return false;
	balance -= amount;
	return true;
}

string Customer::getName() const {
	return name;
}

int Customer::getAccountNumber() const {
	return accountNumber;
}

double Customer::getBalance() const {
    return balance;
}

void Customer::print() const {
    cout << "Acc: " << accountNumber << ", " << name << ", Balance:" << balance;
}
