#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in2c.txt", "r", stdin);
    map<string, set<string>> flights;
    
    int F;
    cin >> F;
    for(int i = 0; i<F; i++) {
        string origin, destination;
        cin >> origin >> destination;
        flights[origin].insert(destination);
        flights[destination].insert(origin);
    }

    string origin = "SINGAPORE";
    set<string> results = flights[origin];
    for(auto it = results.begin(); it != results.end(); it++) {
        if(*it != origin) {
            cout << *it << endl;
        }
    }
}