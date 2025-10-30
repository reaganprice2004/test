#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;

    // Ask user for number of names
    cout << "Enter the number of names: ";
    cin >> n;
    cin.ignore(); // Ignore leftover newline

    string names[n];

    // Input names
    for (int i = 0; i < n; i++) {
        cout << "Enter name " << i+1 << ": ";
        getline(cin, names[i]);
    }

    // Simple bubble sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (names[j] > names[j+1]) {
                // Swap names[j] and names[j+1]
                string temp = names[j];
                names[j] = names[j+1];
                names[j+1] = temp;
            }
        }
    }

    // Print sorted names
    cout << "\nNames in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }

    return 0;
}
