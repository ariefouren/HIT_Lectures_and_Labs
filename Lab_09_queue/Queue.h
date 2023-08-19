/*
 * Queue.h
 *
 *  Created on: Nov 21, 2019
 *      Author: cmshalom
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Customer.h"

class Queue {
public:
	Queue();
	Queue(const Queue&);
	Queue(Customer **);
	void enqueue(Customer &);
	Customer *dequeue();
	Customer *peek() const;
	bool isEmpty() const;
	void print() const;
	~Queue();
private:

	struct Node{
		Customer *customer;
		Node *next;
	};

	Node *head, *tail;
	void init();
};

#endif /* QUEUE_H_ */
