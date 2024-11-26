#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>  // Include this header for numeric_limits

using namespace std;

// Book Class
class Book {
private:
    string title;
    string author;
    int id;
    bool isAvailable; // true if available, false if borrowed
public:
    Book(string t, string a, int i) {
        title = t;
        author = a;
        id = i;
        isAvailable = true;
    }

    // Getters and Setters
    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getId() { return id; }
    bool getAvailability() { return isAvailable; }
    void setAvailability(bool availability) { isAvailable = availability; }

    void displayBook() {
        cout << setw(5) << id << setw(20) << title << setw(20) << author
             << setw(20) << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};

// Base Member Class
class Member {
protected:
    string name;
    int memberId;
public:
    Member(string n, int id) : name(n), memberId(id) {}
    virtual void displayMember() {
        cout << setw(5) << memberId << setw(20) << name << endl;
    }

    void displayMemberToFile(ofstream &file) {
        file << setw(5) << memberId << setw(20) << name << endl;
    }
};

// Derived Classes
class StudentMember : public Member {
public:
    StudentMember(string n, int id) : Member(n, id) {}
};

class TeacherMember : public Member {
public:
    TeacherMember(string n, int id) : Member(n, id) {}
};

// Library Management System
class Library {
private:
    vector<Book> books;
    vector<Member*> members;
public:
    // Add a Book
    void addBook(string title, string author, int id) {
        books.push_back(Book(title, author, id));
    }

    // Add a Member
    void addMember(Member* member) {
        members.push_back(member);
    }

    // Display Books
    void displayBooks() {
        cout << "Books in Library:\n";
        cout << setw(5) << "ID" << setw(20) << "Title" << setw(20) << "Author" << setw(20) << "Status" << endl;
        for (auto &book : books)
            book.displayBook();
    }

    // Display Members
    void displayMembers() {
        cout << "Library Members:\n";
        cout << setw(5) << "ID" << setw(20) << "Name" << endl;
        for (auto &member : members)
            member->displayMember();
    }

    // Borrow a Book
    void borrowBook(int bookId) {
        for (auto &book : books) {
            if (book.getId() == bookId) {
                if (book.getAvailability()) {
                    book.setAvailability(false);
                    cout << "Book borrowed successfully.\n";
                    return;
                } else {
                    cout << "Book already borrowed.\n";
                    return;
                }
            }
        }
        cout << "Book not found.\n";
    }

    // Return a Book
    void returnBook(int bookId) {
        for (auto &book : books) {
            if (book.getId() == bookId) {
                if (!book.getAvailability()) {
                    book.setAvailability(true);
                    cout << "Book returned successfully.\n";
                    return;
                } else {
                    cout << "Book is not borrowed.\n";
                    return;
                }
            }
        }
        cout << "Book not found.\n";
    }

    // Delete a Book
    void deleteBook(int bookId) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == bookId) {
                books.erase(it);
                cout << "Book deleted successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

void saveToFile() {
    // Open file in append mode to keep adding data without overwriting
    ofstream file("Library_data.txt", ios::app);  // Open file in append mode
    if (!file) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    // Saving all output to the file
    streambuf* originalBuffer = cout.rdbuf();  // Save the original buffer
    cout.rdbuf(file.rdbuf());  // Redirect cout to the file

    // Display Books in Library
    cout << "\nBooks in Library:\n";
    cout << setw(5) << "ID" << setw(20) << "Title" << setw(20) << "Author" << setw(20) << "Status" << endl;
    for (auto &book : books)
        book.displayBook();

    // Display Library Members
    cout << "\nLibrary Members:\n";
    cout << setw(5) << "ID" << setw(20) << "Name" << endl;
    for (auto &member : members)
        member->displayMember();

    // Restore the original cout buffer
    cout.rdbuf(originalBuffer);

    file.close();  // Close the file after writing
    cout << "Data saved successfully to Library_data.txt\n";
}


    // Load from File
    void loadFromFile() {
        ifstream file("Library_data.txt");
        if (!file) {
            cout << "No data file found. Starting fresh.\n";
            return;
        }
        string title, author;
        int id;
        bool availability;
        while (file >> id) {
            file.ignore();
            getline(file, title, ',');
            getline(file, author, ',');
            file >> availability;
            books.push_back(Book(title, author, id));
            books.back().setAvailability(availability);
        }
        file.close();
    }
};

int main() {
    Library library;
    library.loadFromFile();

    int choice, id;
    string title, author, name;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Add Member\n3. Display Books\n4. Display Members\n5. Borrow Book\n6. Return Book\n7. Delete Book\n8. Exit\n";
        cout << "Enter choice: ";

        while (!(cin >> choice)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number: ";
        }

        try {
            switch (choice) {
                case 1:
                    cout << "Enter Book Title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter Author: ";
                    getline(cin, author);
                    cout << "Enter Book ID: ";
                    while (!(cin >> id)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a valid Book ID: ";
                    }
                    library.addBook(title, author, id);
                    break;
                case 2:
                    cout << "Enter Member Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Member ID: ";
                    while (!(cin >> id)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a valid Member ID: ";
                    }
                    cout << "Enter Type (1-Student, 2-Teacher): ";
                    int type;
                    while (!(cin >> type) || (type != 1 && type != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter 1 for Student or 2 for Teacher: ";
                    }
                    if (type == 1)
                        library.addMember(new StudentMember(name, id));
                    else
                        library.addMember(new TeacherMember(name, id));
                    break;
                case 3:
                    library.displayBooks();
                    break;
                case 4:
                    library.displayMembers();
                    break;
                case 5:
                    cout << "Enter Book ID to Borrow: ";
                    while (!(cin >> id)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a valid Book ID: ";
                    }
                    library.borrowBook(id);
                    break;
                case 6:
                    cout << "Enter Book ID to Return: ";
                    while (!(cin >> id)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a valid Book ID: ";
                    }
                    library.returnBook(id);
                    break;
                case 7:
                    cout << "Enter Book ID to Delete: ";
                    while (!(cin >> id)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a valid Book ID: ";
                    }
                    library.deleteBook(id);
                    break;
                case 8:
                    library.saveToFile();
                    cout << "Exiting...\n";
                    return 0;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}
