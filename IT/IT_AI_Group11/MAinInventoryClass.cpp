#include <iostream>
#include "AdminClass.h"
using namespace std;

int main() {
    Admin admin;
    int choice;
    string username;
    string password;
    int adminChoice;

    while (true){
        cout<<"\nWelcome to the Joojo & Wuni's Stationery Shop!"<<endl;
        cout<<"1. Admin  Login"<<endl;
        cout<<"2. Customer Menu"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice){
        case 1:{ 
            cout<<"Enter Admin Username:";
            cin>> username;
            cout<<"Enter Admin Password:";
            cin>> password;

            if(username=="admin "&& password == "admin123"){
                while (true){
                     cout<<"\nAdmin Menu"<<endl;
                     cout<<"1. View Inventory"<<endl;
                     cout<<"2. Update Inventory"<<endl;
                     cout<<"3. Logout"<<endl;
                     cout<<"Enter your choice:";
                     cin>>adminChoice;

                     if (adminChoice == 1) {
                        admin.viewInventory();
                    } else if (adminChoice == 2) {
                        string productName;
                        int quantity;
                        bool isAdding;

                        cout << "Enter product name to update: ";
                        cin >> productName;
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        cout << "Are you adding to stock? (1 for Yes, 0 for No): ";
                        cin >> isAdding;

                        admin.updateInventory(productName, quantity, isAdding);

                } else if (adminChoice == 3) {
                        cout << "Logging out of Admin Menu..." << endl;
                        break;
                    } else {
                        cout << "Invalid choice! Please try again." << endl;
                    }
                }

            }else {
                cout << "Invalid Logins! Access denied." << endl;
            }
            break;
        }

        case 2:{
            
        }


    }
}