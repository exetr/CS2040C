#include <bits/stdc++.h>
using namespace std;

int main() {
    while(true) {
        int N, M;
        cin >> N >> M;
        if(N==0 && M==0) {
            break;
        }
        vector<int> jack;
        vector<int> jill;

        for(int i = 0; i<N; i++) {
            int CD;
            cin >> CD;
            jack.push_back(CD);
        }
        for(int i = 0; i<M; i++) {
            int CD;
            cin >> CD;
            jill.push_back(CD);
        }

        int it1 = 0;
        int it2 = 0;
        int result = 0;
        while(it1 < jack.size() && it2 < jill.size()) {
            if(jack[it1] == jill[it2]) {
                result++;
                it1++;
                it2++;
            } else if(jack[it1] < jill[it2]) {
                it1++;
            } else if(jack[it1] > jill[it2]) {
                it2++;
            }
        }
        cout << result << endl;
    }
    return 0;
}