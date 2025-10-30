// ise 211 reagan price lab 07: 10/16/2025
#include <iostream> // input/output stream library
#include <string> // string library
using namespace std;// standard namespace

// define class Book
class Book {
private:
    string title; // title of book variable (private)
    string author; // author of book variable (private)
    int year; // publication year variable (private)
    double price; // price of book variable (private)

public:
    // default constructor - empty for parameterized constructor
    Book() {
        title = "Untitled"; // set default title
        author = "Unknown"; // set default author
        year = 0; // default year
        price = 0.0; // default price
        cout << "Default constructor called." << endl; // observe constructor call
    }

    // parameterized constructor
    Book(string t, string a, int y, double p) {
        title = t; // initialize title
        author = a; // initialize author
        year = y; // initialize year
        price = p; // initialize price
        cout << "Parameterized constructor called." << endl; // observe constructor call
    }

    // challenge - overloaded constructor (ititializes only title and author)
    Book(string t, string a) {
        title = t; // initialize title
        author = a; // initialize author
        year = 0; // default year
        price = 0.0; // default price
        cout << "Overloaded constructor called." << endl;
    }

    // destructor
    ~Book() {
        cout << "Book object destroyed." << endl; // print message when destructor runs (indicates successful run)
    }

    // setter methods (group together similar to lab 06)
    void setTitle(string t) {
        title = t;
    }

    void setAuthor(string a) {
        author = a;
    }

    void setYear(int y) {
        year = y;
    }

    void setPrice(double p) {
        price = p;
    }

    // getter methods (group together similar to lab 06)
    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    int getYear() {
        return year;
    }

    double getPrice() {
        return price;
    }

    // display book information
    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
        cout << "------------------------" << endl;
    }
};

// main function
int main() {
    // create first Book object using default constructor
    Book book1; // default constructor runs automatically
    cout << endl;

    // modify fields using setter methods
    book1.setTitle("Frankenstein");
    book1.setAuthor("Mary Shelley");
    book1.setYear(1818);
    book1.setPrice(15.99);

    // display book1 details
    cout << "Book 1 Details:" << endl;
    book1.displayInfo();

    // create second Book object using parameterized constructor
    Book book2("Fahrenheit 451", "Ray Bradbury", 1953, 12.99);
    cout << endl;

    // display book2 details
    cout << "Book 2 Details:" << endl;
    book2.displayInfo();

    // create third Book object using overloaded constructor (title & author only)
    Book book3("Lord of the Rings", "J.R.R. Tolkien", 1954, 14.99);
    cout << endl;

    // display book3 details
    cout << "Book 3 Details:" << endl;
    book3.displayInfo();

    cout << "End of program reached." << endl;

    return 0; // destructors automatically run, successful completion
}
