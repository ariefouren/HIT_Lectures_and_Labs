#include <iostream>
#include <cmath>
#include "Queue.h" 

int main() {
    // Part 1: Queue of integers with first 10 Fibonacci numbers
    Queue<int> intQueue;
    int fib[10] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };

    for (int i = 0; i < 10; ++i) {
        intQueue.enqueue(fib[i]);
    }

    std::cout << "Queue of Fibonacci numbers: " << intQueue << std::endl;

    // Part 2: Queue of doubles with e^x values
    Queue<double> doubleQueue;

    for (double x = 1.0; x < 10.0; x += 1.0) {
        doubleQueue.enqueue(std::exp(x));
    }

    std::cout << "Queue of e^x values: " << doubleQueue << std::endl;

    // Part 3: Queue of strings with famous computer scientists' names
    Queue<std::string> stringQueue;
    std::string scientists[] = {
        "Alan Turing", "Ada Lovelace", "Grace Hopper", 
        "Donald Knuth", "Tim Berners-Lee",
        "Bjarne Stroustrup" 
    };

    for (const std::string& scientist : scientists) {
        stringQueue.enqueue(scientist);
    }

    std::cout << "Queue of Computer Scientist Names: " << stringQueue << std::endl;
    std::cout << "Dequeuing from Queue of Computer Scientist Names: \n";
    while (!stringQueue.isEmpty())
    {
        std::cout << stringQueue.dequeue() << std::endl;
    }
    std::cout << "Queue of Computer Scientist Names: " << stringQueue << std::endl;

    return 0;
}

