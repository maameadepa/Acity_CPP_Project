#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Expense {
    string date;
    string description;
    double amount;
};

//Add Expense Function
void addExpense(vector<Expense>& expenses) {
    Expense expense;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> expense.date;
    cin.ignore();

    cout << "Enter description: ";
    getline(cin, expense.description);

    while(true) {
        cout << "Enter amount(GHS): ";
        cin >> expense.amount;
        if (expense.amount > 0) {
            break;
        }
        cout << "Please enter an amount above 0!" << endl;
    }

    expenses.push_back(expense);
    cout << "Expense Added Successfully!" << endl;
}

void viewAllExpenses(vector<Expense>& expenses) {
    if(expenses.empty()) {
        cout << "No expenses have been added!" << endl;
        return;
    }

    cout << "\t All Expenses " << endl;
    cout << "---------------------------------------------" << endl;
    cout << setw(12) << "Date" << setw(20) << "Description" << setw(10) << "Amount" << endl;
    cout << "---------------------------------------------" << endl;

    for (const auto& expense : expenses) {
        cout << setw(12) << expense.date << setw(20) 
        << expense.description << setw(10) << expense.amount << endl;
    }
    cout << "-----------------------------------------------" << endl;
    // double total = totalExpense();
    // cout << "Total expense" << setw(40) << total << endl;
}

void updateExpense(vector<Expense>) {

}

void deleteExpense(vector<Expense>) {

}

double totalExpense(const vector<Expense>& expenses) {
    double total = 0.0;

    for (const auto& expense: expenses) {
        total += expense.amount;
    }
    return total;
}

int main() {
    vector<Expense> expenses;
    
    int choice;

    do {
        cout << "\t Expense Tracker Menu " << endl;
        cout << "-------------------------------------" << endl;
        cout << "\t 1. Add Expense" << endl;
        cout << "\t 2. View Expense" << endl;
        cout << "\t 3. Update Expense" << endl;
        cout << "\t 4. Delete Expense" << endl;
        cout << "\t 5. Exit" << endl;
        cout << "\t Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addExpense(expenses);
                    break;
            case 2: viewAllExpenses(expenses);
                    break;
            case 3: updateExpense(expenses);
                    break;
            case 4:deleteExpense(expenses);
                    break;
            case 5: cout << "Exiting..." << endl;
                    break;
            default: cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}