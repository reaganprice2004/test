#include <iostream>
using namespace std;
int main() {
    int var = 10;
    int* x = &var;

    cout << "var: " << var << endl;
    cout << "&var: " << &var << endl;
    cout << "x:   " << x << endl;
    cout << "*x:  " << *x << endl;
    cout << "-----------" << endl;

    *x = 20;
    cout << "var: " << var << endl;
    cout << "*x:   " << *x << endl;

    cout << "-------------" << endl;
    int **y = &x;
    cout << "value of y:    " << y << endl;
    cout << "value y points at: " << *y << endl;
    cout << "value of the pointer y is pointing at: " << **y << endl;
    
    return 0;
}