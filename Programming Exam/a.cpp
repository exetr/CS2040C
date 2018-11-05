#include <bits/stdc++.h>
using namespace std;

struct Val {
    int integer;
    int count;
    bool operator<(const Val& a) const {
        if(count == a.count) {
            return integer > a.integer;
        } else {
            return count < a.count;
        }
    }
};

int main() {
    map<int, int> m;
    priority_queue<Val> pq;

    int N;
    cin >> N;
    for(int i = 0; i<N; i++) {
        int x;
        cin >> x;
        m[x] += 1;
    }

    for(auto it = m.begin(); it != m.end(); it++) {
        int integer = it->first;
        int count = it->second;
        pq.push({integer, count});
    }

    while(!pq.empty()) {
        Val v = pq.top();
        cout << v.count << " " << v.integer << endl;
        pq.pop();
    }

    return 0;
}