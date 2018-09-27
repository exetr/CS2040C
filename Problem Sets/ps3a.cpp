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
        int position;
        int size;
        vector<Patient> v;

    public:
        Hospital() {
            position = 0;
            size = 0;
        }

        /* void ordering(const Patient &a, const Patient &b) {
            if (a.dilation == b.dilation) {
                return 
            }
        } */

        void arriveAtHospital(string name, int dilation) {
            Patient p = {dilation, ++position, name};
            v.push_back(p);
            size++;
            if(size>1) {
                sort(v.begin(),v.end());
            }
        }

        void updateDilation(string name, int incDilation) {
            for(int i = 0; i<size; i++) {
                if(v[i].name == name) {
                    v[i].dilation += incDilation;
                }
            }
            if(size>1) {
                sort(v.begin(), v.end());
            }
        }

        void giveBirth(string name) {
            for(int i = 0; i<size; i++) {
                if(v[i].name == name) {
                    v.erase(v.begin()+i);
                    size--;
                }
            }
            if(size>1) {
                sort(v.begin(), v.end());
            }
        }

        string query() {
            if(size == 0) {
                return "The delivery suite is empty";
            } else {
                return v[size-1].name;
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
                cin >> name >> dilation;
                h.updateDilation(name,dilation);
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