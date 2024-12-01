#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "Account_class.cpp"
#include "SavingsAccount_class.cpp"
#include "CheckingAccount_class.cpp"

using namespace std;

void displayMenu();
void performOperation(Account* account, vector<Account*>& accounts);
Account* findAccount(const vector<Account*>& accounts, const string& accountNumber);
void logTransaction(const string& sender, const string& receiver, double amount);
void viewTransactionHistory();

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
            if (account != nullptr) {
                performOperation(account, accounts);
            } else {
                cout << "Account not found!\n";
            }
            break;
        }
        case 4:
            viewTransactionHistory();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    for (Account* acc : accounts) {
        delete acc;
    }

    return 0;
}
