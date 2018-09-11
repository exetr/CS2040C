#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

unsigned long int median(unsigned long int array[], int size);

int main() {
    // get number of test cases
    unsigned int tc;
    cin >> tc;

    for(unsigned int i=1; i<=tc; i++) {
        //get size of array
        unsigned int n;
        cin >> n;
        //ignore next newline
        cin.ignore();
        
        //get elements of array
        string input;
        unsigned long int x;
        getline(cin,input);

        //declare relevant properties
        istringstream iss(input);
        unsigned long int array[500];
        int counter = 0;
        unsigned long int median_sum = 0;

        //iterate through input and add to array
        while (iss >> x) {
            array[counter] = x;
            counter += 1;
            //sort array in ascending order
            sort(array, array + counter);
            //get median of sorted array in current state
            unsigned long int median_val = median(array, counter);
            //add median to running sum of medians
            median_sum += median_val;
        }

        //print median sum
        cout << median_sum << endl;
    }
}

//function to calculate median of given array
unsigned long int median(unsigned long int array[], int size) {
    double median_value;
    if (size == 1) {
        median_value = array[0];
    } else if (size % 2 == 0) {
        median_value = (array[size/2] + array[(size/2)-1])/2;
    } else {
        median_value = array[size/2];
    }
    return (unsigned long int) floor(median_value);
}