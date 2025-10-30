// reagan price ise 211 - lab 4 09/30/2025
#include <iostream> // input/output stream library
#include <stdexcept> // for exception handling
#include <limits> // for limits used in input validation
using namespace std;
// bc using constructor for NegativeNumberException, have to use public or compiler gives error

// custom exception class for negative numbers: NegativeNumberException
class NegativeNumberException : exception {  
    string message;  // member var to hold error message

public:  // for contructor and what(), otherwise cannot call from main() and compiler would reject both
    // constructor initializes error message
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
        cout << prompt; // display prompt
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
            // only need num2 b/c dividing by second integer only (divide by zero undef)
            if (num2 == 0) throw runtime_error("Division by zero is not allowed!");

            // perform division and print result
            double result = static_cast<double>(num1) / num2;
            cout << "Result: " << result << endl;

            break; // successful run, exit loop

        // catch (for throw) here from above (for negative num and division by zero)
        } catch (const NegativeNumberException& e) {  
            // handle negative number exception
            cout << "Error: " << e.what() << endl;
        } catch (const runtime_error& e) { 
            // handle division by zero exception
            cout << "Error: " << e.what() << endl;
        }

        // if exception occurred, ask user to try again (loop starts again)
        cout << "Please try again.\n" << endl;
    }

    return 0;  // end program, successful completion
}
