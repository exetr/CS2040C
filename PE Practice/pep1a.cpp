#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    map<int, int> m;
    int N;
    cin >> N;
    for(int i = 0; i<N; i++) {
        int x;
        cin >> x;
        m[x] += 1;
    }
    int Q;
    cin >> Q;
    for(int i = 0; i<Q; i++) {
        int V;
        cin >> V;
        if(V>0) {
            m[V] += 1;
        } else if(V<0) {
            V = V * -1;
            if(m[V] > 0) {
                m[V] -= 1;
            }
            if(m[V] == 0) {
                m.erase(V);
            }
        } else {
            auto it1 = m.rbegin();
            auto it2 = m.begin();
            int ans = it1->first - it2->first;
            cout << ans << endl;
        }
    }
}