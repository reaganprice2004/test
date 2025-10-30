// lab 2 reagan price ise 211 - 09/04/2025
#include <iostream> // includes the input/output stream library
#include <cmath>    // includes cmath for mathematical functions
#include <limits>   // includes limits for input validation with cin
using namespace std; // allows use of standard library objects without std:: prefix

int main() { // start of the main function
    
    const int MAX_HISTORY = 5; // maximum number of results to store in history
    double history[MAX_HISTORY]; // array to store result history
    int historySize = 0; // keeps track of how many results are currently stored
    bool running = true; // flag to control whether the program keeps running

    while (running) { // loop that runs until user chooses to exit

        // display the calculator menu to the user
        cout << "\n===== Simple Calculator Menu =====" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Modulo (%)" << endl;
        cout << "6. Power (a^b)" << endl;
        cout << "7. Show Result History" << endl;
        cout << "8. Exit" << endl;
        cout << "9. Undo Last Operation" << endl;
        cout << "Select an operation (1-9): ";

        int choice; // variable to store the user's menu choice
        cin >> choice; // read user's input

        // check if input failed (e.g., user typed a letter instead of a number)
        if (cin.fail()) {
            cin.clear(); // clear the error state of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input from buffer
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            continue; // skip to next iteration of loop
        }

        double a, b, result; // variables to store operands and result

        switch (choice) {  // Use switch to handle each menu option
            case 1: // case for addition
                cout << "Enter two numbers to add: ";
                cin >> a >> b; // read two numbers
                result = a + b; // perform addition
                cout << "Result: " << result << endl;
                break; // exit switch

            case 2: // case for subtraction
                cout << "Enter two numbers to subtract: ";
                cin >> a >> b; // read two numbers
                result = a - b; // perform subtraction
                cout << "Result: " << result << endl;
                break; // exit switch

            case 3: // case for multiplicatio
                cout << "Enter two numbers to multiply: ";
                cin >> a >> b; // read two numbers
                result = a * b; // perform multiplication
                cout << "Result: " << result << endl;
                break; // exit switch

            case 4: // case for division
                cout << "Enter two numbers to divide: ";
                cin >> a >> b; // read two numbers
                if (b == 0) { // check for division by zero
                    cout << "Error: Division by zero is not allowed!" << endl; // tell user division by zero not allowed
                    continue; // skip and restart loop
                }
                result = a / b; // once cleared check, perform division
                cout << "Result: " << result << endl;
                break; // exit switch

            case 5: // case for modulo
                cout << "Enter two integers to apply modulo: ";
                cin >> a >> b; // read two numbers - cast to int since cannot take float
                if (b == 0) { // check for modulo by zero (same as division)
                    cout << "Error: Modulo by zero is not allowed!" << endl; // tell user modulo by zero not allowed
                    continue; // skip and restard loop
                }
                result = static_cast<int>(a) % static_cast<int>(b); // once cleared check, perform modulo
                cout << "Result: " << result << endl; 
                break; // exit switch

            case 6: // case for power
                cout << "Enter base and exponent: ";
                cin >> a >> b; // read base and exponent
                result = pow(a, b); // use pow() for exponents, why we needed #include <limits>
                cout << "Result: " << result << endl;
                break; // exit switch

            case 7: // case to show result history
                if (historySize == 0) { // if no history exists
                    cout << "No history to show." << endl; // tell user no history to show
                } else { // if history exists
                    cout << "Last " << historySize << " result(s): ";
                    for (int i = 0; i < historySize; i++) { // loop through stored results
                        cout << history[i]; // display result to user
                        if (i < historySize - 1) cout << ", "; // add comma if not last result
                    }
                    cout << endl; // newline after history output
                }
                continue; // skip saving result and show menu again

            case 8: // case to exit program
                cout << "Exiting calculator. Thank you and Goodbye!" << endl;
                running = false; // set flag to false to break while loop
                continue; // skip rest and exit

            case 9: // case to undo last operation
                if (historySize == 0) { // if no history exists
                    cout << "Nothing to undo!" << endl; // tell user there is nothing to undo
                } else { // if there is something to undo
                    historySize--; // decrease history size to "remove" last result
                    cout << "Last operation undone." << endl;
                    if (historySize > 0) {
                        cout << "Restored result: " << history[historySize - 1] << endl; // show previous result
                    } else { // else
                        cout << "No previous result to restore." << endl; // if no results left
                    }
                }
                continue; // skip saving and show menu again

            default: // if the user entered an invalid option
                cout << "Invalid choice. Please select a number from 1 to 9." << endl; // tell user invalid choice
                continue; // re-prompt user
        }

        // save result to history only if a valid operation (cases 1-6) was performed
        if (choice >= 1 && choice <= 6) { // if between case 1-6
            if (historySize < MAX_HISTORY) {
                history[historySize] = result; // append new result
                historySize++; // increase history size
            } else {
                // shift all results left to make room for new one
                for (int i = 1; i < MAX_HISTORY; i++) {
                    history[i - 1] = history[i]; // shift each result left
                }
                history[MAX_HISTORY - 1] = result; // add new result at the end, "saving" to history
            }
        }
    }

    return 0; // return 0, successful completion
}
