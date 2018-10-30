#include <iostream>
using namespace std;

int main() {
    int l,r;
    cin >> l >> r;
    if(l==0 && r==0) {
        cout << "Not a moose" << endl;
    }
    else if(l == r) {
        cout << "Even " << l*2 << endl;
    } else {
        cout << "Odd ";
        if(l>r) {
            cout << l*2 << endl;
        } else {
            cout << r*2 << endl;
        }
    }
}