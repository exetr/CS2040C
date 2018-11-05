#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    map<int, string> m;
    m[0] = "RAR";
    int N;
    cin >> N;
    for(int i = 0; i<N; i++) {
        string name;
        int height;
        cin >> name;
        cin >> height;
        m[height] = name;
        auto it1 = m.lower_bound(height);
        it1--;
        cout << it1->second << endl;
    }

    int spaceCounter = 0;
    for(auto it = m.begin(); it != m.end(); it++, spaceCounter++) {
        cout << it->second;
        if(spaceCounter < N) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}