#include <iostream>   // for input and output
#include <string>     // for using string data type
using namespace std;

// bubbleSort: sorts an array of strings alphabetically using Bubble Sort algorithm
void bubbleSort(string arr[], int n) {
    // outer loop runs n-1 times (number of passes)
    for (int i = 0; i < n - 1; i++) {
        // inner loop compares adjacent elements in the array
        for (int j = 0; j < n - i - 1; j++) {
            // if current element is alphabetically greater than the next, swap them
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j]; // temporarily store arr[j]
                arr[j] = arr[j + 1]; // move arr[j+1] into arr[j]
                arr[j + 1] = temp; // move temp into arr[j+1]
            }
        }
    }
}
// main function
int main() {
    int n; // variable to hold number of names

    cout << "Enter the number of names: "; // ask user for count
    cin >> n; // read user input for number of names
    cin.ignore(); // clear leftover newline character from input buffer

    string names[100]; // array to hold names (limit: 100)

    cout << "Enter " << n << " names:" << endl; // prompt user to enter names
    for (int i = 0; i < n; i++) {
        getline(cin, names[i]); // read each full line as a string (names can have spaces)
    }

    // call bubbleSort to arrange names alphabetically
    bubbleSort(names, n);

    // display sorted list of names
    cout << "\nNames in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl; // print each name
    }

    return 0; // end program, successful completion
}
