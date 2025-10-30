// Preprocessor directives
#include <iostream> // 1. Library include
#include <string>  // 1. Library include
//Main function
int main () {      // 2. Program entry point
    // Variable declarations
    std::string name; // 3. Variable
    int age;
    // Input/output statements
    std::getline(cin, name);
    std::cin >> name;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Hello, " << name << "!\n" << "You are " << age << " years old!\n";

    return 0;
}