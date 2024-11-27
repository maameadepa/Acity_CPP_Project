#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//Book Class
class Book {
public:
    string title;
    string author;
    bool isAvailable;

    Book( string t, string a ) : title(t), author(a), isAvailable(true) {}

    void displayBook() const {
        cout << "Title: " << title << ", Author: " << author
             << ", Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};