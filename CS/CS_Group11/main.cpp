#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// Struct for item
struct Item {
    string name;
    int quantity;
    double price;
};

// Shopping cart class
class ShoppingCart {
public:
    vector<Item> items;

    void addItem();
    void viewCart();
};

// Function prototypes
void invalidInput();
void saveCart(const ShoppingCart& cart);
void loadCart(ShoppingCart& cart);
void calculateTotal(const vector<Item>& items);

int main() {
    ShoppingCart cart;
    int choice;

    do {
        cout << "\n===== Online Shopping Cart =====\n";
        cout << "1. Add Item\n";
        cout << "2. View Cart\n";
        cout << "3. Save Cart\n";
        cout << "4. Load Cart\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cart.addItem();
            break;
        case 2:
            cart.viewCart();
            break;
        case 3:
            saveCart(cart);
            break;
        case 4:
            loadCart(cart);
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            invalidInput();
        }
    } while (choice != 5);

    return 0;
}
