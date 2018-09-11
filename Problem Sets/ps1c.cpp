#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unsigned int tc;
    cin >> tc;

    unsigned int n;
    cin >> n;

    unsigned long long int input;
    unsigned long long int result = 0;
    int medianVal;

    int count1 = 0;
    int count3 = 0;
    int count5 = 0;

    for (int i=1; i<=n; i++) {
        cin >> input;

        //determine which number in stdin
        if (input == 1) {
            count1++;
        } else if (input == 3) {
            count3++;
        } else if (input == 5) {
            count5++;
        }

        //for first value input
        if (i == 1) {
            if (count1 == 1) {
                result += 1;
                medianVal = 1;
            } else if (count3 == 1) {
                result += 3;
                medianVal = 3;
            } else if (count5 == 1) {
                result += 5;
                medianVal = 5;
            }
        } 

        //if number of elements is odd
        else if (i%2 == 1) {
            int medPos = (i+1)/2;

            //check if median is 1
            medPos -= count1;
            if (medPos <= 0) {
                result += 1;
                medianVal = 1;
            } 
            //check if median is 3
            else {
                medPos -= count3;
                if (medPos <= 0) {
                    result += 3;
                    medianVal = 3;
                } 
                //check if median is 5
                else {
                    //medPos -= count5;
                    if (medPos >= 0) {
                        result += 5;
                        medianVal = 5;
                    }
                }
            }
        } 

        //if number of elements is even
        else if (i%2 == 0) {
            //catch confirmed cases (number of elements > half of total number of elements)
            if (count1 > i/2) {
                result += 1;
                medianVal = 1;
            } else if (count3 > i/2) {
                result += 3;
                medianVal = 3;
            } else if (count5 > i/2) {
                result += 5;
                medianVal = 5;
            } 
            //remaining cases
            else {
                int lowMP = i/2;
                int highMP = lowMP + 1;
                lowMP -= count1;

                if (lowMP == 0) {
                    //lowMedian = 1;
                    if (count3 == 0) {
                        //highMedian = 5 (median is 3)
                        result += 3;
                        medianVal = 3;
                    } else if (count3 != 0) {
                        //highMedian = 3 (median is 2)
                        result += 2;
                        medianVal = 2;
                    }
                } 
                else if (lowMP > 0) {
                    lowMP -= count3;
                    if(lowMP == 0) {
                        //lowMedian = 3;
                        if (count5 != 0) {
                            //highMedian = 5; (median is 4)
                            result += 4;
                            medianVal = 4;
                        }
                    } else if (lowMP > 0) {
                        result += 5;
                        medianVal = 5;
                    } else if (lowMP < 0) {
                        result += 3;
                        medianVal = 3;
                    }
                }
            }
        }
    }

    cout << result << endl;
    cout << "By submitting this source code, "
    "I declare that it is MY OWN implementation work. "
    "I fully understand the underlying algorithm behind "
    "the code that I wrote and can prove it to Lab TA if asked." << endl;
    return 0;
}