#pragma once
#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& item) : data(item), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    ~Queue() {
        deleteAllElements();
    }

    void enqueue(const T& item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return T();
        }

        T element = head->data;
        Node* temp = head;
        
        head = head->next;
        delete temp;
        return element; 
    }

    T peek() const {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot peek." << std::endl;
            return T();
        }
        return head->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void deleteAllElements() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
        Node* current = queue.head;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};


