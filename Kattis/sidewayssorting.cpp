#include <bits/stdc++.h>
using namespace std;

bool compare(string x, string y) {
    for(auto& c : x) {
        c = tolower(c);
    }
    for(auto& c : y) {
        c = tolower(c);
    }
    return x < y;
}

int main() {
    while(true) {
        int r, c;
        cin >> r >> c;
        if(r==0 && c==0) {
            break;
        }

        vector<string> words;
        words.resize(c, "");
        for(int x = 0; x<r; x++) {
            for(int y = 0; y<c; y++) {
                char c;
                cin >> c;
                words[y].push_back(c);
            }
        }
        stable_sort(words.begin(), words.end(), compare);

        for(int x = 0; x<r; x++) {
            for(int y = 0; y<c; y++) {
                char c = words[y][x];
                cout << c;
            }
            cout << endl;
        }
        cout << endl;
    }
}