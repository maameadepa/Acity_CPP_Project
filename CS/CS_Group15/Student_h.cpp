#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string studentName;
    int studentID;

public:
    Student(const string& name, int id);
    string getName() const;
    int getID() const;
};

#endif
