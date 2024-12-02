#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include <vector>
#include <fstream> // For file handling
using namespace std;

// Library system to manage books, members, and fines
class Library {
private:
    vector<Book> books;      // List of books
    vector<Member> members;  // List of members
    const double fineRate = 0.50; // Fine rate per overdue day

public:
    void addBook();          // Add a book
    void displayBooks();     // Display all books
    void addMember();        // Add a member
    void displayMembers();   // Display all members
    void issueBook();        // Issue a book
    void returnBook();       // Return a book and calculate fine
    void calculateFine();    // Calculate fine based on overdue days
};

#endif
