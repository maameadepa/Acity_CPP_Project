#include <iostream>
#include <vector>
#include "Account_class.h"
#include "SavingsAccount_class.h"
#include "CheckingAccount_class.h"

using namespace std;

void displayMenu() {
    cout << "\n--- Bank Account Management ---\n";
    cout << "1. Create Savings Account\n";
    cout << "2. Create Checking Account\n";
    cout << "3. Access Account\n";
    cout << "4. View Transaction History\n";
    cout << "5. Exit\n";
}

Account* findAccount(const vector<Account*>& accounts, const string& accountNumber) {
    for (auto account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            return account;
        }
    }
    return nullptr;
}

int main() {
    vector<Account*> accounts;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        string accNum, holder;
        double initialBalance;
        Account* account = nullptr;

        switch (choice) {
        case 1: {
            cout << "Create Savings Account:\n";
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, holder);
            cout << "Enter Initial Balance: ";
            cin >> initialBalance;
            account = new SavingsAccount(accNum, holder, initialBalance);
            accounts.push_back(account);
            account->saveToFile();
            cout << "Savings Account created successfully!\n";
            break;
        }
        case 2: {
            cout << "Create Checking Account:\n";
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, holder);
            cout << "Enter Initial Balance: ";
            cin >> initialBalance;
            account = new CheckingAccount(accNum, holder, initialBalance);
            accounts.push_back(account);
            account->saveToFile();
            cout << "Checking Account created successfully!\n";
            break;
        }
        case 3: {
            cout << "Enter Account Number to access: ";
            cin >> accNum;
            account = findAccount(accounts, accNum);
            if (account) {
                account->checkBalance();
            } else {
                cout << "Account not found!\n";
            }
            break;
        }
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    for (auto acc : accounts) {
        delete acc;
    }

    return 0;
}
