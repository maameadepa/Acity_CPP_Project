#include <iostream>
#include <iomanip>
#include "ProductClass.h"
class Admin{
private:
    Product inventory[5];
    int inventorySize = 5;

public:
    Admin() {
        inventory[0] = Product("Pen", 100, 1.50);
        inventory[1] = Product("Pencil", 100, 1.00);
        inventory[2] = Product("Eraser", 100, 0.50);
        inventory[3] = Product("Ruler", 100, 2.00);
        inventory[4] = Product("MathSet", 100, 5.00);
    }
    void viewInventory() {
        cout << setw(20) << left << "Product Name" 
             << setw(10) << left << "Quantity" 
             << setw(10) << "Price" << endl;
        for (int i = 0; i < inventorySize; i++) {
            inventory[i].display();
        }
    }

};