#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("in1b.txt", "r", stdin);

    vector<int> v;
    v.push_back(0);
    v.push_back(1000000);

    string line;
    getline(cin, line);
    istringstream iss1(line);
    int N;
    while(iss1 >> N) {
        v.push_back(N);
    }
    sort(v.begin(), v.end());

    int Q;
    getline(cin, line);
    istringstream iss2(line);
    while(iss2 >> Q) {
        if(Q<0) {
            v.push_back(Q*-1);
        } else if(Q>0) {
            sort(v.begin(), v.end());
            int min = 0;
            int max = 1000000;
            for(auto it = v.begin(); it!=v.end(); it++) {
                if(*it > min && *it < Q) { min = *it;}
                if(*it < max && *it > Q) { max = *it;}
            }
            cout << max-min << endl;
        }
    }
}