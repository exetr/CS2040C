#include <bits/stdc++.h>
using namespace std;

const int MAX_NQ = 300000;
const long long MAX_INT = 100000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("in1b.txt", "r", stdin);

    multiset<long long> s;
    s.insert(0);
    s.insert(MAX_INT);
    
    string line;
    getline(cin, line);
    istringstream iss1(line);
    long long N;
    while(iss1 >> N) {
        s.insert(N);
    }

    getline(cin, line);
    istringstream iss2(line);
    long long Q;
    while(iss2 >> Q) {
        if(Q<0) { s.insert(Q*-1);}
        else if(Q>0) {
            set<long long>::iterator max = s.upper_bound(Q);
            set<long long>::iterator min = max;
            min--;
            while(*min == Q) { min--;}
            cout << *max-*min << endl;
        }
    }
}