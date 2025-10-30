// ise 211 reagan price - 09/25/2025

#include <iostream>
#include <stdexcept>
#include <limits>

int main() {
    double a, b;
    char op;

    std::cout << "Enter first number: ";
    if (!(std::cin >> a)) {
        std::cout << "invalid number" << std::endl;
        return 1;
    }

    std::cout << "Enter second number: ";
    if (!(std::cin >> b)) {
        std::cout << "invalid number" << std::endl;
        return 1;
    }

    std::cout << "Choose operation (+,-,*,/): ";
    std::cin >> op;

    try {
        double result;
        switch (op) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/':
                if (b == 0) {
                    throw std::runtime_error("division by zero");
                }
                result = a / b;
                break;
            default:
                throw std::invalid_argument("unknown operation!");
        }
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

