#include <iostream>
#include "ProductClass.h"
using namespace std;

int main(){
    int choice;
    string username;
    string password;
    int adminChoice;

    while (true){
        cout<<"\nWelcome to the Joojo & Wuni's Stationery Shop!"<<endl;
        cout<<"1. Admin  Login"<<endl;
        cout<<"2. Customer Menu"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<" Enter your choice:";
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


                }
            }


        }


        }


    }
}