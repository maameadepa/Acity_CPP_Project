#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Expense {
private:
    string description, category, date, time;
    double amount;

public:
    Expense(string desc, string cat, double amt, string d, string t)
        : description(desc), category(cat), amount(amt), date(d), time(t) {}

    string getDescription() { 
        return description; 
        }
    string getCategory() {
        return category; 
        }
    double getAmount() {
        return amount; 
        }
    string getDate() {
        return date; 
        }
    string getTime() {
        return time; 
        }

    void setDescription(string& desc) {
        description = desc; 
    }
    void setCategory(string& cat) { 
        category = cat; 
    }
    void setAmount(double amt) { amount = amt; }


};
