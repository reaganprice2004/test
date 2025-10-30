// lab 3 reagan price ise 211 - 09/24/2025
#include <iostream> // input/output stream library
#include <string> // std::string operations
#include <cctype> // have to use for tolower()

using namespace std;

// convert a string to lowercase for case-insensitive comparison
string toLowerCase(const string &str) {
    string lower; // initialize empty string for lowercase version
    for (char c : str) {  // iterate through each character
        lower += tolower(c); // convert character to lowercase and append
    }
    return lower; // return lowercase string
}

// bubble sort function
// sorts array of strings alphabetically (default ascending)
void bubbleSort(string arr[], int n, bool ascending = true) {
    for (int i = 0; i < n - 1; i++) { // outer loop for passes
        for (int j = 0; j < n - i - 1; j++) { // inner loop to compare adjacent elements
            bool condition;
            if (ascending) {
                condition = toLowerCase(arr[j]) > toLowerCase(arr[j + 1]); // compare lowercased strings
            } else {
                condition = toLowerCase(arr[j]) < toLowerCase(arr[j + 1]); // for descending order
            }

            if (condition) {  // if order is wrong, swap
                string temp = arr[j]; // temporary variable for swapping
                arr[j] = arr[j + 1]; // swap elements
                arr[j + 1] = temp;
            }
        }
    }
}

// binary search function (case-insensitive)
int binarySearch(string arr[], int n, const string &target) {
    int left = 0, right = n - 1; // initialize search boundaries
    string targetLower = toLowerCase(target); // convert target to lowercase for comparison

    while (left <= right) { // continue while there is a valid search range
        int mid = left + (right - left) / 2; // compute middle index
        string midLower = toLowerCase(arr[mid]); // lowercase version of middle element

        if (midLower == targetLower) { // found the target
            return mid; // return index
        } else if (midLower < targetLower) { // target is in upper half
            left = mid + 1;
        } else {  // target is in lower half
            right = mid - 1;
        }
    }
    return -1; // target not found
}

// trim leading and trailing spaces from a string
string trim(const string &str) {
    size_t first = str.find_first_not_of(' '); // find first non-space
    if (first == string::npos) return ""; // all spaces
    size_t last = str.find_last_not_of(' '); // find last non-space
    return str.substr(first, last - first + 1); // return trimmed substring
}

int main() {
    int n;

    // prompt user for the number of names
    cout << "Enter the number of names: ";
    cin >> n;
    cin.ignore();   // ignore leftover newline after reading n

    string names[n]; // array to store names

    // input names and demonstrate string operations
    for (int i = 0; i < n; i++) {
        cout << "Enter full name " << i + 1 << ": ";
        string temp;
        getline(cin, temp); // read full name (may include spaces)
        temp = trim(temp); // trim leading/trailing spaces
        names[i] = temp; // store in array

        // demonstrate string operations
        cout << "  Length of name: " << names[i].length() << endl; // length
        size_t spacePos = names[i].find(' '); // find first space
        if (spacePos != string::npos) {
            cout << "  First name segment: " << names[i].substr(0, spacePos) << endl; // substring
        } else {
            cout << "  Name has no spaces." << endl;
        }

        // concatenation 
        if (spacePos != string::npos) {
            string last = names[i].substr(spacePos + 1);
            string first = names[i].substr(0, spacePos);
            cout << "  Concatenated display: " << last << ", " << first << endl;
        }
        cout << endl;
    }

    // ask user for ascending or descending sort
    int sortChoice;
    cout << "Sort order? 1 = Ascending, 2 = Descending: ";
    cin >> sortChoice;
    cin.ignore();  // clear newline
    bool ascending = (sortChoice == 1);

    // sort the names
    bubbleSort(names, n, ascending);

    // display sorted names
    cout << "\nSorted names:\n";
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }

    // challenge: binary search
    string searchName;
    cout << "\nEnter a name to search: ";
    getline(cin, searchName);
    int index = binarySearch(names, n, searchName);
    if (index != -1) {
        cout << "Name found at position " << index << " in index. " << endl;
    } else {
        cout << "Name not found." << endl;
    }

    return 0; // successful completion
}
