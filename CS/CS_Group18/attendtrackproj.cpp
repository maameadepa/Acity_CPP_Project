#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Enumerated data type for gender
enum Gender { MALE, FEMALE };

// Student class
class Student {
private:
    string name;
    int age;
    string course;
    Gender gender;
    vector<int> attendance; // Daily attendance: 1 for present, 0 for absent
public:
    // Constructor
    Student(string n, int a, string c, Gender g) 
        : name(n), age(a), course(c), gender(g), attendance(30, 0) {}

    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
    string getCourse() const { return course; }
    Gender getGender() const { return gender; }
    int getAttendance(int day) const { return attendance[day - 1]; }

    // Setters
    void markAttendance(int day, int status) {
        if (day >= 1 && day <= 30)
            attendance[day - 1] = status;
        else
            throw invalid_argument("Invalid day. Must be between 1 and 30.");
    }

    // Display attendance summary
    void displayAttendance() const {
        int total = 0;
        for (int i : attendance) total += i;
        cout << "Attendance Summary for " << name << ": " << total << "/30 days\n";
    }
};
