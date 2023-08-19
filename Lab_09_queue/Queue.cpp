/*
 * Queue.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: cmshalom
 */

#include <iostream>

#include "Queue.h"
#include "Customer.h"

using namespace std;

Queue::Queue() {
	init();
}

void Queue::init() {
	head = tail = nullptr;
}

Queue::Queue(const Queue& other) {
	init();
    Node *p=other.head;
    while (p != nullptr) {
        enqueue(*(p->customer));
        p = p->next;
    };
}

Queue::Queue(Customer **customers) {
	init();
	int i=0;
    while (customers[i]) {
        enqueue(*(customers[i++]));
    };
}

Queue::~Queue() {
	while(!isEmpty()) dequeue();
}

void Queue::enqueue(Customer & customer) {
    Node *newNode = new Node;
    newNode->customer = &customer;
    newNode->next = nullptr;
    if (tail) {
    	tail->next = newNode;
    } else {
    	head = newNode;
    }
    tail = newNode;
}

Customer *Queue::dequeue() {
    if (!head) return nullptr;
    Node *oldHead=head;
    Customer *ret = oldHead->customer;
    head = head->next;
    if (!head) tail = nullptr;
    delete oldHead;
    return ret;
}

Customer *Queue::peek() const {
    if (isEmpty()) return nullptr;
    return head->customer;
}

bool Queue::isEmpty() const {
	return !head;
}


void Queue::print() const {
    Node *p=head;
    while (p) {
        p->customer->print();
        cout << endl;
        p = p->next;
    };
}
