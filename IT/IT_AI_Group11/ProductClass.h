#include <iostream>
#include <iomanip>
using namespace std;

class Product{
private:
    string name;
    int quantity;
    double price;
public:
    void setNAme(string n){
        name = n;
        }
    void setQuantity(int q){
        quantity = q;
        }
    void setPrice(double p){
        price = p;
        }

    string getName(){
        return name;
        }
    int getQuantity(){
        return quantity;
        }
    double getPrice(){
        return price;
        }

    void display(){
        cout << setw(20) << left << name
             << setw(10) << left << quantity
             << "$" << setw(10) << left << fixed << setprecision(2) << price << endl;
    }
    

};