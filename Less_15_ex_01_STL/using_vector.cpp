#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Step 1: Define vector<int> numbers, initially empty
    vector<int> numbers;

    // Print the size and capacity of the vector "numbers"
    cout << "Size of numbers: " << numbers.size() << endl;
    cout << "Capacity of numbers: " << numbers.capacity() << endl;

    // Step 2: Add 5 integers 1..5 to vector "numbers" using push_back()
    for (int i = 1; i <= 5; ++i) {
        numbers.push_back(i);
    }

    // Print the size and capacity of the vector "numbers" after adding elements
    cout << "Size of numbers: " << numbers.size() << endl;
    cout << "Capacity of numbers: " << numbers.capacity() << endl;

    // Print elements using iterator after adding
    cout << "Elements in numbers after adding:";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;

    // Step 3: Compute and print the product of elements in "numbers" using a for loop and vector<int>::iterator
    int product1 = 1;
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        product1 *= *it;
    }
    cout << "Product of elements using iterator: " << product1 << endl;

    // Print elements using iterator in step 3
    cout << "Elements in numbers in step 3:";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;

    // Step 4: Compute and print the product of elements in "numbers" using a for loop and vector<int>::reverse_iterator
    int product2 = 1;
    for (vector<int>::reverse_iterator rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        product2 *= *rit;
    }
    cout << "Product of elements using reverse iterator: " << product2 << endl;

    // Print elements using iterator in step 4
    cout << "Elements in numbers in step 4:";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;

    return 0;
}
