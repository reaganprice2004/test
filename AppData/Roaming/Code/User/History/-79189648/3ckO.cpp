#include <iostream>
#include <string>

int main () {

    std::string name;
    int age;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Hello, " << name << "!\n";

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "You are " << age << " years old!\n";

    return 0;
}