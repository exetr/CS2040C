// write your matric number here: A0174217H
// write your name here: teo chuan kai
// write list of collaborators here: -
// year 2018/19 Sem1 hash code: IEXVAR3BOJ4VIYLO (do NOT delete this line)

#include <bits/stdc++.h>
using namespace std;

set<string> male;
set<string> female;

void addSuggestion(string babyName, int genderSuitability) {
    if(genderSuitability == 1) {
        male.insert(babyName);
    } else if(genderSuitability == 2) {
        female.insert(babyName);
    }
}

void removeSuggestion(string babyName) {
    male.erase(babyName);
    female.erase(babyName);
}

int query(string START, string END, int gender) {
    int ans = 0;
    if(gender == 0) {
        ans += distance(male.lower_bound(START), male.lower_bound(END));
        ans += distance(female.lower_bound(START), female.lower_bound(END));
    } else if(gender == 1) {
        ans += distance(male.lower_bound(START), male.lower_bound(END));
    } else if(gender == 2) {
        ans += distance(female.lower_bound(START), female.lower_bound(END));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cmd, genderSuitability;
    string babyName, START, END;
    while(true) {
        cin >> cmd;
        if(cmd == 0) {
            break;
        } else if(cmd == 1) {
            cin >> babyName >> genderSuitability;
            addSuggestion(babyName, genderSuitability);
        } else if(cmd == 2) {
            cin >> babyName;
            removeSuggestion(babyName);
        } else if(cmd == 3) {
            cin >> START >> END >> genderSuitability;
            cout << query(START, END, genderSuitability) << endl;
        }
    }
    return 0;
}