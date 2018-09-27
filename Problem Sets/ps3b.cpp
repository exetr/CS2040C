#include <bits/stdc++.h>
using namespace std;

class Hospital {
    struct Patient {
        int dilation;
        int id;
        string name;

        bool operator<(const Patient& a) const {
            if (dilation == a.dilation) {
                return id > a.id;
            } else {
                return dilation < a.dilation;
            }
        }
    };

    private:
        priority_queue<Patient> q;
        int position;

    public:
        Hospital() {
            position = 0;
        }

        void arriveAtHospital(string name, int dilation) {
            Patient p = {dilation, ++position ,name};
            q.push(p);
        }

        void giveBirth(string name) {
            q.pop();
        }

        string query() {
            if(q.empty()) {
                return "The delivery suite is empty";
            } else {
                Patient p = q.top();
                return p.name;
            }
        }
};

int main() {
    Hospital h;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        int cmd, dilation;
        string name;
        cin >> cmd;
        switch(cmd) {
            case 0:
                cin >> name >> dilation;
                h.arriveAtHospital(name,dilation);
                break;
            case 1:
                //not used
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