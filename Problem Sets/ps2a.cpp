#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int tc;
    cin >> tc;
    cin.ignore(100, '\n');

    for (int i = 0; i<tc; i++) {
        char c;
        int counter = 0;
        int x = 0;
        char output[1001];

        for (c=getchar(); c != '\n'; counter++) {
            if (c == ']') {
                ; //do nothing
            } else if (c == '<') {
                if(x == 0) {
                    ; //do nothing
                } else {
                    x--;
                }
            } else {
                output[x] = c;
                x++;
            }
            
            c = getchar();
        }
        
        //print output
        output[x] = '\0';
        printf("%s\n", output);
    }
    return 0;
}

