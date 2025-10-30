#include <iostream>

// Global variable declaration
int globalVar = 10;

void exampleFunction() {
    // Local variable declaration
    int localVar = 5;
    
    // Static variable declaration
    static int staticVar = 0;

    // Modify the variables
    localVar++;
    staticVar++;
    globalVar++;

    // Output the values of the variables
    std::cout << "Inside exampleFunction()" << std::endl;
    std::cout << "Local Variable: " << localVar << std::endl;
    std::cout << "Static Variable: " << staticVar << std::endl;
    std::cout << "Global Variable: " << globalVar << std::endl;
    std::cout << "-----------------------" << std::endl;
}

int main() {
    std::cout << "First function call:" << std::endl;
    exampleFunction();
    
    std::cout << "Second function call:" << std::endl;
    exampleFunction();
    
    std::cout << "Third function call:" << std::endl;
    exampleFunction();

    //std::cout << "Static from the main fun: " << staticVar << std::endl;

    // Main function scope
    int mainVar = 100;
    std::cout << "Inside main() - Outer scope" << std::endl;
    std::cout << "mainVar: " << mainVar << std::endl;

    {
        // Nested scope inside main
        int mainVar = 200;  // This is a different mainVar, local to this block
        std::cout << "Inside main() - Inner scope" << std::endl;
        std::cout << "mainVar: " << mainVar << std::endl;

        // Modifying global variable within this scope
        globalVar++;
        std::cout << "Global Variable inside inner scope: " << globalVar << std::endl;
    }

    std::cout << "Back to main() - Outer scope" << std::endl;
    std::cout << "mainVar: " << mainVar << std::endl;
    std::cout << "Global Variable after inner scope: " << globalVar << std::endl;

    return 0;
}
