/*
 * Customer.h
 *
 *  Created on: Nov 21, 2019
 *      Author: cmshalom
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
using namespace std;

class Customer {
public:
	Customer(const  string name);
	void deposit(double);
	bool withdraw(double);
	 string getName() const;
	int getAccountNumber() const;
	double getBalance() const;
	void print() const;
private:
	static int nextAccountNumber;
	 string name;
	int accountNumber;
	double balance;
};

#endif /* CUSTOMER_H_ */
