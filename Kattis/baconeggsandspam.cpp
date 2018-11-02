#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    while(true) {
        string line;
        map<string, set<string> > report;

        int n;
        cin >> n;
        if(n==0) { break; }
        getline(cin, line);
        
        for(int i = 0; i<n; i++) {
            string name, item;
            getline(cin, line);
            istringstream iss(line);
            iss >> name;
            while(iss >> item) {
                report[item].insert(name);
            }
        }

        for(auto& it : report) {
            cout << it.first << " ";
            set<string> names = it.second;
            for(auto& it2 : names) {
                cout << it2 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}