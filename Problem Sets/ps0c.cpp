#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    while(true){
        //get entire line of input
        string input;
        getline(cin,input);
        //check for loop exit condition
        if(input=="0 0"){
            break;
        }else{
            //declare variables
            unsigned long long int x;
            unsigned long long int sum = 0;
            int counter = 0;
            istringstream iss(input);           
            //iterate through input string for integer
            while(iss >> x){
                if(counter<10){
                    sum += x;
                    counter += 1;
                }else{
                    break;
                }
            }
            cout << sum << endl;
        }   
    }
}