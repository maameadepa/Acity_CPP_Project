#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main (){
    struct Employee {
    int id;
    string name;
    int age;
    string dateOfBirth;
    string gender;
    string department;
};

void addEmployee(vector<Employee>& employees) {
    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, emp.name);
    cout << "Enter Age: ";
    cin >> emp.age;
    cin.ignore();
    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    getline(cin, emp.dateOfBirth);
    cout << "Enter Gender: ";
    getline(cin, emp.gender);
    cout << "Enter Department: ";
    getline(cin, emp.department);
    employees.push_back(emp);
    cout << "Employee added successfully.\n";
}
    
}

