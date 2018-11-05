#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<string> s;
    int N;
    cin >> N;
    for(int i = 0; i<N; i++) {
        string name;
        int height;
        cin >> name >> height;
        s.push(name);
        cout << "RAR" << endl;
    }
    s.push("RAR");

    int spaceCounter = 0;
    while(!s.empty()) {
        cout << s.top();
        s.pop();
        if(spaceCounter < N) {
            cout << " ";
            spaceCounter++;
        }   
    }
    cout << endl;
    return 0;
}