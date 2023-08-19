//============================================================================
// Name        : OOP-CPP-HIT-Lab09.cpp
// Author      : Mordo Shalom
// Version     :
// Copyright   : Your copyright notice
// Description : 
//============================================================================

#include <iostream>
#include <iomanip>
#include "Customer.h"
#include "Queue.h"

using namespace std;


int main() {

	Queue q1;
	cout << boolalpha;
	cout << "Is q1 empty ? " << q1.isEmpty()  << endl;
	Customer c1 = Customer ("Number One");
	Customer c2 = (string) "Number Two";
	Customer *c3 = new Customer("Number Three");
	q1.enqueue(c1);
	cout << "Is q1 empty ? " << q1.isEmpty() << endl;
	q1.enqueue(c2);
	q1.enqueue(*c3);
	q1.print();
	cout << endl;

	c1.deposit(111);
	c2.deposit(222);
	c3->deposit(333);
	q1.print();
	cout << endl;

	Queue q2 = q1;

	cout << "Head of q1 is ";
	q1.peek()->print();
	cout << endl;

	cout << "Removing head of q1 ";
	q1.dequeue()->print();
	cout << endl;

	cout << "Head of q1 is ";
	q1.peek()->print();
	cout << endl;
	cout << "Is q1 empty ? " << q1.isEmpty()  << endl;

	cout << "Removing head of q1 ";
	q1.dequeue()->print();
	cout << endl;
	cout << "Is q1 empty ? " << q1.isEmpty()  << endl;

	cout << "Removing head of q1 ";
	q1.dequeue()->print();
	cout << endl;
	cout << "Is q1 empty ? " << q1.isEmpty()  << endl;

    cout << "Peek returns " << q1.peek() << endl;
    cout << "Dequeue returns " << q1.dequeue() << endl;

	cout << "Is q1 empty ? " << q1.isEmpty()  << endl;

	cout << "q2:" << endl;
	q2.print();

	Customer* customers[]={&c1, c3, &c2, nullptr};
	Queue q3 = customers;

	cout << "q3:" << endl;
	q3.print();


	return 0;
}
