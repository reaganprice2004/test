#include <iostream>
#include <stdexcept>
#include <cmath>

double calculate_sqrt(double value) {
    if (value < 0) {
        throw std::domain_error("Negative value provided to sqrt!");
    }
    return std::sqrt(value);
}

int main() {
    try {
        std::cout << calculate_sqrt(-5) << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}