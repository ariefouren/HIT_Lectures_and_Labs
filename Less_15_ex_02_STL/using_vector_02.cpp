#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Step 1: Create vector numbers1 with values {1,..., 10}
    vector<int> numbers1(10);
    for (int i = 1; i <= 10; ++i) {
        numbers1[i - 1] = i;
    }

    // Print elements, size, and capacity of numbers1
    cout << "Elements of numbers1: ";
    for (int num : numbers1) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Size of numbers1: " << numbers1.size() << endl;
    cout << "Capacity of numbers1: " << numbers1.capacity() << endl;

    // Step 2: Create vector numbers2 with values {1,..., 20}
    vector<int> numbers2(20);
    for (int i = 1; i <= 20; ++i) {
        numbers2[i - 1] = i;
    }

    // Print elements, size, and capacity of numbers2
    cout << "Elements of numbers2: ";
    for (int num : numbers2) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Size of numbers2: " << numbers2.size() << endl;
    cout << "Capacity of numbers2: " << numbers2.capacity() << endl;

    // Step 3: Set numbers1[5] equal to 0 using []
    numbers1[5] = 0;

    // Step 4: Set numbers1[5] equal to 0 using at()
    numbers1.at(5) = 0;

    // Step 5: Insert 0 to numbers1 at index 7 using insert()
    numbers1.insert(numbers1.begin() + 7, 0);

    // Print elements, size, and capacity of numbers1 after modifications
    cout << "Elements of numbers1 after modifications: ";
    for (int num : numbers1) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Size of numbers1: " << numbers1.size() << endl;
    cout << "Capacity of numbers1: " << numbers1.capacity() << endl;

    // Step 7: Try to insert 0 at position 2000 using at(), catch exception
    try {
        numbers1.at(2000) = 0;
    }
    catch (const out_of_range& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    // Step 8: Erase the 1st element of numbers1 using erase()
    numbers1.erase(numbers1.begin());

    // Step 9: Print elements, size, and capacity of numbers1 after erasing
    cout << "Elements of numbers1 after erasing: ";
    for (int num : numbers1) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Size of numbers1: " << numbers1.size() << endl;
    cout << "Capacity of numbers1: " << numbers1.capacity() << endl;

    // Step 10: Erase all elements of numbers1 using erase() and iterator
    numbers1.erase(numbers1.begin(), numbers1.end());

    // Step 11: Insert elements from numbers2 to numbers1 using insert()
    numbers1.insert(numbers1.begin(), numbers2.begin(), numbers2.end());

    // Step 12: Clear numbers1 using clear()
    numbers1.clear();

    // Print elements, size, and capacity of numbers1 after clearing
    cout << "Elements of numbers1 after clearing: ";
    for (int num : numbers1) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Size of numbers1: " << numbers1.size() << endl;
    cout << "Capacity of numbers1: " << numbers1.capacity() << endl;

    return 0;
}
