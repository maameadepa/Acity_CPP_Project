#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Income {
private:
    string source, date, time;
    double amount;

public:
    Income(string src, double amt, string d, string t)
        : source(src), amount(amt), date(d), time(t) {}

    string getSource() {
        return source; 
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
 
};
