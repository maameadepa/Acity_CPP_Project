#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

double CompoundAmount(double principal, double annualInterestRate, int years){
    double monthlyInterestRate = (annualInterestRate / 100) / 12;


    double compoundAmount = (principal * pow((1+monthlyInterestRate/12),12*years));

    return compoundAmount;
}
double calculateMonthlyPayment(double principal, double annualInterestRate, int years) {
    // Convert annual interest rate to monthly and percentage to decimal
    double monthlyInterestRate = (annualInterestRate / 100) / 12;
    
    // Total number of payments (months)
    int totalPayments = years * 12;
    
    // Monthly payment formula
    double monthlyPayment = (principal * monthlyInterestRate * pow(1 + monthlyInterestRate, totalPayments)) /
                            (pow(1 + monthlyInterestRate, totalPayments) - 1);

    return monthlyPayment;
}


int main(){
    int lvalue;
    int interestRate;
    int lyears;
    int repay;
    double compoundperyear;


    cout << "Enter the loan amount: " << endl;
    cin >> lvalue;

    cout << "Enter the annual interest rate: " << endl;
    cin >> interestRate;

    cout << "Enter the loan term(number of years you are borrowing the money for): " << endl;
    cin >> lyears;

    int monthlypayment = calculateMonthlyPayment(lvalue , interestRate , lyears);
    compoundperyear = CompoundAmount(lvalue , interestRate , lyears);

    cout << "Loan Breakdown\t" <<endl;
    cout << "Principal\t" << "Annual Interest Rate(%)\t" << "Loan Term(in years)\t" << "Monthly Payment\t" <<endl;
    cout << "===================================================================================================="<<endl;
    cout << "$"<< lvalue <<"       \t"<<interestRate<<"%               \t"<<lyears<<"years                \t"<<"$"<<monthlypayment <<"     \t"<<endl; 


    while (compoundperyear>=0){
        cout << "Enter the amount you want to pay"<<endl;
        cin >> repay;

        compoundperyear -= repay;
        if (compoundperyear >= 0){

        cout << "Remaining debt: " <<compoundperyear<<endl;
        }
        else{
            cout <<"Your debt has been paid in full"<<endl;
            break;
        }

    }
}