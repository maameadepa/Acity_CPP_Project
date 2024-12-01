#include "Account_class.cpp" // Include the updated Account class
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CheckingAccount : public Account {
public:
    CheckingAccount(string accNum, string holder, double bal)
        : Account(accNum, holder, bal) {}

    void saveToFile() const override { // Overrides the virtual method
        string filename = "CheckingAccount_" + getAccountNumber() + ".txt";
        ofstream file(filename);
        if (file.is_open()) {
            file << "Account Type: Checking Account\n";
            file << "Account Number: " << getAccountNumber() << "\n";
            file << "Account Holder: " << getHolderName() << "\n";
            file << "Balance: " << getBalance() << "\n";
            file.close();
            cout << "Account successfully saved to " << filename << ".\n";
        } else {
            cout << "Error saving account to file.\n";
        }
    }
};
