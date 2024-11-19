#include <iostream>

using namespace std;

int main(){
    float bs, da, hra, gross_salary;

    cout<<"Enter the basic salary: ";
    cin>>bs;

    da = 0.40 * bs;
    hra = 0.20 * bs;
    gross_salary = da + hra + bs;

    cout<<"Gross Salary: "<<gross_salary;
    return 0; 
}