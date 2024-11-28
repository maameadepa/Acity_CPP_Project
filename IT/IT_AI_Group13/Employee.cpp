# include <iostream>
# include <fstream>
# include <vector>
# include <iomanip>

using namespace std;

struct Employee{
    int id;
    string name;
    string position;
    string department;
    string salaryType; // Salaried or hourly
    double salary;
    
    void display(){
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Department: " << department << endl;
        cout << "Salary Type: " << salaryType <<endl;
        cout << "Salary: " << salary <<  endl;
    } 
};

class ManageEmployee{
    private:
        vector<Employee> employees;
        string filename = "Employees info.txt";

        void saveToFile(){
            ofstream outFile(filename);
            if (!outFile){
                cout << "Unable to open file";
            }

            for(const auto& emp: employees){
                outFile << "ID: " << setw(3) << setfill('0') << emp.id << endl;
                outFile << "Name: " << emp.name << endl;
                outFile << "Position: " << emp.position << endl;
                outFile << "Department: " << emp.department << endl;
                outFile << "Salary Type: " << emp.salaryType << endl;
                outFile << "Salary: $" << fixed << setprecision(2) << emp.salary << endl;
                outFile << endl;
            }
        }
    
    public:
        ManageEmployee() {
            ifstream inFile (filename);
            if (!inFile){
                cout << "Unable to open file";
            }

            string line;
            while (getline(inFile,line)){
                if (line.empty()) continue;
                
                Employee emp;

                getline(inFile, line); // ID
                emp.id = stoi(line.substr(line.find(":") + 2));

                getline(inFile, line); // Name
                emp.name = line.substr(line.find(":") + 2);

                getline(inFile, line); // Position
                emp.position = line.substr(line.find(":") + 2);

                getline(inFile, line); // Department
                emp.department = line.substr(line.find(":") + 2);

                getline(inFile, line); // Salary Type
                emp.salaryType = line.substr(line.find(":") + 2);

                getline(inFile, line); // Salary
                emp.salary = stod(line.substr(line.find("$") + 1));

                employees.push_back(emp);
            }
        }

        void addEmployee(){
            Employee emp;
            cout << "Enter Employees Details" << endl;
            cout << "ID: ";
            cin >> emp.id;
            cin.ignore();
            cout << "Name: ";
            getline(cin, emp.name);
            cout << "Position: ";
            getline(cin, emp.position);
            cout << "Department: ";
            getline(cin, emp.department);
            cout << "Salary Type (Salaried or Hourly): ";
            cin >> emp.salaryType;
            cout << "Salary: ";
            cin >> emp.salary;

            employees.push_back(emp);
            saveToFile();
            cout << "Employee added sucessfully" << endl;
        }

    const vector<Employee>& getEmployees() const{
        return employees;
    }
};