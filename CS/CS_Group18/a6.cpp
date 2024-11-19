#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void transfermoney(int momo_pin) {
    cout << "\nTransfer Money\n**\n";
    cout << "\n1. MoMo User\n2. Other Network\n";
    cout << "\nEnter choice: ";
    int no;
    int number1, number2;
    double amount1;
    string reference;
    cin >> no;
    
    if (no == 1) {
        cout << "\nEnter Mobile number: ";
        cin >> number1;
        cout << "\nConfirm Mobile number: ";
        cin >> number2;

        if (number1 == number2) {
            cout << "\nEnter amount to be sent\nAmount: ";
            cin >> amount1;
            cout << "\nEnter Reference: ";
            cin >> reference;
            cout << "\n";
            cout << "\n*SUMMARY*\n";
            cout << fixed << setprecision(2);
            cout << "Transfer GHS " << amount1 << " to " << number2 << endl;
            cout << "Reference: " << reference << endl;
            cout << "Fee is 0.00, Tax is 0.00" << endl;
            cout << "Total amount is GHS " << amount1 << endl;

            int momo;
            cout << "\nEnter MoMo Pin or any key to cancel: ";
            cin >> momo;
             if (momo == momo_pin) {
                cout << "You have successfully sent GHS " << amount1 << " to " << number2 << endl;

                ofstream smsFile("momo_transfer.txt", ios::app);
                smsFile << "You have successfully sent GHS " << amount1 << " to " << number2 << endl;
                smsFile << "Reference: " << reference << endl;
                smsFile << "Total amount is GHS " << amount1 << endl;
                smsFile << "------------------------------------------\n";
                smsFile.close();
            } else {
                cout << "Incorrect Pin" << endl;
                return; 
            }
        } else {
            cout << "The numbers are not the same" << endl;
        }
    } 
    else if (no == 2) {
        cout << "\n1. Airtel Tigo\n2. Telecel\n3. G-Pay\n4. Glo\n"; 
    } 
    else {
        cout << "\nInvalid Option" << endl;
        return;  
    }
}

void buyAirtime(int momo_pin) {
    int airtimeChoice;
    cout << "\n**Buy Airtime\n";
    cout << "1. Self\n";
    cout << "2. Other Number\n";
    cout << "Enter your choice: ";
    cin >> airtimeChoice;

    if (airtimeChoice == 1) {
        int amount;
        cout << "\nEnter amount: ";
        cin >> amount;
        cout << "\nEnter MoMo Pin: ";
        int momo1;
        cin >> momo1;

        if (momo1 == momo_pin) {
            cout << "\nYou have successfully bought GHS " << amount << " airtime for yourself.\n";

           
            ofstream smsFile("airtime_purchase.txt", ios::app);
            smsFile << "You have successfully bought GHS " << amount << " airtime for yourself.\n";
            smsFile << "------------------------------------------\n";
            smsFile.close();
        } else {
            cout << "Incorrect Pin" << endl;
            return;
        }
    } else if (airtimeChoice == 2) {
        string otherNumber, otherNumber1;
        int amount;
        cout << "Enter recipient number: ";
        cin >> otherNumber;
        cout << "Confirm recipient number: ";
        cin >> otherNumber1;

        if (otherNumber == otherNumber1) {
            cout << "Enter amount: ";
            cin >> amount;
            cout << "Enter MoMo Pin: ";
            int momo1;
            cin >> momo1;
                        if (momo1 == momo_pin) {
                cout << "You have successfully bought GHS " << amount << " airtime for " << otherNumber << ".\n";

                ofstream smsFile("airtime_purchase.txt", ios::app);
                smsFile << "You have successfully bought GHS " << amount << " airtime for " << otherNumber << ".\n";
                smsFile << "------------------------------------------\n"; 
                smsFile.close();
            } else {
                cout << "Incorrect Pin" << endl;
                return;
            }
        } else {
            cout << "The numbers do not match. Please try again.\n";
        }
    } else {
        cout << "Invalid choice.\n";
    }
}

void momo_pay(int momo_pin) {
    cout << "\n**MoMo Pay" << endl;
    cout << "1. MoMo pay\n2. Pay Bill\n3. GhQR\n4. Fuels\n5. Ghana.GOV\n";
    cout << "\nEnter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "1. DSTV\n2. Snap++";
            break;
        default:
            cout << "Invalid choice";
            break;
    }
}

int main() {
    string ussdcode;
    int choice;
    const int momo_pin = 1234;
    bool running = true;
    int attempts = 0;
    
    while (true) {
        cout << "Enter USSD code: ";
        cin >> ussdcode;

        if (ussdcode == "*170#") {
            cout << "USSD code accepted.\n";
            break;
        } else {
            attempts++;
            cout << "Invalid USSD code. You have entered an incorrect code " << attempts << " times.\n";
        }
    }
    
    while (running) {
        cout << "\nMTN MOMO" << endl;
        cout << "\n1. Transfer Money\n2. Momo Pay\n3. Airtime/Bundle\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                transfermoney(momo_pin);
                break;
            case 2:
                 momo_pay(momo_pin);
                break; 
            case 3:
                buyAirtime(momo_pin);
                break;  
            case 4:
                cout << "Exiting...\n";
                running = false;
                break; 
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}