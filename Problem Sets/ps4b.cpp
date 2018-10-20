// write your matric number here: A0174217H
// write your name here: teo chuan kai
// write list of collaborators here: -
// year 2018/19 Sem1 hash code: IEXVAR3BOJ4VIYLO (do NOT delete this line)

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

map<char, set<string> > male;
map<char, set<string> > female;

void addSuggestion(string babyName, int genderSuitability) {
    if(genderSuitability == 1) {
        male[babyName[0]].insert(babyName);
    } else if(genderSuitability == 2) {
        female[babyName[0]].insert(babyName);
    }
}

void removeSuggestion(string babyName) {
    male[babyName[0]].erase(babyName);
    female[babyName[0]].erase(babyName);
}

int setSize(set<string> &names) {
    return names.size();
}

int setDistance(string START, string END, set<string> &names) {
    return distance(names.lower_bound(START), names.lower_bound(END));
}

int query(string START, string END, int gender) {
    int ans = 0;
    char cS = START[0];
    char cE = END[0];
    switch(gender) {
        case 0:
            //find distance from with lower_bound for 
            //maps with first letter of START and END
            //-- male
            ans += setDistance(START, END, male[cS]);
            if(cS != cE) {
                ans += setDistance(START, END, male[cE]);
            }
            //-- female
            ans += setDistance(START, END, female[cS]);
            if(cS != cE) {
                ans += setDistance(START, END, female[cE]);
            }
            
            //find entire size of map with first letter that
            //falls in between START and END
            //-- male
            for(char cC = cS+1; cC < cE; cC++) {
                ans += setSize(male[cC]);
            }
            //-- female
            for(char cC = cS+1; cC < cE; cC++) {
                ans += setSize(female[cC]);
            }
            break;

        case 1:
            //find distance from with lower_bound for 
            //maps with first letter of START and END
            ans += setDistance(START, END, male[cS]);
            if(cS != cE) {
                ans += setDistance(START, END, male[cE]);
            }
            //find entire size of map with first letter that
            //falls in between START and END
            for(char cC = cS+1; cC < cE; cC++) {
                ans += setSize(male[cC]);
            }
            break;

        case 2:
            //find distance from with lower_bound for 
            //maps with first letter of START and END
            ans += setDistance(START, END, female[cS]);
            if(cS != cE) {
                ans += setDistance(START, END, female[cE]);
            }
            //find entire size of map with first letter that
            //falls in between START and END
            for(char cC = cS+1; cC < cE; cC++) {
                ans += setSize(female[cC]);
            }
            break;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("in.txt", "r", stdin);
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