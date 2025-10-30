#include <iostream>
#include <string>
using namespace std;

void fun1() {
    static int x = 0;
    cout << "The value x:" << x << endl;

}

void fun2() {
    int x = 0;
    cout << "The value x:" << x << endl;

}
class Car {
    static int count;

public:
    int id;
    string model;
    Car () {
        id = ++count;
    }
};

int Car::count = 0;
int main() {
    fun1();
    fun2();

    fun1();
    fun2();
}