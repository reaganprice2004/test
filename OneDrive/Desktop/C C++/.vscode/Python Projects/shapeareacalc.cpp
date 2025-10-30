#include <iostream> // input/output libraru
#include <cmath> // for m_pi (value of pi)

using namespace std;// so we don't have to write std:: before cout, cin, etc

int main() {
    int choice; // store user menu choice
    float area = 0; // store calculated area

    do { // loop until user chooses to exit
        // display menu
        cout << "\n=== Shape Area Calculator ===\n";
        cout << "1. Area of Circle\n";
        cout << "2. Area of Rectangle\n";
        cout << "3. Area of Triangle\n";
        cout << "4. Area of Square\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;  // get user's choice

        switch (choice) {
            case 1: { // if user chooses circle:
                float radius; // variable for radius
                cout << "Enter radius of circle: ";
                cin >> radius;  // input radius
                area = M_PI * radius * radius; // area = πr²
                cout << "Area of Circle: " << area << endl;
                break; // exit this case
            }

            case 2: { // if user chooses rectangle
                float length, breadth; // variables for length and breadth
                cout << "Enter length and breadth of rectangle: ";
                cin >> length >> breadth; // input values
                area = length * breadth; // area = length × breadth
                cout << "Area of Rectangle: " << area << endl;
                break; // exit this case
            }

            case 3: { // if user chooses triangle
                float base, height; // variables for base and height
                cout << "Enter base and height of triangle: ";
                cin >> base >> height; // input values
                area = 0.5 * base * height; // area = ½ × base × height
                cout << "Area of Triangle: " << area << endl;
                break; // exit this case
            }

            case 4: {   // if user chooses square
                float side; // variable for side
                cout << "Enter side of square: ";
                cin >> side; // input side
                area = side * side; // area = side²
                cout << "Area of Square: " << area << endl;
                break; // exit this case
            }

            case 5: // if user chooses to exit
                cout << "Exiting program. Goodbye!" << endl;
                break; // exit switch

            default: // if user enters invalid choice
                cout << "Invalid choice. Please enter a number from 1 to 5.\n";
        }

    } while (choice != 5); // repeat loop until user chooses 5

    return 0; // end of program, successful
}
