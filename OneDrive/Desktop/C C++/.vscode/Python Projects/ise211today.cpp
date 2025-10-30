#include <iostream>

using namespace std;

int factorial (int n) {
    if (n==0) {
        return 1;
    }
    else {
        return n * factorial(n-2);
    }
}

int main()
{
    int n = 5;
    cout << "Factorial of" << n << "is: " << factorial(n) << endl;
    return 0;
}