#include <bits/stdc++.h>
using namespace std;

struct Name {
    string name;
    bool operator<(const Name& a) const {
        if(name.size() == a.name.size()) { return name > a.name;} 
        else { return name.size() < a.name.size();}     
    }
};

int main() {
    freopen("in2a.txt", "r", stdin);
    set<string> input;
    priority_queue<Name> output;

    int N;
    cin >> N;
    for(int i = 0; i<N; i++) {
        string name;
        cin >> name;
        input.insert(name);
    }

    int M;
    cin >> M;
    for(int i = 0; i<M; i++) {
        string name;
        cin >> name;
        input.erase(name);
    }

    for(auto it1 = input.begin(); it1 != input.end(); it1++) {
        string first = *it1;
        string second;
        if(first[0] == 'J') {
            for(auto it2 = input.begin(); it2 != input.end(); it2++) {
                second = *it2;
                string result;
                if(second == first) { continue;}
                else {
                    result = first + " " + second;
                    output.push({result});
                }
            }
        } else { continue;}
    }

    while(!output.empty()) {
        Name n = output.top();
        cout << n.name << endl;
        output.pop();
    }
}