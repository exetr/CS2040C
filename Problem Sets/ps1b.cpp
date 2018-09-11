#include <bits/stdc++.h>

using namespace std;

void median(double arr[], int n) {

    //queue to store smaller half elements
    priority_queue<double> s;

    //queue to store greater half elements
    priority_queue<double, vector<double>, greater<double> > g;

    //declare first element as current median
    double med = arr[0];
    unsigned long long int result = med;
    
    //push first element of array into queue s
    s.push(arr[0]);

    //iterate through remaining elements within array
    for (int i = 1; i < n; i++) {

        //set current value as next element in array
        double x = arr[i];

        //case1: queue s has more elements
        if(s.size() > g.size()) {
            if(x < med) {
                g.push(s.top());
                s.pop();
                s.push(x);
            } else {
                g.push(x);
            }
            //find average of top of s and g queue
            med = (s.top() + g.top())/2.0;
        }

        //case2: both queues are equal in size
        else if(s.size() == g.size()) {
            if (x < med) {
                s.push(x);
                //median is top of queue s
                //result += (int)s.top();
                med = (double)s.top();
            } else {
                g.push(x);
                //median is top of queue g
                //med = (int)g.top();
                med = (double)g.top();
            }
        }

        //case3: queue g has more elements
        else {
            if (x > med) {
                s.push(g.top());
                g.pop();
                g.push(x);
            } else {
                s.push(x);
            }
            //find average of top of s and g queue
            med = (s.top() + g.top())/2.0;
        }

        //sum with current running median
        result += (unsigned long long int)med;
    }

    //print result
    printf("%llu\n", result);
}

int main() {

    // get number of test cases
    unsigned int tc;
    cin >> tc;

    //iterate through test cases
    for(int i=1; i<=tc; i++) {
        
        //get size of array
        unsigned int n;
        cin >> n;
        
        //get and process elements of array
        unsigned long long int input;
        double* array = new double[n];
        
        //read values from stdin and add to array
        for(int i=0; i<n; i++) {
            cin >> input;
            array[i] = (double) input;
        }

        //get running median of array
        median(array, n);

        //delete memory allocated for array
        delete [] array;
        array = NULL;

    }
	
	return 0;
}