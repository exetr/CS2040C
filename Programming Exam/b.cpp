#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    int N;
    cin >> N;
    for(int i = 0; i<N; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    for(auto it = s.begin(); it != s.end(); it++) {
        cout << "1 " << *it << endl;
    }
    return 0;
}