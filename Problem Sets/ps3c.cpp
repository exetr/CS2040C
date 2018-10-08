#include <bits/stdc++.h>
//#include <iostream>
//#include <tuple>
//#include <string>
//#include <map>
using namespace std;

typedef tuple<int, int, string> Patient; //dilation, position, name

class Hospital{
    private:
        unordered_map<string, pair<int, int>> m; //name, dilation, position
        priority_queue<Patient> q;
        int position;

    public:
        Hospital() {
            position = -1;
        }

        void arriveAtHospital(string name, int dilation) {
            //insert into priority queue
            q.push(make_tuple(dilation, position, name));
            //insert into map
            m[name] = make_pair(dilation,position);
            position--;
        }

        void updateDilation(string name, int incDilation) {
            //increase value of dilation in map
            get<0>(m[name]) += incDilation;
            int pDilation = get<0>(m[name]);
            int pPosition = get<1>(m[name]);
            //push new entry into priority queue
            q.push(make_tuple(pDilation, pPosition, name));
        }

        void giveBirth(string name) {
            //delete entry in map
            m.erase(name);
            //patient still exists in priority queue
        }

        string query() {
            if(m.empty()) {
                return "The delivery suite is empty";
            } else {
                //if patient at top of q matches entry in p,
                //patient is valid and information is up to date,
                //else, information is out of data and pop from q
                int dilation = get<0>(q.top());
                string name = get<2>(q.top());
                bool valid = checkValid(dilation, name);
                while(valid == false) {
                    q.pop();
                    dilation = get<0>(q.top());
                    name = get<2>(q.top());
                    valid = checkValid(dilation, name);
                }
                return name;
            }
        }

        bool checkValid(int dilation, string name) {
            if(m.find(name) == m.end()) {
                return false;
            } else {
                if(get<0>(m[name]) != dilation) {
                    return false;
                } else {
                    return true;
                }
            }
        }
};

int main() {
    Hospital h;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int cmd, dilation;
        string name;
        cin >> cmd;
        switch(cmd) {
            case 0:
                cin >> name >> dilation;
                h.arriveAtHospital(name, dilation);
                break;
            case 1:
                cin >> name >> dilation;
                h.updateDilation(name, dilation);
                break;
            case 2:
                cin >> name;
                h.giveBirth(name);
                break;
            case 3:
                cout << h.query() << endl;
                break;
        }
    }
}