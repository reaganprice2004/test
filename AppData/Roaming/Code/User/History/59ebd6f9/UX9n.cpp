// ise 211 reagan price lab 06: 10/14/2025
#include <iostream>   // input/output stream library
#include <string>     // string library
using namespace std;  // standard namespace

// define class Book
class Book {
private:
    string title; // title of book variable (private)
    string author; // author of book variable (private)
    int year; // publication year variable (private)
    double price; // price of book variable (private)

public:
    // using setter method to set book title
    void setTitle(string t) {
        title = t;  // assign given title to private title variable
    }

    // using setter method to set the book author
    void setAuthor(string a) {
        author = a; // assign given author to private author variable
    }

    // using setter method to set book publication year
    void setYear(int y) {
        year = y;   // assign given year to private publication year variable
    }

    // using setter method to set book price
    void setPrice(double p) {
        price = p;  // assign the given price to the private book price variable
    }

    // uisng getter method to return book title
    string getTitle() {
        return title; // return book title
    }

    // using getter method to return book author
    string getAuthor() {
        return author; // return book author
    }

    // using getter method to return publication year
    int getYear() {
        return year; // return publication year
    }

    // using getter method to return book price
    double getPrice() {
        return price; // return book price
    }

    // display all book info neatly
    void displayInfo() {
        cout << "Title: " << title << endl;   // print book title
        cout << "Author: " << author << endl; // print book author
        cout << "Year: " << year << endl;     // print publication year
        cout << "Price: $" << price << endl;  // print price
        cout << "------------------------" << endl; // separator line between for better readability
    }
};

int main() { // main function
    Book book1, book2; // create two Book objects

    // set values for first book - the great gatsby
    book1.setTitle("Frankenstein"); // set title
    book1.setAuthor("Mary Shelley"); // set author
    book1.setYear(1818); // set year
    book1.setPrice(15.99); // set price

    // set values for the second book
    book2.setTitle("Fahrenheit 451"); // set title
    book2.setAuthor("Ray Bradbury"); // set author
    book2.setYear(1953); // set year
    book2.setPrice(12.99); // set price

    // display details for the first book
    cout << "Book 1 Details:" << endl; // print heading
    book1.displayInfo(); // call method to display info

    // display details for the second book
    cout << "Book 2 Details:" << endl; // print heading
    book2.displayInfo(); // call method to display info

    return 0; // end program, successful completion
}
