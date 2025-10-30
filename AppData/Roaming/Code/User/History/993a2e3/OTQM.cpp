#include <iostream>
#include <string>

using namespace std;
int main()
{
    int age = 20;
    float temperature = 98.7;
    double balance = 630000.33;
    char grade = 'A';
    bool isValid = true;
    string name = "Reagan";

    cout << "My age: " << age
         << "My room temp: " << temperature
         << "My account dollar amount: " << balance
         << "Is valid account: " << isValid
         << "My name: " << name << endl;

    int x = 400000000000000000;
    cout << "Value of X: " << x << endl;
    return 0;
}