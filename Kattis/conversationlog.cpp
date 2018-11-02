#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    unordered_map<string, int> words;
    unordered_map<string, unordered_set<string> > userMap;
    unordered_map<string, unordered_set<string> > wordMap;
    vector< pair<int, string> > results;
    
    int M;
    string line;
    cin >> M;
    getline(cin, line);
    for(int i = 0; i<M; i++) {
        string name, word;
        getline(cin, line);
        istringstream iss(line);
        iss >> name;
        while(iss >> word) {
            words[word] += 1;
            userMap[name].insert(word);
            wordMap[word].insert(name);
        }
    }
    int userCount = userMap.size();
    for(auto it = wordMap.begin(); it != wordMap.end(); it++) {
        if(it->second.size() == userCount) {
            results.push_back(make_pair(-words[it->first], it->first));
        }
    }
    sort(results.begin(), results.end());
    if(results.size() == 0) {
        cout << "ALL CLEAR" << endl;
    } else {
        for(auto& a : results) {
            cout << a.second << endl;
        }
    }
}