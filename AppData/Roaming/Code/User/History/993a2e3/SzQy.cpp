#include <iostream>
using namespace std;

void printArray(int a[]) {
    cout << sizeof(a) << endl;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    printArray(arr);
}
