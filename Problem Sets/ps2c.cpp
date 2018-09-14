#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int tc;
    cin >> tc;
    cin.ignore(100, '\n');

    for (int i=0; i<tc; i++) {
        char c;
        int size = 0;
        list<char> output;
        list<char>::iterator it = output.begin();
        
        for(c=getchar(); c != '\n'; ) {
            if (c == '<') {
                if(size == 0) {
                    ; //do nothing
                } else if (it == output.begin()) {
                    ; //do nothing
                }
                else {
                    //it--;
                    it = output.erase(--it);
                    size--;
                }
            } else if (c == '[') {
                it = output.begin();
            } else if (c == ']') {
                it = output.end();
            } else {
                output.insert(it, c);
                size++;
            }
            c=getchar();
        }

        //print list
        for(it=output.begin(); it != output.end(); it++) {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}