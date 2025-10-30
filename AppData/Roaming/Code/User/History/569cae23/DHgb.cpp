#include <iostream>  // include input/output stream library
#include <string>  // include string library for string handling
#include <cctype>  // include ctype library for character checks (isalpha)

using namespace std; // use standard namespace

// check if name contains alphabetic characters or not
bool isValidName(const string& str) {
    for (char c : str) {  // loop through each individual string character
        if (!isalpha(static_cast<unsigned char>(c))) {  // check if character is not an alphabet
            return false; // return false if non-alphabet character is found
        }
    }
    return true; // return true if all characters are alphabets
}

int main() {
    string name;  // variable declared to store user's name
    int age;  // variable declared to store user's age

    do {  // do-while loop to repeatedly ask for name
        cout << "Enter your name (alphabets only): ";  // prompt user to enter their name
        getline(cin, name);   // read entire line as name input - now last names are included
        if (!isValidName(name)) { // check to make sure name is valid
            cout << "Invalid input. Please enter a name with alphabets only.\n"; // show error message
        }
    } while (!isValidName(name));  // continue this loop until name only contains alphabetics

    cout << "Enter your age: ";  // prompt user to enter age
    cin >> age;  // read age input

    cout << "Hello, " << name << "! You are " << age << " years old!" << endl; // print personal greeting

    return 0; // return 0 - successful
}
