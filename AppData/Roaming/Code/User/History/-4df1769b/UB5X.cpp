// ise 211 reagan price lab 08 10/28/2025
#include <iostream> // input/output standard library
#include <string> // for using string
using namespace std;  // use standard namespace

// base class Vehicle
class Vehicle {
protected: // protected so derived classes can access (Car and Bike)
    string brand; // vehicle brand
    string model; // vehicle model
    int year; // vehicle year
public:
    // constructor, initializes base attributes
    Vehicle(string b, string m, int y) : brand(b), model(m), year(y) {}

    // virtual function to display vehicle details
    virtual void displayDetails() {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
    }
};

// derived class Car
class Car : public Vehicle {
private:
    int doors; // additional attribute specific to Car
public:
    // constructor, calls original base class constructor
    // why you see functions from base class Vehicle (initialized attributes)
    Car(string b, string m, int y, int d) : Vehicle(b, m, y), doors(d) {}

    // override the displayDetails() method
    void displayDetails() override {
        cout << "Car Brand: " << brand << ", Model: " << model
             << ", Year: " << year << ", Doors: " << doors << endl;
    }
};

// derived class Bike (why we needed protected above)
class Bike : public Vehicle {
private:
    string brakeType; // additional attribute specific to Bike (not needed for Car)
public:
    // constructor, calls base class constructor
    // functions again from base class Vehicle (initialized attributes), added brakeType for Bike class
    Bike(string b, string m, int y, string bt) : Vehicle(b, m, y), brakeType(bt) {}

    // override the displayDetails() method
    void displayDetails() override {
        cout << "Bike Brand: " << brand << ", Model: " << model
             << ", Year: " << year << ", Brake Type: " << brakeType << endl;
    }
};

int main() {
    // create Car and Bike objects using pointers to base class
    Vehicle* v1 = new Car("Toyota", "Camry", 2020, 4);
    Vehicle* v2 = new Bike("Yamaha", "R1", 2021, "Disc");

    // call displayDetails() polymorphically
    v1->displayDetails();
    v2->displayDetails();

    // free allocated memory (needed so can rerun and not be saved in the memory)
    delete v1;
    delete v2;

    return 0;  // end program, successful completion
}
