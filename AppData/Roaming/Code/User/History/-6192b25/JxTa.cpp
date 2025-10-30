// reagan price ise 211 - lab 4 09/30/2025
#include <iostream> // input/output stream library
#include <stdexcept> // for exception handling
#include <limits> // for limits used in input validation
using namespace std;

// custom exception class for negative numbers (from lab 4 requirements)
class NegativeNumberException : exception {  
    string message;  // member variable to hold error message

public:  // for contructor and what(), otherwise cannot call from main() and compiler would reject both
    // constructor initializes the error message
    NegativeNumberException(const string& msg) : message(msg) {}

    // override what() to return the error message
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// function to safely get an integer from the user
int getInteger(const string& prompt) {
    int value;  // variable to store user input
    while (true) {  // keep asking until valid input is entered
        cout << prompt; // show prompt
        cin >> value; // try to read integer

        if (cin.fail()) { // if input is invalid (non-numeric)
            cin.clear(); // clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid integer." << endl;
        } else { // if input is valid
            return value; // return entered integer
        }
    }
}

int main() {
    while (true) {  // keep looping until successful division
        try {
            // get two integers from the user
            int num1 = getInteger("Enter the first integer: ");
            int num2 = getInteger("Enter the second integer: ");

            // check if first number is negative
            if (num1 < 0) throw NegativeNumberException("First integer cannot be negative!");
            // check if second number is negative
            if (num2 < 0) throw NegativeNumberException("Second integer cannot be negative!");

            // check for division by zero
            if (num2 == 0) throw runtime_error("Division by zero is not allowed!");

            // perform division
            double result = static_cast<double>(num1) / num2;
            cout << "Result: " << result << endl;

            break; // successful run, exit loop

        // handle exceptions here
        } catch (const NegativeNumberException& e) {  
            // handle negative number exception
            cout << "Error: " << e.what() << endl;
        } catch (const runtime_error& e) {  
            // handle division by zero exception
            cout << "Error: " << e.what() << endl;
        }

        // if an exception occurred, ask user to try again (challenge part)
        cout << "Please try again.\n" << endl;
    }

    return 0;  // end program, successful
}
