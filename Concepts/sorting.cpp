/* @exetr
CS2040C AY2018/19 S1
Sorting Algorithms */

#include <bits/stdc++.h>
using namespace std;

string printArray(int array[], int n) {
    stringstream ss;
    for (int i = 0; i<n; i++) {
        ss << array[i] << " ";
    }
    string output = ss.str();
    return output;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* 
Optimised Bubble Sort
Worst-case Time Complexity = O(n^2)
Best-case Time Complexity = O(n)
 */
void bubbleSort(int A[], int n) {
    for (int i = 0; i<n; i++) {             //pass
        bool swapped = false;
        for (int j = 0; j<n-i-1; j++) {     //comparison
            if (A[j] > A[j+1]) {            //swap
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {break;}
    }
}

/* 
Selection Sort
Time Complexity = O(n^2)
 */
void selectionSort(int A[], int n) {
    for (int i = 0; i<n; i++) {
        int min_index = i;
        for (int j = i+1; j<n; j++) {
            if(A[j] < A[min_index]) {min_index = j; }
        }
        int temp = A[min_index];
        A[min_index] = A[i];
        A[i] = temp;
    }
}

/* 
Insertion Sort
Worst-case Time Complexity = O(n^2)
Best-case Time Complexity = O(n)
 */
void insertionSort(int A[], int n) {
    for (int i = 1; i<n; i++) {
        int key = A[i];
        int j;
        for (j=i-1; j>=0 && A[j] > key; --j) {
            A[j+1] = A[j];
        }
        A[j+1] = key;
    }
}

/* 
Merge Sort
Time Complexity = O(n log n)
 */
void mergeSort(int A[], int low, int high) {
    if(low < high) {                //when low>=high, array is size 1
        int mid = (low+high)/2;     //split array into half
        mergeSort(A, low, mid);     //sort first half
        mergeSort(A, mid+1, high);  //sort second half
        merge(a, low, mid, high);   //merge back pair of sorted array
    }
}

void merge(int A[], int low, int mid, int high) {
    int n = high - low + 1;     //find size
    int* temp = new int[n];     //temp array with variable size
    int left = low;             //set left position to start of one array
    int right = mid+1;          //set right position to start of other array
    int counter = 0;

    while(left<=mid && right<=high) {
        if (a[left] <= a[right]) {
            temp[counter++] = a[left++]; 
        } else {
            temp[counter++] = a[right++]; 
        }
    }
    while(left<=mid) {              //copy remaining elements
        b[counter++] = a[left++]; 
    };
    while(right<=high) {
        b[counter++] = b[right++]; 
    };   
    for (int x = 0; x<n; ++x) {     //copy result back
        A[low+x] = temp[x]; 
    };   
    delete [] temp;
}

/* 
Quicksort
Worst-case Time Complexity = O(n^2)
Best-case Time Complexity = O(n log n)  
 */
void quicksort(int A[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(A, low, high);
        quicksort(A, low, pivotIndex-1);
        quicksort(A, pivotIndex+1, high);
    }
}

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    for (int x = i+1; x<high; ++x) {
        if (A[x] < pivot) {
            swap(A, i, x);
        }
    }
    swap(A, low, i);
    return i; 
}

/* 
Radix Sort 
Time Complexity = O(nk), where k = number of digits in largest element
 */
void radixSort() {
    //todo
}

/* 
Counting Sort 
Time Complexity = O(n + k), where k = number of distinct elements
 */
void countingSort() {
    int A[20] = {2,3,8,7,1,2,2,2,7,3,9,8,2,1,4,2,4,6,9,2};
    int n = sizeof(A)/sizeof(A[0]);
    int keyArray[10] = {0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i<n; i++) {
        keyArray[A[i]] += 1;
    }
    for (int i = 0; i<10; i++) {
        while(keyArray[i] != 0) {
            cout << i << " ";
            keyArray[i] -= 1;
        }
    }
}

int main() {
    return 0;
}