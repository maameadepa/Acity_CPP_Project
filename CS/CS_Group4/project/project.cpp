#include <iostream>
#include <iomanip> 
#include <fstream>
using namespace std;

int main() {
    string name;
    int rollNumber;
    int subjects;
    float total = 0, marks, average;

    ofstream outToFile("reportcard.txt", ios::app);


    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter roll number: ";
    cin >> rollNumber;

    cout << "Enter the number of subjects: ";
    cin >> subjects;

    total = 0;


    outToFile << "\n--------- Report Card ---------\n";
    outToFile << "Name       : " << name << endl;
    outToFile << "Roll Number: " << rollNumber << endl << endl;
  
    for (int i = 1; i <= subjects; ++i) {
        cout << "Enter marks for Subject " << i << ": ";
        cin >> marks;
        total += marks;

        
        char grade;
        if (marks >= 90) {
            grade = 'A';
        } else if (marks >= 75) { 
            grade = 'B';
        } else if (marks >= 50) {
            grade = 'C';
        } else {
            grade = 'D';
        }

        
        outToFile << "Subject " << i << " Marks: " << marks << " | Grade: \t " << grade << endl;
    }

    
    average = total / subjects;
    outToFile << "\nTotal Marks: " << total << endl;
    outToFile << "Average    : " << average << endl;

    string remarks;
    if (average >= 90) {
        remarks = "Excellent performance. More vim.";
    } else if (average >= 75) {
        remarks = "Good job. You force.";
    } else if (average >= 50) {
        remarks = "You try. There's room for improvement.";
    } else {
        remarks = "Needs improvement. Don't give up.";
    }
    outToFile << "Remarks    : " << remarks << endl;
    
    outToFile.close();
    
    return 0;
}
