#include <iostream>
using namespace std;

class Product{
private:
    string name;
    int quantity;
    double price;
public:
    void setNAme(string n){
        name=n;
        }
    void setQuantity(int q){
        quantity = q;
        }
    void setPrice(double p){
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

};