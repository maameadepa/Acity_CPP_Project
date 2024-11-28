#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>   // For formatting output (fixed, setprecision)
#include <vector>
#include <ctime>     // For working with dates
#include <algorithm>
using namespace std;



int main() {
    // Example code
    cout << "Hello, Library Management System!" << endl;
    return 0;
}


// Book class to store book details
class Book {
private:
    int book_ID;
    string b_title;
    string b_author;
    bool b_status;           // Status of the book (issued or not)

public:
    // Constructor to initialize book details
    Book(int id, string t, string a) : book_ID(id), b_title(t), b_author(a), b_status(false) {}

    // Getters and setters
    int getBookID() const {
    	return book_ID;
	}

    string getTitle(){
	 	return b_title;
	}

    string getAuthor(){
		return b_author;
	}

    bool getStatus(){
		return b_status;
	}

    void setStatus(bool standing) {
		b_status = standing;
	}

    // Display book details
    void displayBook(){
        cout << setw(10) << book_ID << setw(20) << b_title << setw(20) << b_author << setw(10) << (b_status ? "Yes" : "No") << endl;
    }
};






// Member class to store memberbership details
class Member {
private:
    int member_ID;
    string m_name;
    vector<int> borrowedBooks; // List of borrowed book IDs

public:

    Member(int id, string n) : member_ID(id), m_name(n) {}

    // Getters and setters
    int getMemberID() const {
		return member_ID;
	}

    string getName(){
		return m_name;
	}

    vector<int> getBorrowedBooks() const {
		return borrowedBooks;
	}


    // Borrow a book
    void borrowBook(int book_ID) {
        borrowedBooks.push_back(book_ID);
    }   //like adding a book to your personal borrowed list


    // Return a book
   void returnBook(int book_ID) {
    borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), book_ID), borrowedBooks.end());
}
   // bookID from the list when the book is returned


    // Display member details
    void displayMember() {
        cout << setw(10) << member_ID << setw(20) << m_name << setw(20) << borrowedBooks.size() << " books" << endl;
    }   //Shows the member's ID, name, and how many books they've borrowed
};

