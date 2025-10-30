#include <iostream>
using namespace std;

int main() {
    int arr[10]; // array to hold 10 integers
    int sum = 0; // variable for sum
    int maxVal; // variable for max
    double avg; // variable for average - double since

    // input 10 integers
    cout << "Enter 10 integers:" << endl;
    for (int i=0; i<10; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (i == 0 || arr[i] > maxVal) {
            maxVal = arr[i]; // initialize or update max
        }
    }

    // calculate average
    avg = static_cast<double>(sum) / 10; // using static_cast to make easier

    // output results
    cout << "Sum = " << sum << endl;
    cout << "Average = " << avg << endl;
    cout << "Max value = " << maxVal << endl;

    return 0;
}
