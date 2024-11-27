# include <iostream>
# include "Employee.cpp"

using namespace std;

int main(){
    ManageEmployee empManager;
    int choice;

    cout << "Payroll Management System" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Edit Employee" << endl;
    cout << "3. Delete Employee" << endl;
    cout << "4. Display Employee" << endl;
    cout << "5. Generate Payslip" << endl;
    cout << "6. Exit" << endl;
    
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1: empManager.addEmployee(); break;
        case 6: cout << "Exiting program"; break;
        default: cout << "Options are between 1-6"; break;

    }

}