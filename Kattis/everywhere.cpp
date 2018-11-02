#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 0; i<T; i++) {
        set<string> cities;
        int n;
        cin >> n;
        for(int j = 0; j<n; j++) {
            string city;
            cin >> city;
            cities.insert(city);
        }
        cout << cities.size() << endl;
    }
}