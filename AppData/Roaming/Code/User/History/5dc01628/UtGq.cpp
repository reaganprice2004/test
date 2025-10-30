// ise 211 reagan price lab 5 10/07/2025
#include <iostream>  // input/output library
using namespace std; // standard namespace

// function takes a pointer to an integer array and its size
// returns sum of all elements in the array
int sumArray(int* arr, int size) {
    int sum = 0; // initialize sum to 0
    for (int i = 0; i < size; i++) { // loop through each element
        sum += *(arr + i); // add value pointed to by (arr + i) to sum
    }
    return sum; // return final sum
}

int main() {
    // basic pointer operations
    int num = 25; // declare an integer variable/initialize to 25
    int* ptr = &num; // declare pointer to int and assign it the address of num

    cout << "--- Pointer Basics ---" << endl; // display header
    cout << "Variable value: " << num << endl; // display value of num
    cout << "Variable address: " << &num << endl; // display address of num
    cout << "Pointer value (stored value in ptr): " << ptr << endl; // display address stored in ptr
    cout << "Value pointed to by pointer: " << *ptr << endl;  // display value pointed to by ptr

    // dynamic array using pointers
    int size; // declare variable to store array size
    cout << "\nEnter array size: "; // prompt user for size of array
    cin >> size; // read size from user

    int* arr = new int[size]; // allocate array of ints

    cout << "Enter " << size << " integer values:" << endl; // prompt user to fill array
    for (int i = 0; i < size; i++) {  // loop through each array index
        cin >> *(arr + i); // read value into array using pointer arithmetic
    }

    cout << "\nArray values: "; // print header for array values
    for (int i = 0; i < size; i++) { // loop through each array element
        cout << *(arr + i) << " ";  // print value using pointer arithmetic
    }
    cout << endl; // move to next line after printing array

    int total = sumArray(arr, size); // call sumArray function to get sum of elements
    cout << "Sum of array elements: " << total << endl; // display sum

    delete[] arr; // free dynamically allocated memory

    return 0; // return 0, successful program terminated
}
