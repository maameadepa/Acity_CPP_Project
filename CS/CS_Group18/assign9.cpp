#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Class to gather and store user information
class UserInfo{
public:
    string name;
    int age;

    void getUserInfo(){
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your age: ";
        cin >> age;
    }
};

// Class to calculate the area of a triangle
class TriangleArea{
public:
    double base, height;

    TriangleArea(double b, double h) : base(b), height(h){}

    double calculateArea(){
        return 0.5 * base * height;
    }
};

// Class to calculate the volume of a cylinder
class CylinderVolume {
public:
    double radius, height;

    CylinderVolume(double r, double h) : radius(r), height(h) {}

    double calculateVolume(){
        return M_PI * radius * radius * height;
    }
};

// Class to write information to a file
class FileWriter{
public:
    void writeToFile(const UserInfo &user, double triangleArea, double cylinderVolume){
        
        ofstream file("assign9.txt");
        
        if (file.is_open()) {
            file << "User Information:" <<endl;
            file << "Name: " << user.name <<endl;
            file << "Age: " << user.age <<endl;
            file << "Triangle Area: " << triangleArea <<endl;
            file << "Cylinder Volume: " << cylinderVolume <<endl;
            file.close();
            
            cout << "Information is written inside assign9.txt" <<endl;
        } 
        
        else {
            cout << "Unable to open file." <<endl;
        }
    }
};

int main() {
    // Create instances of each class
    UserInfo user;
    user.getUserInfo();

    // Get triangle dimensions and calculate area
    double base, height;
    
    cout << "Enter the base of the triangle: ";
    cin >> base;
    
    cout << "Enter the height of the triangle: ";
    cin >> height;
    
    TriangleArea triangle(base, height);
    double triangleArea = triangle.calculateArea();

    // Get cylinder dimensions and calculate volume
    double radius, cylHeight;
    
    cout << "Enter the radius of the cylinder: ";
    cin >> radius;
    
    cout << "Enter the height of the cylinder: ";
    cin >> cylHeight;
    
    CylinderVolume cylinder(radius, cylHeight);
    
    double cylinderVolume = cylinder.calculateVolume();

    // Write data to file
    FileWriter fileWriter;
    fileWriter.writeToFile(user, triangleArea, cylinderVolume);

    return 0;
}