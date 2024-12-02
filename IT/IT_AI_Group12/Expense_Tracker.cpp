#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "ExpenseClass.cpp"
#include "IncomeClass.cpp"

class ExpenseTracker {
private:
    vector<Expense> expenses;
    vector<Income> incomes;
    string expenseFile = "expenses.txt";
    string incomeFile = "incomes.txt";

    void saveToFile() const {
        ofstream outExp(expenseFile), outInc(incomeFile);
        if (outExp.is_open()) {
            for (const auto& exp : expenses) outExp << exp.serialize();
            outExp.close();
        }
        if (outInc.is_open()) {
            for (const auto& inc : incomes) outInc << inc.serialize();
            outInc.close();
        }
    }

    void loadFromFile() {
        ifstream inExp(expenseFile), inInc(incomeFile);
        string line;

        expenses.clear();
        incomes.clear();

        if (inExp.is_open()) {
            while (getline(inExp, line)) {
                expenses.push_back(Expense::deserialize(line));
            }
            inExp.close();
        }

        if (inInc.is_open()) {
            while (getline(inInc, line)) {
                incomes.push_back(Income::deserialize(line));
            }
            inInc.close();
        }
    }

public:
    ExpenseTracker() {
        loadFromFile();
    }

    ~ExpenseTracker() {
        saveToFile();
    }

    void addExpense() {
        string description, category;
        double amount;

        cout << "Enter description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter category: ";
        getline(cin, category);
        cout << "Enter amount: ";
        cin >> amount;

        expenses.emplace_back(description, category, amount, getCurrentDate(), getCurrentTime());
        cout << "Expense added successfully.\n";
    }

    void viewExpenses() const {
        if (expenses.empty()) {
            cout << "No expenses recorded.\n";
            return;
        }

        cout << "Expenses:\n";
        for (size_t i = 0; i < expenses.size(); ++i) {
            cout << i + 1 << ". " << expenses[i].getDate() << " " << expenses[i].getTime() << " "
                 << expenses[i].getDescription() << " " << expenses[i].getCategory() << " $"
                 << fixed << setprecision(2) << expenses[i].getAmount() << "\n";
        }
    }

    void addIncome() {
        string source;
        double amount;

        cout << "Enter income source: ";
        cin.ignore();
        getline(cin, source);
        cout << "Enter amount: ";
        cin >> amount;

        incomes.emplace_back(source, amount, getCurrentDate(), getCurrentTime());
        cout << "Income added successfully.\n";
    }

    void viewIncomes() const {
        if (incomes.empty()) {
            cout << "No incomes recorded.\n";
            return;
        }

        cout << "Incomes:\n";
        for (size_t i = 0; i < incomes.size(); ++i) {
            cout << i + 1 << ". " << incomes[i].getDate() << " " << incomes[i].getTime() << " "
                 << incomes[i].getSource() << " $" << fixed << setprecision(2) << incomes[i].getAmount() << "\n";
        }
    }

    void generateSummary() const {
        double totalIncome = 0, totalExpense = 0;

        for (const auto& inc : incomes) totalIncome += inc.getAmount();
        for (const auto& exp : expenses) totalExpense += exp.getAmount();

        cout << "\n--- Summary ---\n";
        cout << "Total Income: $" << fixed << setprecision(2) << totalIncome << "\n";
        cout << "Total Expense: $" << fixed << setprecision(2) << totalExpense << "\n";
        cout << "Remaining Balance: $" << fixed << setprecision(2) << (totalIncome - totalExpense) << "\n";
        cout << "Percentage of Income Spent: " 
             << (totalIncome > 0 ? (totalExpense / totalIncome) * 100 : 0) << "%\n";
    }

    string getCurrentDate() const {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        return to_string(localTime->tm_mday) + "/" + to_string(localTime->tm_mon + 1) + "/" + to_string(1900 + localTime->tm_year);
    }

    string getCurrentTime() const {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        return to_string(localTime->tm_hour) + ":" + to_string(localTime->tm_min);
    }
};

int main() {
    ExpenseTracker tracker;
    int choice;

    do {
        cout << "\nExpense Tracker Menu\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Add Income\n";
        cout << "4. View Incomes\n";
        cout << "5. Generate Summary\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: tracker.addExpense(); break;
        case 2: tracker.viewExpenses(); break;
        case 3: tracker.addIncome(); break;
        case 4: tracker.viewIncomes(); break;
        case 5: tracker.generateSummary(); break;
        case 6: cout << "Exiting... Goodbye!\n"; break;
        default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
