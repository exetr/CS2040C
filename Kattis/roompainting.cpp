#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> sizes;
    sizes.insert(1000000000);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i<n; i++) {
        int x;
        cin >> x;
        sizes.insert(x);
    }

    long long waste = 0;
    for(int i = 0; i<m; i++) {
        int x;
        cin >> x;
        auto it = sizes.lower_bound(x);
        waste += *it - x;
    }
    cout << waste << endl;
}