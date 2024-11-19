#include <iostream>
#include <fstream>
using namespace std;

int main(){

    string name;
    int age;
    string school;
    // opening the file
    ofstream outToFile("files.txt");
    
    
    cout << "Name: ";
    cin >> name;
    cout << "Age:";
    cin >> age;
    cout << "school: ";
    cin.ignore();
    getline(cin,school);

    outToFile <<name<<endl;
    outToFile << age<<endl;
    outToFile << school<<endl;

    outToFile.close();
    } 