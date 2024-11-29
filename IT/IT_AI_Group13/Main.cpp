#include <iostream>
#include "Employee.cpp"
using namespace std;

int main() {
    EmployeeManager empManager;
    int choice;

    do {
        cout << "\n--- Payroll Management System ---\n"
             << "1. Add Employee\n2. Edit Employee\n3. Delete Employee\n"
             << "4. View Employees\n5. Generate Payslip\n6. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: empManager.addEmployee(); break;
            case 4: {
                int viewChoice;
                cout << "1. View All Employees\n2. View Specific Employee\nChoice: ";
                cin >> viewChoice;
                if (viewChoice == 1) empManager.viewAllEmployees();
                else if (viewChoice == 2) empManager.viewEmployeeById();
                else cerr << "Invalid choice.\n";
                break;
            }
            case 6: cout << "Exiting program.\n"; break;
            default: cerr << "Invalid choice.\n"; break;
        }
    } while (choice != 6);

    return 0;
}
