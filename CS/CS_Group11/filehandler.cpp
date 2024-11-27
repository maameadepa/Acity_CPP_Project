#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};

class ShoppingCart {
public:
    vector<Item> items;
};

void saveCart(const ShoppingCart& cart) {
    ofstream file("CartDetails.txt");
    if (!file) {
        cout << "Error saving cart to file!\n";
        return;
    }
    for (const auto& item : cart.items) {
        file << item.name << "," << item.quantity << "," << item.price << "\n";
    }
    file.close();
    cout << "Cart saved successfully!\n";
}

void loadCart(ShoppingCart& cart) {
    ifstream file("CartDetails.txt");
    if (!file) {
        cout << "Error loading cart from file!\n";
        return;
    }
    cart.items.clear();
    string name;
    int quantity;
    double price;
    while (file >> name >> quantity >> price) {
        cart.items.push_back({name, quantity, price});
    }
    file.close();
    cout << "Cart loaded successfully!\n";
}
