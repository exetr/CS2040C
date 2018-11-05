#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, deque<string> > m;
    m[0].push_front("RAR");
    int N;
    cin >> N;
    for(int i = 0; i<N; i++) {
        string name;
        int height;
        cin >> name >> height;
        m[height].push_front(name);
        auto it = m.lower_bound(height);
        it--;
        cout << (it->second).back() << endl;
    }

    int spaceCounter = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        //deque<string> curr = it->second;
        while(!(it->second).empty()) {
            cout << (it->second).front();
            (it->second).pop_front();
            if(spaceCounter < N) {
                cout << " ";
                spaceCounter++;
            }
        }
    }
    cout << endl;
    return 0;
}