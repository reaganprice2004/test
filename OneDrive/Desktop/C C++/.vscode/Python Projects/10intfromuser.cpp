#include <iostream> // include standard input/output library for cin and cout
using namespace std; // use the standard namespace so we don’t need std:: prefix

// main function: program execution starts here
int main() {
    int arr[10]; // declare an array to hold 10 integers
    int sum = 0; // variable to store the sum of all integers
    int maxVal; // variable to store the maximum value
    double avg; // variable to store the average value

    // prompt user to enter 10 integers
    cout << "Enter 10 integers:" << endl;
    for (int i = 0; i < 10; i++) { // loop through indices 0 to 9
        cin >> arr[i]; // input each integer into the array
        sum += arr[i]; // add each entered integer to the sum

        if (i == 0 || arr[i] > maxVal) { 
            // if it’s the first element OR the current element is greater than current max
            maxVal = arr[i]; // initialize or update the max value
        }
    }

    // calculate average (cast sum to double to avoid integer division)
    avg = static_cast<double>(sum) / 10; // ensure decimal result if needed

    // display the results
    cout << "Sum = " << sum << endl; // print sum of integers
    cout << "Average = " << avg << endl; // print average value
    cout << "Max value = " << maxVal << endl; // print maximum value

    return 0; // return 0 to indicate successful program execution
}

