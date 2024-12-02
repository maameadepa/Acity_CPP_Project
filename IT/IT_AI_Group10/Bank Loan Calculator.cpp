#include <iostream>
#include <cmath> // For pow
#include <iomanip> // For set precision. The decimal place.
#include <fstream> // Save to File
#include <string>// String class
#include <vector>// Something like a memory space(Can resize it self automatically)


using namespace std;

int i;


class Loan{
	private: // Only accessible to the loan class.
		double principal;   // What you borrowed        
    	double annualInterestRate; //Annual charge on what you borrowed in percentage
    	int duration;         // Time in years             
    	double monthlyPayment;  //What to pay monthly to cover the loan
    
    
    public: // Accessible anywhere in the code //Constructor
    	Loan(double p, double r, int d)
    	:principal(p), annualInterestRate(r) , duration(d), monthlyPayment(0.0){}// Explicitly initializing monthly payment to avoid errors during calculations.
    	// Sets up basic info about the loan
    	//Takes the values for the loan and fills in the details.
    	
    	
    	 /*
     	 calculateMonthlyPayment
      	Calculates the fixed monthly payment using the formula for an annuity.
      	Formula: M = P * (r(1+r)^n) / ((1+r)^n - 1), where:
      	- M = Monthly Payment
     	 - P = Principal
     	 - r = Monthly interest rate
    	  - n = Total number of payments (months)
    	 */
    	 
    void calculateMonthlyPayment() {
        double monthlyRate = annualInterestRate / 12 / 100; //From years to months
        int totalPayments = duration * 12;                 // Total number of payments in mothns

        if (monthlyRate == 0) {
            // When the interest rate is 0
            monthlyPayment = principal / totalPayments;
        } else {
            // When the loan comes with interest
            monthlyPayment = principal * (monthlyRate * pow(1 + monthlyRate, totalPayments)) 
                            / (pow(1 + monthlyRate, totalPayments) - 1);
        }
    }
    

     // displayLoanDetails
    
    void displayLoanDetails() const { // Does not change your loan details
        cout << fixed << setprecision(2); // 2 decimal places
        cout << "\nYour Loan Details" << endl;
        cout << "*****************" << endl;
        cout << "\nPrincipal: GHS" << principal << endl;
        cout << "\nAnnual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "\nDuration: " << duration << " years" << endl;
        cout << "\nMonthly Payment: GHS" << monthlyPayment << endl;
    }
    
    // Saving Details To the File.
     void saveToFile(ofstream &outFile) const { //& used for referencing. Do not waste time to create a new file. 
        outFile << fixed << setprecision(2);
        outFile << "Principal: GHS" << principal << "\n";
        outFile << "Annual Interest Rate: " << annualInterestRate << "%\n";
        outFile << "Duration: " << duration << " years\n";
        outFile << "Monthly Payment: GHS" << monthlyPayment << "\n";
        outFile << "------------------------\n";
    }
		
};

//For the user's bank details
// Create another menu for the bank account.
class BankAccount {
private:
    string accountName;
    string accountNumber;   
    double balance;          
    vector<Loan> loans;       // A list of loans associated with the account. At this point it is dynamic and empty all loans can be added.

public:
    // Constructor
    BankAccount(const string &name, const string &number, double bal) 
        : accountName(name), accountNumber(number), balance(bal) {}

    //Deposit
    void deposit(double amount) {
        balance += amount; // Increase balance
        cout << "Deposit successful! New balance: GHS " << fixed << setprecision(2) << balance << endl;
    }

    
     //Withdraw
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount; // Deduct amount
            cout << "Withdrawal successful! New balance: GHS" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Insufficient funds!" << endl; // Error message if balance is insufficient
        }
    }


       // Requesting for a loan
    void requestLoan(double principal, double interestRate, int duration) {
        if (principal > balance * 2) {
            // What you borrowed should not be more than what is in your account
            cout << "Loan request denied !" << endl;
            return;
        }

        // Creating a new loan
        Loan newLoan(principal, interestRate, duration);
        newLoan.calculateMonthlyPayment(); // Calculate monthly payment for the loan
        loans.push_back(newLoan);          // Adds loans

        cout << "\nLoan approved!" << endl;
       // newLoan.displayLoanDetails(); // Display loan details

        saveToFile(); // Save loan details to a file for record-keeping
    }

    
     // displayAccountDetails
    
    void displayAccountDetails() const {
        cout << "Account Name: " << accountName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: GHS" << fixed << setprecision(2) << balance << endl;
        cout << "Number of Loans: " << loans.size() << endl; //.size() returns number of elements in the vector.
    }

    
      //saveLoanDetails
     
    void saveToFile() const {
        ofstream outFile("LoanDetails.txt", ios::app); // Appends
        if (outFile.is_open()) {
            outFile << "Account Name: " << accountName << "\n";
            outFile << "Account Number: " << accountNumber << "\n";
            outFile << "Balance: GHS" << fixed << setprecision(2) << balance << "\n";
            outFile << "Loans:\n";
			 
            for (size_t i = 0; i < loans.size(); ++i) { //size_t = unsigned int type to represent sizes
    			cout << "\nLoan #" << (i + 1) << ":" << endl; // Number of Your loans
    			
            	loans[i].displayLoanDetails();
				
				
				loans[i].saveToFile(outFile);
				}


            outFile.close();
            cout <<"Loan Details Saved!" << endl;
        } else {
            cout << "Cannot open!" << endl;
        }
    }
};


 // The main
int main() {

     cout <<" Bank Loan Calculator (Know Your Debts!!)"<< endl;
     cout << "*****************************************" << endl; 
	// Example
    BankAccount account("Vina", "758594", 10000.00);

    account.displayAccountDetails(); // From the account details 
    
    int choice; // User choice menu
    do { // Menu is displayed at least once for the do while before the condition is checked
    // the user can atleast see the menu and choose what they want from it.
        //  Menu options
        cout << "\nMenu:\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Request Loan\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        // Process user choice
        switch (choice) {
        case 1: {
            double amount;
            cout << "\nEnter deposit amount: GHS";
            cin >> amount;
            account.deposit(amount);
            break;
        }
        case 2: {
            double amount;
            cout << "\nEnter withdrawal amount: GHS";
            cin >> amount;
            account.withdraw(amount);
            break;
        }
        case 3: {
            double principal, interestRate;
            int duration;
            cout << "\nEnter loan principal amount: GHS";
            cin >> principal;
            cout << "\nEnter annual interest rate (in %): ";
            cin >> interestRate;
            cout << "\nEnter loan duration (in years): ";
            cin >> duration;
            account.requestLoan(principal, interestRate, duration);
            break;
        }
        case 4:
            account.displayAccountDetails();
            break;
        case 5:
            cout << "\nGoodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5); 

    return 0;
}


