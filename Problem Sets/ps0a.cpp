#include <iostream>
using namespace std;

int main() {
    while(true) {
        int a, b;
        cin >> a >> b;
        if(a==0 | b==0){
            break;
        } else {
            int sum = a+b;
            cout << sum << endl;
        }
    }
}