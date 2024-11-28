#include "Account_class.cpp"

class SavingsAccount : public Account {
public:
int accountNumber;
string holderName;
int balance;

    SavingsAccount(const string& accNum, const string& holder, double bal)
        : Account(accNum, holder, bal) {}

    void saveToFile() const override {
        ofstream file("SavingsAccount_" + accountNumber + ".txt");
        if (file.is_open()) {
            file << "Account Type: Savings Account\n";
            file << "Account Number: " << accountNumber << "\n";
            file << "Account Holder: " << holderName << "\n";
            file << "Balance: " << balance << "\n";
            file.close();
        } else {
            cout << "Error saving account to file.\n";
        }
    }
};