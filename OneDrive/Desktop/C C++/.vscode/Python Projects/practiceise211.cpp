#include <iostream>
using namespace std;

void increment(int* ptr) {
    (*ptr)++;
}

int main() {
    int x = 5;
    increment(&x);
    cout << "x after increment: " << x << endl;
}
