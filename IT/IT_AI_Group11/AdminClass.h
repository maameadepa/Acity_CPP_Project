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
    void updateInventory(string productName, int quantity, bool isAdding){
         for (int i = 0; i < inventorySize; i++) {
            if (inventory[i].getName() == productName) {
                int currentQuantity = inventory[i].getQuantity();
                int newQuantity;

                if (isAdding) {
                    newQuantity = currentQuantity + quantity;
                    inventory[i].setQuantity(newQuantity);
                    cout << "Added " << quantity << " units of " << productName << " to stock." << endl;
                } else {
                    newQuantity = currentQuantity - quantity;

                    if (newQuantity < 0) {
                        cout << "Not enough stock for " << productName << "!" << endl;
                        return;
                    } else {
                        inventory[i].setQuantity(newQuantity);
                        cout << "Sold " << quantity << " units of " << productName << "." << endl;

                        if (newQuantity <= 10) {
                            cout << "Alert: " << productName << " is low on stock! Please restock." << endl;
                        }
                    }
                }

                cout << "Updated stock for " << productName << ": " << newQuantity << endl;
                return;
            }
        }
        cout << "Product not found in inventory!" << endl;
    }
    
    Product getProduct(string productName) {
        for (int i = 0; i < inventorySize; i++) {
            if (inventory[i].getName() == productName) {
                return inventory[i];
            }
        }
        return Product(); 
    }

};