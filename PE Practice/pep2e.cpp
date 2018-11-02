#include <bits/stdc++.h>
using namespace std;

void printSet(set<string> &s) {
    for(auto it = s.begin(); it != s.end(); it++) {
        cout << *it << "-";
    }
    cout << endl;
}

int main() {
    //freopen("in2c.txt", "r", stdin);
    map<string, set<string> > flights;

    int F;
    cin >> F;
    for(int i = 0; i<F; i++) {
        string origin, destination;
        cin >> origin >> destination;
        flights[origin].insert(destination);
        flights[destination].insert(origin);
    }

    set<string> results;
    set<string> leg1 = flights["SINGAPORE"];
    //printSet(leg1);
    for(auto it = leg1.begin(); it != leg1.end(); it++) {
        results.insert(*it);
        set<string> leg2 = flights[*it];
        results.insert(leg2.begin(), leg2.end());
    }

    for(auto it = results.begin(); it != results.end(); it++) {
        if(*it != "SINGAPORE") {
            cout << *it << endl;
        }
    }
}