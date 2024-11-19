#include <iostream>
using namespace std;

int main() {
    int marks[5];
    int sum = 0;  // Initialize sum to 0
    float percentage;  // Declare percentage as float for decimal value

    cout << "Marks for the exams" << endl;

    // Loop to get input from the user
    for (int i = 0; i < 5; i++) {
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> marks[i];
        sum += marks[i];  // Add the current mark to the sum
    }

    // Calculate percentage
    percentage = (sum / 500.0) * 100;  // Use 500.0 to avoid integer division

    // Output the percentage
    cout << "The percentage is: " << percentage << "%" << endl;

    return 0;
}
