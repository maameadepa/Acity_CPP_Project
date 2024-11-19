#include <iostream>
#include <string>

using namespace std;
string a = "abcd";

int main() { 
    
    for(int i = a.length()-1; i >= 0; i--){
        cout << a[i]; 
    }

    return 0;
}