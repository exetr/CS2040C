#include <iostream>
using namespace std;

int main() {
    while(true) {
        unsigned long long a, b;
        cin >> a >> b;
        if(a==0 | b==0){
            break;
        } else {
            unsigned long long sum = a+b;
            cout << sum << endl;
        }
    }
}