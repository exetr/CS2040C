#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in2d.txt", "r", stdin);
    vector<int> result;

    int F;
    cin >> F;
    for(int i = 0; i<F; i++) {
        int origin, destination;
        cin >> origin >> destination;
        if(origin == 0 && destination != 0) {
            result.push_back(destination);
        }
        if(destination == 0 && origin != 0) {
            result.push_back(origin);
        }
    }

    sort(result.begin(), result.end());
    for(int i = 0; i<result.size(); i++) {
        cout << result[i] << endl;
    }
}