#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i<N; i++) {
        set<int> guests;
        int G;
        cin >> G;
        for(int j = 0; j<G; j++) {
            int C;
            cin >> C;
            if(guests.find(C) == guests.end()) {
                guests.insert(C);
            } else {
                guests.erase(C);
            }
        }
        auto it = guests.begin();
        cout << "Case #" << i+1 << ": " << *it << endl;
    }
}