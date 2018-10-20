#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    set<string> s;
    unordered_set<string> us;

    while(cin >> x) {
        us.insert(x);
    }

    for(auto it1 = us.begin(); it1 != us.end(); ++it1) {
        for(auto it2 = us.begin(); it2 != us.end(); ++it2) {
            if(*it1 == *it2) {
                continue;
            } else {
                s.insert(*it1 + *it2);
                s.insert(*it2 + *it1);
            }
        }
    }

    for(auto it3 = s.begin(); it3 != s.end(); ++it3) {
        cout << *it3 << endl;
    }
}