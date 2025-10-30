#include <iostream>  // Include input/output stream library
#include <string>  // Include string library for string handling
#include <cctype>  // Include ctype library for character checks (isalpha)

using namespace std; // Use the standard namespace

// Function to check if the name contains only alphabetic characters
bool isValidName(const string& str) {
    for (char c : str) {  // Loop through each character in the string
        if (!isalpha(static_cast<unsigned char>(c))) {  // Check if character is NOT an alphabet
            return false; // Return false if any non-alphabet character found
        }
    }
    return true; // Return true if all characters are alphabets
}

int main() {
    string name;  // Declare a variable to store the user's name
    int age;  // Declare a variable to store the user's age

    do {  // Start do-while loop to repeatedly ask for name
        cout << "Enter your name (alphabets only): ";  // Prompt user to enter their name
        getline(cin, name);   // Read entire line as the name input
        if (!isValidName(name)) { // Check if the name is invalid
            cout << "Invalid input. Please enter a name with alphabets only.\n"; // Show error message
        }
    } while (!isValidName(name));  // Continue loop until name is valid

    cout << "Enter your age: ";  // Prompt user to enter their age
    cin >> age;  // Read age input

    cout << "Hello, " << name << "! You are " << age << " years old." << endl; // Print personalized greeting

    return 0; // Return 0 to indicate successful execution
}
